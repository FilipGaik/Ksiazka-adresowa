#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "TextFile.h"
#include "User.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class UserFile : public TextFile{
public:
    UserFile(string registeredUsersFileName)
    : TextFile(registeredUsersFileName) {};
    vector<User> loadRegisteredUsersToUsers();
    string getRegisteredUsersFileName();
};

#endif
