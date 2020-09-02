/*
SM

Readability HW from CS50
    assumptions: 
        You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z
        any sequence of characters separated by spaces should count as a word
        and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
*/

#include <iostream> //interaction with terminal
#include <cmath> //for rounding function


int main()
{

    std::string input_text;
    double L=0; // average number of letters per 100 words
    double W=0; //number of words in input text
    double S=0; //average number of sentences per 100 words 
    double grade; //determined by the formula


    //gets the text from user
    std::cout << "Text: ";
    std::getline (std::cin, input_text);

    for(char const &c: input_text) //will loop through the string input_text char by char
    {
        int ascii_num = c;
        if (c==' ')  //space indicates a new word
        {
            W++;
        }
        else if (ascii_num >64 && ascii_num<91 ) //lower case letters
        {
            L++;
        }
        else if (ascii_num>96 && ascii_num<123) //upper case letters
        {
            L++;
        }        
        else if(ascii_num == 33||ascii_num ==46 || ascii_num ==63) //indicates end of sentence
        {
            S++;
        }
        
    }

    std::cout <<"\n";



    //W+1 because the last word of the user input_text does not have a space that follows it


    //to get average letter per words is L/words, to get per 100 words its L/(words/100)=(100*L)/words;
     L=(100*L/(W+1));
    
    //to get average sentences per 100 words: same as L
    //S=(100*S)/(W);
    S=(100*S/(W+1));

    grade =  0.0588 * L - 0.296 * S - 15.8;


    //outputs the grade determined the formula
    if (grade > 16)
    {
        std::cout << "Grade: Grade 16+";
    }
    else if (grade < 1)
    {
        std::cout << "Grade: Before grade 1";
    }
    else
    {
        std:: cout << "Grade:" << std::round(grade);
    }


    return 0;
}
