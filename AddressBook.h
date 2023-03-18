#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook{
    UserManager userManager;
    AddresseeManager* addresseeManager;
    const string ADDRESSEES_FILENAME;

public:
    AddressBook(string registeredUsersFileName, string addresseesFileName)
        : userManager(registeredUsersFileName), ADDRESSEES_FILENAME(addresseesFileName)
    {
        addresseeManager = NULL;
    };
    ~AddressBook()
    {
        delete addresseeManager;
        addresseeManager = NULL;
    };
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int newId);
    void registration();
    void loggingIn ();
    void changePassword();
    void addFriend();
    void displayAddressBook();
    void logout();
    int getTheBiggestId();
    void deleteAddressee();
    void editAddressee();
    void displayByName();
    void displayBySurname();
};

#endif
