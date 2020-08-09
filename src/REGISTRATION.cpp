#include "REGISTRATION.h"
#include <iostream>
#include <Person.h>
#include <LOGIN.h>
using namespace std;

PAGE* REGISTRATION::display(){
    Person p;
    p.selfRegister();
    return new LOGIN("We have received your application successfully.\nYou will be able to login after we review your application.");


}
