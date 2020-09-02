/*
SM

CS50 Credit HW: use Luhns to validate credit card numbers

    *assumption is that entirely numeric entry

*/

#include <iostream> //allows interaction with terminal
#include <algorithm> //allows use for numeric_limits and max for user validation
#include <cmath> //allows use of log10 and power functions


//pre declaration of functions that is defined after the main program
int card_type(long long int card_number, int card_length);
int Luhns(long long int card_number, int card_length);


int main()
{
    //declare variables 
    long long int card_number=0;
    int card_length=0;


    //get card_number from user with input validation
    do
    {
        std::cout << "Number: ";
        std::cin >> card_number;

        //if look is user validation, explaination is in stairs.cpp
        if (std::cin.fail()) 
        { 
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "That is not a number I understand.\n";
          continue;
        }

        card_length= 1 + log10(card_number); //explaination of how this works at end of program

        //explains invalid input 
        if ((card_length!=13) && (card_length!=15) && (card_length !=16))
        {
            std::cout << "Invalid Card Number length" << std::endl;
        }
    } while ((card_length!=13) && (card_length!=15) && (card_length !=16)); //condition to ask the user for input again


    Luhns(card_number, card_length); //calls Luhns Function to see if card number is valid
    return 0;
}


int Luhns(long long int card_number, int card_length)
{
    std::cout << "\n";
    
    long long int card_n = card_number; //for CC Number manipulation without corrupting input data
    
    //puts the digits of the card_number into an array to identify each of digits that need to go through Luhns Algorithm
    int array[card_length-1]; 
    //sends the card_n  into the array
    for (int i=card_length-1; i >=0; i--)
    {
        array[i]= card_n%10;
        card_n /=10;
    } 
    


    int sum=0; //sum for luhns

    //Step 1 of Luhns: Multiple every other digit by 2 and find sum
    //if the card_length is even or odd effects the array location so first step is seperate card_length by even or odd
    if ((card_length)%2==0) //card number length is even
    {
        //loops throught the array
        for (int i = card_length-1; i >= 0 ; i--)
        {
            //even number locations in array, the digits here are multiplied by 2 first then the digits are added to the sum
            if (i%2==0)
            {   
                sum=sum+((array[i]*2)%10); //gets the ones digit
                sum=sum+((array[i]*2)/10); //gets the tens digit   
            }
            else //odd array locations are just added to the sum
            {
                sum=sum+array[i];
            }
        } 
    }

    //same concept but for card_number length that are odd
    if ((card_length)%2!=0) //card number length is odd
    {
        for (int i = card_length-1; i >= 0 ; i--)
        {
            if (i%2!=0)
            {   
                sum=sum+((array[i]*2)%10); //gets the ones digit
                sum=sum+((array[i]*2)/10); //gets the tens digit   
            }
            else
            {
                sum=sum+array[i];
            }
        } 
    }


    //last step of Luhns is is the sum ends in a 0, so use %, if the remainder is 0, then sum is a multiple of 10.
    //this means that the cc is a valid number so we can look to see what card type is given
    if (sum%10==0)
    {
        card_type(card_number, card_length); 
    }
    else
    {
        std::cout << "Invalid";
        return 1;
    }
    
    return 0;    
}


int card_type(long long int card_number, int card_length)
{
    //gets the first two digits that of the card number
    int first_two_digits = (card_number/pow(10,(card_length-2)));
    int found=0; //if the luhns sum is valid, it doesnt mean that the number is within the paramters of the hw

    //Visa: 13, 16 digit, start with 4
    if ((int (card_number/pow(10,(card_length-1)))==4) && (card_length==16|| card_length==13))
    {
        std::cout << "Visa";
        found=1;
        return 0;
    }

    //American Express: 15 digit, start with 34 or 37
    if ((first_two_digits==34 || first_two_digits==37 )&& card_length==15)
    {
        std::cout << "American Express";
        found=1;
        return 0;
    }

    //Master: 16 digit, start with 51,52,53,54,55
    if ((first_two_digits<=55) && (first_two_digits >=51)  && card_length==16)
    {
        std::cout << "Master Card";
        found=1;
        return 0;
    }

    //if a valid card type was found, found=1, so if found doesnt equal 1, then a valid card type is not given by the user
    if (found != 1)
    {
        std::cout << "Invalid Card Type";
        return 1;
    }


    return 0;
}



/*
notes:
    log10(number) can tell you how many digits there are bc
        log10(1000)=3 > 10^3=1000 so the number of digits is log10(1000)+1 gets the number of digit
        log10(1001)=3.00043408 > if we set this to an int then int log10(1001)=3 and add one to get the number of digits
    


challenges, need to be solved:
    input: 4003-6000-0000-001
    output:
        Number: 4003-6000-0000-001
        Invalid Card Number length        
        Number: Invalid Card Number length
        Number: Invalid Card Number length
        Number: Invalid Card Number length
        Number: [allows for next input]

next steps:

the even and odd length effects the way to do Luhns
my code right now handles it by having the exact same code one with even number and other with odd numbers
this can be done better
*/
