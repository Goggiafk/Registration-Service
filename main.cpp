#include <iostream>
#include <fstream>
#include <string>

/* ############################# User messages ############################## */
#define MSG_ENTERLOGIN "Enter your Login"
#define MSG_ENTERPASSWORD "Enter your Password"
#define MSG_INVALIDLOGIN "Invalid Login or Password"
#define MSG_SUCCESS "Successfully logged in"
#define MSG_FAREWELL "Bye-bye!"

#define ERR_INVALIDARGUMENTS "Invalid Arguments: No userdata FilePath provided"
#define ERR_FILENOTLOADED "File couldn't open"

#define MSG_OPTIONSELECT "Choose an option:"
#define MSG_REGISTEROPTION "1 - Register"
#define MSG_LoginOPTION "2 - Login"
#define MSG_EXITOPTION "3 - Exit"
#define MSG_WRONGOPTION "Wrong option selected"
/* ########################################################################## */

void RegisterUser(std::string FilePath) {
    std::string Login, Password;

    std::cout << MSG_ENTERLOGIN << std::endl;
    std::cin >> Login;
    std::cout << MSG_ENTERPASSWORD << std::endl;
    std::cin >> Password;

    std::ofstream Outfile(FilePath);

    if (!Outfile.is_open()) {
        return;
        std::cout << ERR_FILENOTLOADED << std::endl;
    }

    Outfile << Login << std::endl;
    Outfile << Password << std::endl;
    Outfile.close();
}

void LoginUser(std::string FilePath) {
    std::string Login, Password;

    std::cout << MSG_ENTERLOGIN << std::endl;
    std::cin >> Login;
    std::cout << MSG_ENTERPASSWORD << std::endl;
    std::cin >> Password;

    std::ifstream Infile(FilePath);
    if (!Infile.is_open()) {
        return;
        std::cout << ERR_FILENOTLOADED << std::endl;
    }

    std::string Line;
    
    getline(Infile, Line);
    
    if (Line == Login)
    {
        getline(Infile, Line);
        if (Line == Password) {
            std::cout << MSG_SUCCESS << std::endl;
        }
        else 
        {
            std::cout << MSG_INVALIDLOGIN << std::endl;
        }
    }
    else 
    {
        std::cout << MSG_INVALIDLOGIN << std::endl;
    }
    
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << ERR_INVALIDARGUMENTS << std::endl;
        return 0;
    }

    int UserChoice{};

    while (UserChoice != 3) {
        std::cout << MSG_OPTIONSELECT << std::endl;
        std::cout << MSG_REGISTEROPTION << std::endl;
        std::cout << MSG_LoginOPTION << std::endl;
        std::cout << MSG_EXITOPTION << std::endl;

        std::cin >> UserChoice;

        switch (UserChoice) {
        case 1:
			RegisterUser(argv[1]);
            break;
        case 2:
            LoginUser(argv[1]);
            break;
        case 3:
            std::cout << MSG_FAREWELL << std::endl;
            break;
        default:
            std::cout << MSG_WRONGOPTION;
            break;
        }
    }

    return 0;
}