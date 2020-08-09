#include "PAGE.h"

#include "libraries.h"
#include "pages.h"
using namespace std;

PAGE* PAGE::display(){
cout <<"PAGE display";
}
PAGE* PAGE::changePage(string name){
    if(name == "LOGIN")
        return new LOGIN;
    if(name == "MAIN")
        return new MAIN;
    if(name == "REGISTRATION")
        return new REGISTRATION;
    if(name == "USER")
        return new USER;
    if(name == "COMPETITIONLIST")
        return new COMPETITIONLIST;
    try{
        throw name;
    }
    catch(string name){
        cout << "No page named \"" + name + "\" exists\nCheck changePage method in class \"PAGE\"";
    }


}
