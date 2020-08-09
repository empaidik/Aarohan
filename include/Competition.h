#ifndef COMPETITION_H
#define COMPETITION_H
#include <vector>
#include <string>
#include "libraries.h"
#include <Color.h>
using namespace std;
class Competition : public Color
{
    public:
        Competition(string id);
        Competition(string id, bool useless);
        void save();
        void print();
        void load();
        void add();
        string name;
        string description;
        string id = "none";
        string location = "data/competitions/";
        int entryFee;
        int teamLimit;
        int timeLimit;
        vector<int> cashPrizes;
};

#endif // COMPETITION_H
