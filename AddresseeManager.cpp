#include "AddresseeManager.h"

int AddresseeManager::loadAddressBookToAddressees(int idOfLoggedUser){
    int counter = 0;
    int theBiggestId = 0;
    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::in);

    addressees.clear();

    if (!addressBook.good()){
        return 0;
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
        return theBiggestId;
    }
}

int AddresseeManager::addFriend(int idOfLoggedUser, int theBiggestId){
    Addressee newFriend;

    cout << "Podaj imie: ";
    newFriend.setName(AuxiliaryFunctions::readLine());

    cout << "Podaj nazwisko: ";
    newFriend.setSurname(AuxiliaryFunctions::readLine());

    cout << "Podaj numer telefonu: ";
    newFriend.setPhoneNumber(AuxiliaryFunctions::readLine());

    cout << "Podaj adres e-mail: ";
    newFriend.setEmail(AuxiliaryFunctions::readLine());

    cout << "Podaj adres: ";
    newFriend.setAddress(AuxiliaryFunctions::readLine());

    newFriend.setId(theBiggestId == 0 ? 1 : theBiggestId + 1);
    newFriend.setIdOfLoggedUser(idOfLoggedUser);

    addressees.push_back(newFriend);

    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::out | ios::app);

    addressBook << addressees[addressees.size() - 1].getId() << "|" << addressees[addressees.size() - 1].getIdOfLoggedUser() << "|"
    << addressees[addressees.size() - 1].getName() << "|" << addressees[addressees.size() - 1].getSurname() << "|"
    << addressees[addressees.size() - 1].getPhoneNumber() << "|" << addressees[addressees.size() - 1].getEmail() << "|"
    << addressees[addressees.size() - 1].getAddress() << "|" << endl;

    cout << "Kontakt zostal dodany." << endl;
    Sleep(3000);
    system("cls");

    return ++theBiggestId;
}

void AddresseeManager::displayAddressBook(){
    if ((int) addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else{
        for (int i = 0; i < (int) addressees.size(); i++){
            cout << endl << "ID: " << addressees[i].getId() << endl;
            cout << addressees[i].getName() << " " << addressees[i].getSurname() << endl;
            cout << "Numer telefonu: " << addressees[i].getPhoneNumber() << endl;
            cout << "E-mail: " << addressees[i].getEmail() << endl;
            cout << "Adres: " << addressees[i].getAddress() << endl;
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}
