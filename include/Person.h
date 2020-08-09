#ifndef PERSON_H
#define PERSON_H
#include "libraries.h"
using namespace std;

class Person
{
    public:
        Person();
        void selfRegister();
        void savePendingUser();
        string getNextUserId();
    protected:

    private:
        string location = "data/users/";
        string name;
        string collegeName;
        string email;
        string phoneNumber;
        string username;
        string password;
};

#endif // PERSON_H
