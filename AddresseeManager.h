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
    vector <Addressee> addressees;
    AddresseeFile addresseeFile;
    const int ID_OF_LOGGED_USER;
    void exportAfterDeletion(int id);
    void setTheBiggestIdAfterDeletion();
    void exportAfterEdition(string editedAddressee, int id);

public:
    AddresseeManager(string addresseesFileName, int idOfLoggedUser)
        : addresseeFile(addresseesFileName), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        addressees = addresseeFile.loadAddressBookToAddressees(ID_OF_LOGGED_USER);
    };
    void addFriend();
    void displayAddressBook();
    int getTheBiggestId();
    void deleteAddressee();
    void editAddressee();
    void displayByName();
    void displayBySurname();
};

#endif
