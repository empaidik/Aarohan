#include <PAGE.h>
#include <Color.h>
#include <MAIN.h>
#include <COMPETITIONLIST.h>
#include <LOGIN.h>
#include <REGISTRATION.h>
#include <ctime>
#include <cstdlib>
using namespace std;
Color color;

void heading();

int main()
{
    srand((unsigned)time(0));
    PAGE* pagePointer = new MAIN;
    while(true){
    system("cls");
    heading();
    PAGE* tempPage;
    tempPage = pagePointer->display();
    delete pagePointer;
    pagePointer = tempPage;
    }
    return 0;
}

void heading(){
    color.color(14);
    cout << "\n\n\t********* AAROHAN --- THE CULTURAL FEST *********\n\n";
    color.color(11);
    cout << "\t\t Pune's Largest Cultural Fest\n\n\n\n\n";
    color.color(8);
    cout << "Notifications : ";
    color.color(12);
    vector<string> notifications = {"Aarohan is pune's largest cultural fest", "Dyanamic notifications from the Admins will pop-up here\n\t\tThese are urgent"};
    int randomNumber  = rand()%(notifications.size());
    cout << notifications.at(randomNumber);
    cout << "\n\n\n\n";

}


// 0 -> Black
// 1-> Violet
// 2 -> Green **
// 3 -> light blue  **
// 4 -> Red
// 5 -> Purple
// 6 -> yellow
// 7 -> White
// 8 -> Gray
// 9 -> Black
// 10 -> Black
// 11 -> Black
// 12 -> Black
// 13 -> Black
// 14 -> Black
// 15 -> Black


