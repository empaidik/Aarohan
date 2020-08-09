#include "Competition.h"
#include "libraries.h"
using namespace std;


Competition::Competition(string id)
{
    this->id = id;
    load();
    //ctor
}
Competition::Competition(string id, bool useless)
{
    this->id = id;
    //ctor
}
void Competition::add(){

            cout << "\nName, Description, Entry Fees, Team Limit, Cash Prizes :\nPress Enter to continue\n";
            cin.ignore();
            cout << "Name : ";getline(cin, name);
            cout << "Description : ";getline(cin, description);
            cout << "Entry Fee : ";cin >> entryFee;
            cout << "Team Limit : ";cin >> teamLimit;
            cout << "Time Limit : ";cin >> timeLimit;
            string strStream;  // For cash prizes
            int tempNum;
            cout << "Cash Prizes (If more than one separate them by spaces) : ";
            cin.ignore();
            getline(cin, strStream);
            istringstream vectorStream(strStream);
            while (vectorStream >> tempNum)
                cashPrizes.push_back(tempNum);
            save();
}

void Competition::save(){
            ofstream file;
            file.open(location+id+".txt");
            file << id <<"\n";
            file << name <<"\n";
            file << description <<"\n";
            file << entryFee <<"\n";
            file << teamLimit <<"\n";
            file << timeLimit <<"\n";
            for(auto i : cashPrizes)
                file << i << " ";
            file.close();
}

void Competition::print(){
        color(11);
        cout << "\n\t\t" << name << "\n";
        color(8);cout << "\n\tDescription : ";color(10);cout << description;
        color(8);cout << "\n\tEntry Fees  : ";color(10); cout  << entryFee;
        color(8);cout << "\n\tTeam Limit  : ";color(10); cout  << teamLimit;
        color(8);cout << "\n\tTime Limit  : ";color(10); cout << timeLimit;
color(8);
        cout << "\n\tCash Prizes : ";color(10);
        for( auto i : cashPrizes)
            cout << i << "/-  ";
}

void Competition::load(){
            ifstream file;
            file.open(location+id+".txt");
            getline(file, id);
            getline(file, name);
            getline(file, description);
            file >> entryFee;
            file >> teamLimit;
            file >> timeLimit;
            string temp;
            int tempNum;
            file.ignore();
            getline(file, temp);
            istringstream vectorStream(temp);
            while (vectorStream >> tempNum)
                cashPrizes.push_back(tempNum);
            file.close();
}
