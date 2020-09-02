/*
SM

Caesar Problem Set from CS50
    create a cipher text

*/

#include <iostream> //input and output into the termainl
#include <algorithm> //max and min (used for data validation)
#include <limits> //std::numeric_limits<std::steamsize (used for data validation)



//other functions called here to introduce it for the compiler
int cipher(const std::string& input, int key);
int key_set();


//main function, gets basic starting information to pass into other functions and finishes the program output
int main()
{
    //declare variables needed to pass into other functions
	std::string plain_text; 
    int key;


    std::cout <<"What is the plain text: ";
    std::getline(std::cin, plain_text); //this allows user input a string (including multiple words with spaces)

    key = key_set();//calls key_set function and sets the return value to the 
                    //variable key takes the returned function 

    if (key == 0)
    {
        return 1; //since key=0, there is no encryption, so it is not nessecary to go through cipher
    }
    
    //main output into the terminal
    std::cout << "Plain text:  " << plain_text <<std::endl;
    std::cout << "Cipher Text: " << cipher(plain_text, key); //calls cipher function explaination at end of program
	
    return 0;
}



//asks user for the key value wtih some user validation
int key_set()
{
	int key;

    //user validation to make sure that int key is a positive int != 0
    do
    {
		std::cout <<"How much of a shift do you want? ";
		std::cin >> key;
		key=key%26; //makes sure that the key shift isnt more than 26.
        //if look is user validation, see comments at end of program for details
        if (std::cin.fail()) { 
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "That is not a number I understand.\n\n";
          continue;
        }

        //telling user why input is invalid
        if(key==0){ 
            std::cout <<"The key value is 0, so that encrypted text is the same as the plain text provided.\n\n";
            return 0; //returns 0 into main() 
        }
    } while (key==0); //condition to ask the user for input again

    //making sure that key is a postive intger
    if(key < 0) 
    {
        key*=(-1);
    }

    return key; //Return the value to key to main
}


int cipher(const std::string& input, int key)
{
	int ascii_num;
    char letter;
    	
    for (char const &c: input)
        {

            ascii_num=c; //gets the ascii number of the character passed into the program by the user

            if (ascii_num >64 && ascii_num<91) //checks if character is a capital letter
            {
                //set up explained below at end of comments
                if ((c+key)>=91) //new letter is beyond Z, so needs to loop back around to A
                {
                    ascii_num=c+key-26;
                }
                else 
                {
                    ascii_num=c+key; 
                }
            }
            
            //set up explained below at end of comments
            else if (ascii_num>96 && ascii_num<123) //checks if character letter is lowercase
            {
                if ((c+key)>=123) //new letter is beyond z, so needs to loop back around to a
                {
                    ascii_num=(c+key)-26; 
                }
                else
                {
                    ascii_num=c+key;
                }
            }  


            letter=ascii_num; //sets the letter to the new ascii key
            std::cout << letter; //prints out the new letter
        }
     

    std::cout << "\n";

	return 0;
}
    /*
    explaination of cipher:
        every character has a ascii number associated with them
        the cipher is essentially reassigning the ascii number by shifting the ascii number by the given key

        Key items to make sure that it happend: 
            only want to rewrite the alphebet characters not the spaces or special characters
            IE the first set of the program is to issolate the characters that are in A-Z and a-z
        
        this brings up the next step. we need the letters to loop back to the begining of the alphabeth
            the ascii numbers are in this order: abcd...wyxz{|}~
            want to have this order            : abcd...wyxzabcd
                    So if key=1 want z to become a (the same loop with capital letters also)

        
        the only ascii numbers that need to be re-assigned is the plain text characters that are a-z and A-Z
        aka the ascii numbers (97-122) and (65-91)
        if the new encrypted/new ascii letter is beyond z or Z take away 26 so that the letters loop around
        so that z goes back to a and Z to A


        so after we find the letters, then we need to see if the new encrypted ascii number is the {|}~
        we want to make sure that the ascii is looped back around to the letter a
            this is done by -26 to the new ascii number if the new ascii number is too high
        if there is an ascii number that isnt a-z or A-Z then the ascii number isnt rewriten in the loops


        simple example:
        key=2
        plain text: {z y} {a b}
        expected:   {b a} {c d}
        without the -26 output:{| {} {c d}


    */




/*
next steps:
    out put works as expected /but/ there is an extra 0 that is output into the terminal
    using the debugger i cannot tell where the 0 is coming from
*/
