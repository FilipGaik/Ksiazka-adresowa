#include "AddresseeFile.h"

string AddresseeFile::getAddresseesFileName(){
    return FILENAME;
}

vector<Addressee> AddresseeFile::loadAddressBookToAddressees(int idOfLoggedUser){
    vector<Addressee> addressees;
    int counter = 0;
    theBiggestId = 0;
    fstream addressBook;
    addressBook.open(getAddresseesFileName(), ios::in);

    if (!addressBook.good()){
        return addressees;
    }
    else{
        Addressee myFriend;
        string line;
        cin.sync();

        while (getline(addressBook, line)){
            myFriend.setId(stoi(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter)));
            myFriend.setIdOfLoggedUser(stoi(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter)));
            myFriend.setName(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
            myFriend.setSurname(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
            myFriend.setPhoneNumber(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
            myFriend.setEmail(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
            myFriend.setAddress(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));

            theBiggestId = myFriend.getId();

            if (myFriend.getIdOfLoggedUser() == idOfLoggedUser){
                addressees.push_back(myFriend);
            }
            counter = 0;
            cin.sync();
        }
        return addressees;
    }
}

void AddresseeFile::setTheBiggestId(int newId){
    theBiggestId = newId;
}

int AddresseeFile::getTheBiggestId(){
    return theBiggestId;
}
