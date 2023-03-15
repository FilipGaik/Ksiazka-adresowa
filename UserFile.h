#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class UserFile{
    const string REGISTERED_USERS_FILENAME;

public:
    UserFile(string registeredUsersFileName) : REGISTERED_USERS_FILENAME(registeredUsersFileName) {};
    vector<User> loadRegisteredUsersToUsers();
    string getRegisteredUsersFileName();
};

#endif
