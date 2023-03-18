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

    newFriend.setId(addresseeFile.getTheBiggestId() + 1);
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

    addresseeFile.setTheBiggestId(addresseeFile.getTheBiggestId() + 1);
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

void AddresseeManager::exportAfterDeletion(int id){
    int counter = 0;
    string line;
    int idToCompare;
    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::in);
    fstream addressBookTemporary;
    addressBookTemporary.open(addresseeFile.getAddresseesFileName() + "_temporary.txt", ios::out);

    while (getline(addressBook, line)){
        idToCompare = stoi(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
        if (idToCompare != id){
            addressBookTemporary << line << endl;
        }
        counter = 0;
    }

    addressBook.close();
    addressBookTemporary.close();
    string command = "del " + addresseeFile.getAddresseesFileName();
    system(command.c_str());
    string renameFrom = addresseeFile.getAddresseesFileName() + "_temporary.txt";
    string renameTo = addresseeFile.getAddresseesFileName();
    rename(renameFrom.c_str(), renameTo.c_str());
}

void AddresseeManager::setTheBiggestIdAfterDeletion(){
    int counter = 0;
    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::in);

    if (!addressBook.good()){
        return;
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

            addresseeFile.setTheBiggestId(myFriend.getId());

            counter = 0;
        }
    }
}

void AddresseeManager::deleteAddressee(){
    string idFromReadLine;
    int id;
    char confirmation;
    bool isIdInAddressees = false;
    int counterToDelete;

    if ((int) addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else{
        do{
            cout << "Podaj numer Id adresata do usuniecia: ";
            idFromReadLine = AuxiliaryFunctions::readLine();
        }while (!AuxiliaryFunctions::isNumber(idFromReadLine));

        id = stoi(idFromReadLine);

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].getId() == id){
                isIdInAddressees = true;
                counterToDelete = i;
                break;
            }
        }
        if (!isIdInAddressees){
            cout << "Nie ma takiego numeru id w ksiazce adresowej!" << endl;
        }
        else{
            cout << "Adresat o numerze Id: " << id << " zostanie usuniety." << endl;
            cout << "Potwierdz wciskajac klawisz t: ";
            cin >> confirmation;

            if (confirmation == 't'){
                addressees.erase(addressees.begin() + counterToDelete);
                exportAfterDeletion(id);
                cout << "Adresat zostal usuniety." << endl;
                if(id == addresseeFile.getTheBiggestId()){
                    setTheBiggestIdAfterDeletion();
                }
            }
            else{
                cout << "Adresat nie zostal usuniety." << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

void AddresseeManager::exportAfterEdition(string editedAddressee, int id){
    int counter = 0;
    string line;
    int idToCompare;
    fstream addressBook;
    addressBook.open(addresseeFile.getAddresseesFileName(), ios::in);
    fstream addressBookTemporary;
    addressBookTemporary.open(addresseeFile.getAddresseesFileName() + "_temporary.txt", ios::out);

    while (getline(addressBook, line)){
        idToCompare = stoi(AuxiliaryFunctions::getSubstringAndIncreaseCounter(line, counter));
        if (idToCompare != id){
            addressBookTemporary << line << endl;
        }
        else{
            addressBookTemporary << editedAddressee << endl;
        }
        counter = 0;
    }
    addressBook.close();
    addressBookTemporary.close();
    string command = "del " + addresseeFile.getAddresseesFileName();
    system(command.c_str());
    string renameFrom = addresseeFile.getAddresseesFileName() + "_temporary.txt";
    string renameTo = addresseeFile.getAddresseesFileName();
    rename(renameFrom.c_str(), renameTo.c_str());
}

void AddresseeManager::editAddressee(){
    string idFromReadLine;
    int id;
    string choiceFromReadLine;
    int choice;
    int counterInAddressees = -1;
    string editedAddressee;

    if ((int) addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("cls");
    }
    else{
        do{
            cout << "Podaj id adresata, ktorego chcesz edytowac: ";
            idFromReadLine = AuxiliaryFunctions::readLine();
        }while (!AuxiliaryFunctions::isNumber(idFromReadLine));

        id = stoi(idFromReadLine);

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].getId() == id){
                counterInAddressees = i;
                break;
            }
        }

        if (counterInAddressees == -1){
            cout << "Nie ma takiego numeru id w ksiazce adresowej!" << endl;
            system("pause");
            system("cls");
        }
        else{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "Edycja adresata." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << "1. Imie: " << addressees[counterInAddressees].getName() << endl;
            cout << "2. Nazwisko: " << addressees[counterInAddressees].getSurname() << endl;
            cout << "3. Numer telefonu: " << addressees[counterInAddressees].getPhoneNumber() << endl;
            cout << "4. E-mail: " << addressees[counterInAddressees].getEmail() << endl;
            cout << "5. Adres: " << addressees[counterInAddressees].getAddress() << endl;
            cout << "6. Powrot do menu glownego." << endl;
            do{
                cout << "Co chcesz edytowac? Wpisz numer od 1 do 6: ";
                choiceFromReadLine = AuxiliaryFunctions::readLine();
            }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

            choice = stoi(choiceFromReadLine);

            while (choice >= 1 && choice < 6){
                switch (choice){
                case 1:
                    cout << addressees[counterInAddressees].getName() << " zamienic na: ";
                    addressees[counterInAddressees].setName(AuxiliaryFunctions::readLine());
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 2:
                    cout << addressees[counterInAddressees].getSurname() << " zamienic na: ";
                    addressees[counterInAddressees].setSurname(AuxiliaryFunctions::readLine());
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 3:
                    cout << addressees[counterInAddressees].getPhoneNumber() << " zamienic na: ";
                    addressees[counterInAddressees].setPhoneNumber(AuxiliaryFunctions::readLine());
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 4:
                    cout << addressees[counterInAddressees].getEmail() << " zamienic na: ";
                    addressees[counterInAddressees].setEmail(AuxiliaryFunctions::readLine());
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 5:
                    cout << addressees[counterInAddressees].getAddress() << " zamienic na: ";
                    addressees[counterInAddressees].setAddress(AuxiliaryFunctions::readLine());
                    cout << "Adresat zostal zaktualizowany." << endl;
                }
                do{
                    cout << "Co chcesz edytowac? Wpisz numer od 1 do 6: ";
                    choiceFromReadLine = AuxiliaryFunctions::readLine();
                }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));
                choice = stoi(choiceFromReadLine);
            }

            editedAddressee = to_string(addressees[counterInAddressees].getId()) + "|" + to_string(addressees[counterInAddressees].getIdOfLoggedUser()) +
            "|" + addressees[counterInAddressees].getName() + "|" + addressees[counterInAddressees].getSurname() +
            "|" + addressees[counterInAddressees].getPhoneNumber() + "|" + addressees[counterInAddressees].getEmail() +
            "|" + addressees[counterInAddressees].getAddress() + "|";

            exportAfterEdition(editedAddressee, id);
            system("cls");
        }
    }
}

void AddresseeManager::displayByName(){
    if (addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("cls");
    }
    else{
        cout << "Podaj imie, ktore mam wyszukac: ";
        string name = AuxiliaryFunctions::readLine();
        bool thereIsAMatch = false;

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].getName() == name){
                cout << endl << "ID: " << addressees[i].getId() << endl;
                cout << addressees[i].getName() << " " << addressees[i].getSurname() << endl;
                cout << "Numer telefonu: " << addressees[i].getPhoneNumber() << endl;
                cout << "E-mail: " << addressees[i].getEmail() << endl;
                cout << "Adres: " << addressees[i].getAddress() << endl;

                thereIsAMatch = true;
            }
        }

        if (!thereIsAMatch){
            cout << "Niestety brak danych dla imienia " << name << endl;
        }

        cout << endl;
        system("pause");
        system("cls");
    }
}

void AddresseeManager::displayBySurname(){
    if (addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("cls");
    }
    else{
        cout << "Podaj nazwisko, ktore mam wyszukac: ";
        string name = AuxiliaryFunctions::readLine();
        bool thereIsAMatch = false;

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].getSurname() == name){
                cout << endl << "ID: " << addressees[i].getId() << endl;
                cout << addressees[i].getName() << " " << addressees[i].getSurname() << endl;
                cout << "Numer telefonu: " << addressees[i].getPhoneNumber() << endl;
                cout << "E-mail: " << addressees[i].getEmail() << endl;
                cout << "Adres: " << addressees[i].getAddress() << endl;

                thereIsAMatch = true;
            }
        }

        if (!thereIsAMatch){
            cout << "Niestety brak danych dla nazwiska " << name << endl;
        }

        cout << endl;
        system("pause");
        system("cls");
    }
}
