#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager{
private:
    int idOfLoggedUser;
    vector <User> users;
    UserFile userFile;

public:
    UserManager(string registeredUsersFileName) : userFile(registeredUsersFileName){
        idOfLoggedUser = 0;
    };
    void loadRegisteredUsersToUsers();
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int newId);
    void registration();
    int loggingIn ();
    void exportRegisteredUsersToExternalFile();
    void changePassword();
};

#endif
