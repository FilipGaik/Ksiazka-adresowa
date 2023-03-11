#include "AddressBook.h"

void AddressBook::loadRegisteredUsersToUsers(){
    userManager.loadRegisteredUsersToUsers();
}

void AddressBook::setChoiceFromReadLine(){
    choiceFromReadLine = AuxiliaryFunctions::readLine();
}

int AddressBook::getIdOfLoggedUser(){
    return userManager.getIdOfLoggedUser();
}

void AddressBook::setIdOfLoggedUser(int newId){
    userManager.setIdOfLoggedUser(newId);
}

void AddressBook::registration(){
    userManager.registration();
}

int AddressBook::loggingIn (){
    return userManager.loggingIn();
}

void AddressBook::displayRegLogMenu(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "KSIAZKA ADRESOWA" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "1. Rejestracja." << endl;
    cout << "2. Logowanie." << endl;
    cout << "3. Zakoncz program." << endl;

    do{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "Wybierz opcje (1-3): ";
        setChoiceFromReadLine();
    }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    choice = stoi(choiceFromReadLine);

    switch(choice){
    case 1:
        registration();
        break;
    case 2:
        setIdOfLoggedUser(loggingIn());
        break;
    default:
        exit(0);
    }
}

void AddressBook::changePassword(){
    userManager.changePassword();
}

int AddressBook::loadAddressBookToAddressees(int idOfLoggedUser){
    return addresseeManager.loadAddressBookToAddressees(idOfLoggedUser);
}

void AddressBook::displayMenu(){
    int theBiggestId = loadAddressBookToAddressees(getIdOfLoggedUser());

    do{
        system("cls");
        if (theBiggestId == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Ksiazka adresowa jest pusta, wprowadz dane!" << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "KSIAZKA ADRESOWA" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        cout << "1. Dodaj adresata." << endl;
        cout << "2. Wyszukaj adresata po imieniu." << endl;
        cout << "3. Wyszukaj adresata po nazwisku." << endl;
        cout << "4. Wyswietl wszystkich adresatow." << endl;
        cout << "5. Usun adresata." << endl;
        cout << "6. Edytuj adresata." << endl;
        cout << "7. Zmien haslo." << endl;
        cout << "8. Wyloguj." << endl;

        do{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "Wybierz opcje (1-8): ";
            setChoiceFromReadLine();
        }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        choice = stoi(choiceFromReadLine);

        switch (choice){
        case 1:
            theBiggestId = addresseeManager.addFriend(userManager.getIdOfLoggedUser(), theBiggestId);
            break;
        case 2:
            cout << "Opcja jeszcze niedostepna." << endl; system("pause"); system("cls"); //displayByName();
            break;
        case 3:
            cout << "Opcja jeszcze niedostepna." << endl; system("pause"); system("cls"); //displayBySurname();
            break;
        case 4:
            addresseeManager.displayAddressBook();
            break;
        case 5:
            cout << "Opcja jeszcze niedostepna." << endl; system("pause"); system("cls"); //theBiggestId = deleteAddressee(theBiggestId);
            break;
        case 6:
            cout << "Opcja jeszcze niedostepna." << endl; system("pause"); system("cls"); //editAddressee();
            break;
        case 7:
            changePassword();
            break;
        default:
            setIdOfLoggedUser(0);
        }
    }while (choice >= 1 && choice < 8);
}
