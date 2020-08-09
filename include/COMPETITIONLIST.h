#ifndef COMPETITIONLIST_H
#define COMPETITIONLIST_H

#include <PAGE.h>
#include <Color.h>
#include "Competition.h"
#include "libraries.h"
using namespace std;
class COMPETITIONLIST : public PAGE, public Color
{
    public:
        COMPETITIONLIST();

        int competitionNumber;
        PAGE* display();
        vector<Competition> competitions;
        void loadCompetitions();
        enum SubPage{
            Main, Details, Admin
        }subPage = Main;

        COMPETITIONLIST(SubPage tempPage, int competitionNumber);
    protected:

    private:
        string location = "data/competitions/";
        int nextId = 1;
};

#endif // COMPETITIONLIST_H
