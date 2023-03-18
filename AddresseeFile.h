#ifndef ADDRESSEEFILE_H
#define ADDRESSEEFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "TextFile.h"
#include "Addressee.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class AddresseeFile : public TextFile{
    int theBiggestId;

public:
    AddresseeFile(string addresseesFileName)
    : TextFile(addresseesFileName){
        theBiggestId = 0;
    };
    string getAddresseesFileName();
    vector<Addressee> loadAddressBookToAddressees(int idOfLoggedUser);
    int getTheBiggestId();
    void setTheBiggestId(int newId);
};

#endif
