#ifndef USER_H
#define USER_H

#include <PAGE.h>
#include <Color.h>
#include "libraries.h"
using namespace std;
class USER : public PAGE, public Color
{
    public:
        USER();
        PAGE* display();


    protected:

    private:
};

#endif // USER_H
