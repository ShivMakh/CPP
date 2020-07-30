//SM CS50 Mario Problem Variation
//

//Headers
#include <iostream> //std::cout, std::cin, 
#include <algorithm> //max and min
#include <limits> //std::numeric_limits<std::steamsize


int main(){
    std::cout <<"Welcome!\n";

//
//PART 1: USER INPUTS AND VALIDATION
//

    //var declarations for user inputs
    int steps,maxim, minim, true_min;

    //ask for the maximum height, allows for any number not 0
    do{
        std::cout << "What is the max height possible of the stairs?\n";
        std::cin >> maxim;
        //if look is user validation, see comments at end of program for details
        if (std::cin.fail()) { 
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "That is not a number I understand.\n";
          continue;
        }

        //telling user why input is invalid
        if(maxim==0){ 
            std::cout <<"0 for the maximum doesnt make much sense...\n";
        }
    } while (maxim==0); //condition to ask the user for input again
    std::cout <<"Alright, lets move forward.\n\n";

    //asking for minimum height, allows for any number less than maxim and not 0
    do{
        std::cout << "What is the min height?\n";
        std::cin >> minim;
        true_min =std::min(minim, maxim);
        //user validation
        if (std::cin.fail()) { 
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
          std::cout << "That is not a number I understand.\n";
          continue;
        }
        //informing user reason for invalid input
        if((maxim-minim)==0){
            std::cout << "The range of possible steps has to be at least 1. \n";
        }
        if(true_min==maxim){ //tells user that the minim has to be less than maxim
            std::cout << "That doesnt make much sense, please enter the min again.\n";
        }
        if(minim == 0){
            std::cout <<"The minimum amount of steps cannot be 0.\n";
        }
    } while ( true_min== maxim || minim==0|| (maxim-minim)==0); //making sure the max and min makes sense, and that the minimum for the while loop is not 0

                                          
    //confirms the maxim and minim amount of steps
    std::cout << "\n\n The min number of steps are " << minim 
        << ".\n The max number of steps are " << maxim << ".\n"<<std::endl;   


    //now asks for how many steps you would like within the user defined maxim and minum
    std::cout << "So, negative number of steps go down, postive goes up.\n";     
    
    do{
        std::cout << "How many steps would you like? \n";
        std::cin >> steps;
        //user validation
        if (std::cin.fail()) {
          std::cin.clear();      
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "not an integer, try again\n";
          continue;
        }
        //informing user why input is invalid
        if (steps <minim) 
        {
            std::cout << "hmm, this is less than the minimum number of steps of " <<minim << ". Please pick a higher number.\n\n";
        }
        if (steps > maxim){
            std::cout << "There are too many steps.\n Please pick a lower number of steps.\n\n";
        } 
      } while (steps < minim || steps >maxim);
    

//
//
//PART 2: Showing the steps
//
// 

    //var declarations
    int j=0,k=steps-1;
    char symb = '#', space = ' ';


    //if the steps are going up first, and then down. happens if steps >0
    //prints out the steps that go up then down
    if (steps >0){ 
        std::cout << "\nGoing up!\n\n";
        for (int i=0; i <steps; i++){    
            while (j<=i){
                std::cout << std::string(k,space) << std::string(j+1,symb) << "\t" << std::string(j+1, symb);
                j++; k--;
            }
            std::cout << "\n";
        }
    }

    //if the steps desired is negative then the steps go down first
    if (steps<0){ 
        k=(steps*(-1))-1;  //making sure that k is positive so that the number of spaces is positive for the loop to print out the the stairs
        std::cout << "\nGoing down!\n\n";
        for (int i=0; i <(steps*(-1)); i++){    
            while (j<=i){
                std::cout << std::string(j+1, symb) << std::string(k,space) << "\t" << std::string(k,space) << std::string(j+1,symb);
                j++; k--;
            }
            std::cout << "\n";
        }
    }    
    //if the steps desired is 0 then the number of steps then the level is flat
    if (steps == 0){
        std::cout << "\n\n\nNo steps. We are staying at the same level.\n\n\n";
        for(int i=0; i<(15); i++){
        std::cout << "-";
        }
    }


    return 0;
}


//NOTES:if in the do while loop, one of the conditions is 0. then the program doesnt loop around again. 
//      that is why the maxim and minm cannot be 0.
/*

        if (std::cin.fail()) {
          std::cin.clear();      
          std::cin.ignore();
          std::cout << "That is not a number I understand.\n";
          continue;
        }

        std::cin.fail() This line is triggered if the input of cin failed for any reason whatso
        std::cin.clear() will clear the error flag triggered by the cin.fail
        std::cin.ignore(std::numeric_limits<std::streamsize>::max()), '\n') this would be better however with this line, the loop doesnt ask for user input again
        std::c
            
            
            
  -----------------------------------
    *next steps in program is to make a sepeate function for input validation

*/
