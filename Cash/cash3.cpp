/*
SM


Cash HW from CS 50-improved (not as repeatative as cash2.cpp)
*/

#include <iostream> //allows terminal interaction
#include <limits> //std::numeric_limits<std::steamsize [used in user validation]
#include <string> //allows string arrays

//allows for a 2d array with different types, this structure type is called coins
typedef struct 
{
    std::string name;
    double value;
}
coins;

int main()
{
    //fill in the 2d array which connects coin name and value together
    coins coin[4];
    
    coin[0].name = "Quarters";
    coin[0].value = .25;

    coin[1].name = "Dimes";
    coin[1].value = .10;

    coin[2].name = "Nickles";
    coin[2].value = .05;

    coin[3].name = "Pennies";
    coin[3].value = .01;




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

    //loops through the 2d array 
    for (int i = 0; i < (sizeof(coin)/ sizeof(coin[0])); i++)
    {
        while (change >= coin[i].value)
        {
            change -=coin[i].value;
            coins++;
            number_of_currency++;
        }

        //machine rounding occasionally results in the numbers of pennies to be off...
        //this only happens if change =.01, with proper human rounding; this may happen once.
        if (change <=.01 && change >=0.0094)  
        {
        coins++;
        change=0; //to make sure that change is 0 for having clean data
        number_of_currency++;
        }
        
        std::cout << "The number of " << coin[i].name  <<" is: " << number_of_currency  << std::endl;
        number_of_currency=0; //reset the number of the currency, reset to count for the next amount of coins
    }

    change =0; //sets change to 0, to make sure everything is clean
    std::cout <<"\nThe total number of coins needed is: " << coins <<std::endl; 

}


/*
notes:
    this program is better because the coin name and value are linked together, in cash2.cpp,
    bc in cash2.cpp it is assumed that the coin value and the name are always going to be in the same order
    using a structure, means that 'quarters' and .25 is always linked together. 
    this program runs seems to run faster than the cash.cpp and cash2.cpp

next steps:
    it doesnt make sense in this specific problem, but it is possible for fantasy game currency to have a simliar breakdown
    here it would make sense to allow user to input fantasy currency details

    actually compare run times between all of the cash programs

*/
