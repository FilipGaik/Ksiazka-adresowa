#ifndef ADDRESSEEFILE_H
#define ADDRESSEEFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Addressee.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class AddresseeFile{
    const string ADDRESSEES_FILENAME;
    int theBiggestId;

public:
    AddresseeFile(string addresseesFileName) : ADDRESSEES_FILENAME(addresseesFileName){
        theBiggestId = 0;
    };
    string getAddresseesFileName();
    vector<Addressee> loadAddressBookToAddressees(int idOfLoggedUser);
    int getTheBiggestId();
    void setTheBiggestId(int newId);
};

#endif
