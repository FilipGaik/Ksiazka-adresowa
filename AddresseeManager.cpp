#include "AddresseeManager.h"

void AddresseeManager::addFriend(){
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

    newFriend.setId(getTheBiggestId() + 1);
    newFriend.setIdOfLoggedUser(ID_OF_LOGGED_USER);

    addressees.push_back(newFriend);

    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::out | ios::app);

    addressBook << addressees[addressees.size() - 1].getId() << "|" << addressees[addressees.size() - 1].getIdOfLoggedUser() << "|"
    << addressees[addressees.size() - 1].getName() << "|" << addressees[addressees.size() - 1].getSurname() << "|"
    << addressees[addressees.size() - 1].getPhoneNumber() << "|" << addressees[addressees.size() - 1].getEmail() << "|"
    << addressees[addressees.size() - 1].getAddress() << "|" << endl;

    cout << "Kontakt zostal dodany." << endl;
    system("pause");
    system("cls");

    addresseeFile.setTheBiggestId(getTheBiggestId() + 1);
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

int AddresseeManager::getTheBiggestId(){
    return addresseeFile.getTheBiggestId();
}
