#ifndef ADDRESSEEMANAGER_H
#define ADDRESSEEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "AddresseeFile.h"
#include "Addressee.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class AddresseeManager{
private:
    vector <Addressee> addressees;
    AddresseeFile addresseeFile;

public:
    int loadAddressBookToAddressees(int idOfLoggedUser);
    int addFriend(int idOfLoggedUser, int theBiggestId);
    void displayAddressBook();
};

#endif
