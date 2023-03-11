#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook{
private:
    UserManager userManager;
    string choiceFromReadLine;
    int choice;
    AddresseeManager addresseeManager;

public:
    AddressBook(string registeredUsersFileName) : userManager(registeredUsersFileName) {};
    void loadRegisteredUsersToUsers();
    void setChoiceFromReadLine();
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int newId);
    void displayRegLogMenu();
    void registration();
    int loggingIn ();
    int loadAddressBookToAddressees(int idOfLoggedUser);
    void displayMenu();
    void changePassword();

};

#endif
