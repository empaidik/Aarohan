#include "MAIN.h"
#include "libraries.h"
using namespace std;
MAIN::MAIN()
{
    //ctor

}
MAIN::MAIN(string error)
{
    hasError = true;
    this->error = error;
    //ctor

}

MAIN::~MAIN()
{
    //dtor
}

PAGE* MAIN::display(){
    if(hasError){color(4);cout << error << endl;}
    color(10);
    cout << "\t\t\t  Login\n\n";
    color(8);
    cout << "\t\t-----------OR-----------\n\n";
    color(10);
    cout << "\t\t\t Register\n\n";
    color(8);
    cout << "Press 1 to Login and 2 to Registration : ";
    char input;
    cin  >> input;
    if(input == '1')
        return changePage("LOGIN");
    else if(input == '2')
       return changePage("REGISTRATION");
//    else return changePage("MAIN");
    else return new MAIN("Invalid entry");
}
