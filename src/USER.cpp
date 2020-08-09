#include "User.h"

USER::USER()
{
    //ctor
}
PAGE* USER::display(){
    cout << "\n1) View Schedule";
    cout << "\n2) Register for Competitions";
    cout << "\n3) View competition list";
    cout << "\n4) My account details";
    cout << "\n5) Logout";
    cout << "\n\n Enter valid choice : ";
    char input;
    cin >> input;
    switch(input){
    case '1':
    case '2':
    case '3':return changePage("COMPETITIONLIST");
    case '4':
    case '5':return changePage("MAIN");

    }
}
