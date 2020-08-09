#ifndef LOGIN_H
#define LOGIN_H

#include <PAGE.h>
#include <Color.h>

class LOGIN : public PAGE, public Color
{
    public:
        LOGIN();
        virtual ~LOGIN();
        PAGE* display();
        LOGIN(std::string error);
        enum SubPage{
            Main, Login, ForgotPassword
        }subPage = Main;
        LOGIN(SubPage tempPage);
        std::string username;
        std::string password;
        PAGE* checkIfUserExists(std::string username, std::string password);
    protected:

    private:
        bool hasError = false;
        std::string error;
};

#endif // LOGIN_H
