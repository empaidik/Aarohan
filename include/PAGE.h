#ifndef PAGE_H
#define PAGE_H

#include "libraries.h"
class PAGE
{
    public:
        virtual PAGE* display();
        PAGE* changePage(std::string name);
    protected:

    private:
};

#endif // PAGE_H
