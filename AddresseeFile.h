#ifndef ADDRESSEEFILE_H
#define ADDRESSEEFILE_H

#include <iostream>

using namespace std;

class AddresseeFile{
private:
    const string addresseesFileName;

public:
    AddresseeFile() : addresseesFileName("AddresseesBook.txt") {};
    string getAddresseesFileName();
};

#endif
