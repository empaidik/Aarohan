#ifndef MAIN_H
#define MAIN_H

#include <PAGE.h>
#include <Color.h>
#include "libraries.h"

class MAIN : public PAGE, public Color
{
    public:
        MAIN();
        MAIN(std::string error);
        virtual ~MAIN();
        PAGE* display();
    protected:

    private:
        bool hasError = false;
        std::string error;

};

#endif // MAIN_H
