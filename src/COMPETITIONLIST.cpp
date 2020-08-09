#include "COMPETITIONLIST.h"
#include "libraries.h"
using namespace std;

COMPETITIONLIST::COMPETITIONLIST()
{
    loadCompetitions();
    //ctor
}
COMPETITIONLIST::COMPETITIONLIST(SubPage tempPage, int competitionNumber)
{
    this->competitionNumber = competitionNumber;
    subPage = tempPage;
    loadCompetitions();
    //ctor
}

PAGE* COMPETITIONLIST::display(){
    if(subPage == Main){
    int count=1;
    color(6);
    for(auto i : competitions){
        cout << "\t\t" << count << ")  ";
        cout << i.name << endl;
        count++;
    }
    color(8);
    cout << "\nPress 0 to go back and corresponding number to view details : ";
    int selected;
    cin >> selected;
    if(selected == 0)return changePage("USER");
    return new COMPETITIONLIST(Details, selected);

    }

    if(subPage == Details){
        competitions[competitionNumber - 1].print();
        char temp;
        color(8);
        cout << "\n\nPress anything to go back : ";
        cin >> temp;
        return new COMPETITIONLIST;

    }
//    competitions[1].print();
    cout << "Add Competitions or display competions : ";
    char temp;
    cin >> temp;
    if(temp == 'o'){
        string id ="comp" + to_string(nextId);
        Competition tempCompetition(id, true);
        tempCompetition.add();
        nextId++;
        competitions.push_back(tempCompetition);
        ofstream listFile;
        listFile.open(location + "list.txt");
        for(auto i : competitions)
            listFile << i.id <<'\n';
        listFile.close();
    }
    return new COMPETITIONLIST;

}
void COMPETITIONLIST::loadCompetitions(){
    ifstream listFile;
    listFile.open(location + "list.txt");
    while(listFile){
        string id;
        getline(listFile, id);
        if(id=="")break;
        Competition tempCompetititon(id);
        competitions.push_back(tempCompetititon);
        id.replace(0,4,"");
        stringstream to_int(id);
        to_int >> nextId;
        nextId++;
    }
    listFile.close();

}
