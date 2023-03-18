#include "AddressBook.h"

int AddressBook::getIdOfLoggedUser(){
    return userManager.getIdOfLoggedUser();
}

void AddressBook::setIdOfLoggedUser(int newId){
    userManager.setIdOfLoggedUser(newId);
}

void AddressBook::registration(){
    userManager.registration();
}

void AddressBook::loggingIn (){
    userManager.loggingIn();
    if (getIdOfLoggedUser() > 0){
        addresseeManager = new AddresseeManager(ADDRESSEES_FILENAME, userManager.getIdOfLoggedUser());
    }
}

void AddressBook::changePassword(){
    userManager.changePassword();
}

void AddressBook::addFriend(){
    addresseeManager -> addFriend();
}

void AddressBook::displayAddressBook(){
    addresseeManager -> displayAddressBook();
}

void AddressBook::logout(){
    userManager.setIdOfLoggedUser(0);
    delete addresseeManager;
    addresseeManager = NULL;
}

int AddressBook::getTheBiggestId(){
    return addresseeManager -> getTheBiggestId();
}

void AddressBook::deleteAddressee(){
    addresseeManager -> deleteAddressee();
}

void AddressBook::editAddressee(){
    addresseeManager -> editAddressee();
}

void AddressBook::displayByName(){
    addresseeManager -> displayByName();
}

void AddressBook::displayBySurname(){
    addresseeManager -> displayBySurname();
}
