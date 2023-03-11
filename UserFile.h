#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class UserFile{
private:
    const string registeredUsersFileName;

public:
    UserFile(string regUsFiNa) : registeredUsersFileName(regUsFiNa) {};
    vector<User> loadRegisteredUsersToUsers();
    string getRegisteredUsersFileName();
};

#endif
