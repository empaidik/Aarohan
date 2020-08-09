#include "LOGIN.h"
#include "libraries.h"
using namespace std;
LOGIN::LOGIN()
{
    //ctor
}
LOGIN::LOGIN(string error)
{
    hasError = true;
    this->error = error;
    //ctor

}
LOGIN::LOGIN(SubPage tempPage){
    subPage = tempPage;
}
LOGIN::~LOGIN()
{
    //dtor
}
PAGE* LOGIN::display(){
    if(subPage == Main){
        color(10);
        cout << "\n\t\t     Login To Aarohan\n\n";
        color(8);
        cout << "\t\t-----------OR-----------\n\n";
        color(10);
        cout << "\t\t    Go Back To Main Menu\n\n";

        if(hasError){color(4);cout << error << endl;}
        color(8);
        cout << "Press 1 to Login  or  2 to Go Back : ";
        char input;
        cin >> input;
        if(input == '1') return new LOGIN(Login);
        if(input == '2') return changePage("MAIN");
        else return new LOGIN("Invalid Entry");
    }
    else if(subPage == Login){
        color(10);
        cout << "\n\t\t     Login To Aarohan\n\n";
        color(6);
        cout << "\n\tUsername : ";
        cout << "\n\tPassword : \n\n";
        color(8);
        cout << "Enter Username : ";
        color(15);
        cin.ignore();
        getline(cin, username);
        color(8);
        cout << "Enter Password : ";
        color(15);
        getline(cin, password);
        cout << username << "\t" << password;
        char input;
        return checkIfUserExists(username, password);
    }

}

PAGE* LOGIN::checkIfUserExists(string username, string password){
    ifstream userFile;
    userFile.open("data/users/users.txt");
    while(userFile){

    string tempUsername;
    string tempPassword;

    getline(userFile, tempUsername);
    getline(userFile, tempPassword);

    bool userInPendingList = false;
    if(tempUsername[0] == 'p')userInPendingList = true;
    tempUsername.replace(0, 1, "");
    if(tempUsername == username)
        if(tempPassword == password){
            if(userInPendingList)return new LOGIN(":( OPPS\nYour account is still under verification.\nContact Team Aarohan, If its taking too long.");
            return changePage("USER");
        }
    }
    return new LOGIN("Invalid credentials. Contact Aarohan team for help");
}
