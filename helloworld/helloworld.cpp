//SM- practice getting using input and output from the terminal

#include <iostream>
using namespace std;

int main(){
    string name;
    std::cout<<"Hello! What is your name?\n";
    cin >> name;
    cout << "Hello, " << name;
    return 0; 
}
