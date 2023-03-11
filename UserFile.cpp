#include "UserFile.h"

vector<User> UserFile::loadRegisteredUsersToUsers(){
    int counter = 0;
    vector<User> users;
    fstream registeredUsers;
    registeredUsers.open(registeredUsersFileName, ios::in);
    User user;
    string line;
    cin.sync();

    while (getline(registeredUsers, line)){
        user.setId(stoi(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter)));
        user.setLogin(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
        user.setPassword(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));

        users.push_back(user);
        counter = 0;
        cin.sync();
    }
    return users;
}

string UserFile::getRegisteredUsersFileName(){
    return registeredUsersFileName;
}
