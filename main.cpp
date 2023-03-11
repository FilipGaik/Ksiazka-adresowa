#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Registered users.txt");
    addressBook.loadRegisteredUsersToUsers();
    while (1){
        if (addressBook.getIdOfLoggedUser() == 0){
            addressBook.displayRegLogMenu();
        }
        else{
            addressBook.displayMenu();
        }
    }

    return 0;
}
