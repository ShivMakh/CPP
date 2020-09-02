/*
SM


Cash HW from CS 50-improved (not as repeatative as cash.cpp)
*/

#include <iostream> //input and output to the terminal
#include <limits> //std::numeric_limits<std::steamsize [used in user validation]
#include <string> //allows string arrays

int main()
{
    
    float change=0.00; //the amount of change to breakdown
    int coins=0; //counts the amount of coins needed
    int number_of_currency=0; //will count how many quarters, dimes, nickles, and pennies are needed individually


    //ask user for the amount of change to breakdown, with user validation
    do{
        std::cout << "How much change do you need to breakdown? ";
        std::cin >> change;

        //user validation, explaination in stairs.cpp 
        if (std::cin.fail()) { 
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "That is not a number I understand.\n";
          continue;
        }

        //telling user why input is invalid
        if(change==0)
        { 
            std::cout <<"There is no change to give, awesome!" << std::endl;
            return 0; //ends program, bc dont need to breakdown any change
        }
        if(change<0)
        {
            std::cout << "The negative amount of change...that doesnt make much sense." << std::endl;
        }
    } while (change==0 || change <=0); //condition to ask the user for input again

    //arrays for the coin name and the denominations
    std::string coin[] = {"Quarters", "Dimes", "Nickles", "Pennies"};
    float coin_values[] = {.25, .10, .05, .01};

    //for loop goes through the arrays above and looks at the 
    //change compared to the coin demonination and counts the coins accordingly
    for (int i =0; i<sizeof(coin)/sizeof(coin[0]); i++) //sizeof(coin)/sizeof(coin[0]) gets the length of the array
    {
        while (change>=coin_values[i])
        {
            change-=coin_values[i];
            coins++; 
            number_of_currency++;         
        }

        //machine rounding occasionally results in the numbers of pennies to be off...
        //this only happens if change =.01, with proper human rounding; this may happen once.
        if (change <=.01 && change >=.0094)  
        {
        coins++;
        change=0; //to make sure that change is 0 for having clean data
        number_of_currency++;
        }        


        std::cout << "The number of " << coin[i]  <<" is: " << number_of_currency  << std::endl;
        number_of_currency=0; //reset the number of the currency, reset to count for the next amount of coins
    }

    change =0; //sets change to 0, to make sure everything is clean
    std::cout <<"\nThe total number of coins needed is: " << coins <<std::endl; 
   
   
    return 0;
}



/*
challenges:
    the last penny rounding problem took a little bit of fiddling
next steps:
    improve user validation

notes:
    compared to cash.cpp, about same length,  but I think this is cleaner
    allows for changing the demoninations, has less variables, and less copy/pasted loops

*/
