#include "Person.h"

Person::Person()
{
    //ctor
}

void Person::selfRegister(){

    cout << "\nName, College, Email, Phone Number, Set Username and Password :\nPress Enter to continue\n";
    cin.ignore();
    cout << "Name : ";getline(cin, name);
    cout << "College : ";getline(cin, collegeName);
    cout << "Email : ";getline(cin, email);
    cout << "Phone Number: ";getline(cin, phoneNumber);
    cout << "Set Username : ";getline(cin, username);
    cout << "Set Password : ";getline(cin,password);
    savePendingUser();

}
string Person::getNextUserId(){
        fstream listFile;
        listFile.open(location + "pending/list.txt", ios::in);
        string lastString = "";
        vector<string> listStack;
        while(listFile){
            getline(listFile, lastString);
            listStack.push_back(lastString);
        }
        listStack.pop_back();
        if(listStack.size() != 0){

            int lastNumber;
            stringstream to_int(listStack[listStack.size() - 1]);
            to_int >> lastNumber;
            lastNumber++;
            listStack.push_back(to_string(lastNumber));
        }
        else listStack.push_back("1");
        listFile.close();
        listFile.open(location + "pending/list.txt", ios::out);
        for(auto i : listStack)
            listFile << i << "\n";
        listFile.close();
        return listStack[listStack.size() - 1];
}
void Person::savePendingUser(){
    string nextUserId = getNextUserId();
    cout << nextUserId;
    ofstream userFile;
    userFile.open(location + "pending/"+nextUserId + ".txt");
    userFile << name << "\n";
    userFile << collegeName << "\n";
    userFile << email << "\n";
    userFile << phoneNumber << "\n";
    userFile << username << "\n";
    userFile << password << "\n";
    userFile.close();
    ofstream usersFile;
    usersFile.open(location + "users.txt", ios::app);

    usersFile <<"\np" << username <<"\n" << password;
    usersFile.close();
}
