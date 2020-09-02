/*
SM


Cash HW from CS50

*/

#include <iostream> //input and output to the terminal
#include <limits> //std::numeric_limits<std::steamsize
#include <string> //allows string arrays

int main()
{
    float change=0.00; //the change to breakdown
    int coins=0; //the amount of coins needed

    //will count the number of each type of coins
    int quarters=0; 
    int dimes=0;
    int nickles=0;
    int pennies=0;


    //ask user for the amount of change to break down, with user validation
    do{
        std::cout << "How much change do you need to breakdown? ";
        std::cin >> change;

        //user validation,explaination breakdown in stairs.cpp
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


    //While loops that go through the demoninations
    //they will count the number of coins and the number of each type
    while (change>=.25)
    {
        change-=.25;
        coins++;
        quarters++;
    }

    while (change>=.10)
    {
        change-=.10;
        coins++;
        dimes++;
    }

    while (change>=.05)
    {
        change-=.05;
        coins++;
        nickles++;
    }

    //for pennies but because of machine rounding, occasionally there is rounding errors.
    //only happens when change is .01 with proper rounding, can happen only once
    if (change>=.0094)  
    {
        change-=.01;
        coins++;
        pennies++;
    }


    //output into the terminal the results
    change=0; //to make sure that change is 0 for having clean data
    std::cout << "The number of quarters is: " << quarters << std::endl;
    std::cout << "The number of dimes is: " << dimes << std::endl;
    std::cout << "The number of nickles is: " << nickles << std::endl;    
    std::cout << "The number of pennies is: " << pennies << std::endl;

    std::cout <<"The total number of coins is: " << coins;    //main output asked in cash hw for CS50


    return 0;
}


/*
next challenges:
    improve user validation, maybe using parsing?

*/
