#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Addressee{
    int id, idOfLoggedUser;
    string name, surname, phoneNumber, email, address;
};

struct User{
    int id;
    string login, password;
};

string readLine(){
    string line;
    cin.sync();
    getline(cin, line);
    return line;
}

bool isNumber(string line){
    for (int i = 0; i < (int) line.size(); i++){
        if (!isdigit(line[i])){
            return false;
        }
    }
    return true;
}

string getSubstringAndIncreaseCounter(string line, int& counter){
    string substring;

    for (int i = counter; i < (int) line.size(); i++){
        if (line[i] != '|'){
            substring += line[i];
        }
        else{
            counter = i + 1;
            break;
        }
    }
    return substring;
}

int loadAddressBookToAddressees(vector<Addressee>& addressees, int idOfLoggedUser){
    int counter = 0;
    int theBiggestId = 0;
    fstream addressBook;
    addressBook.open( "KsiazkaAdresowa.txt", ios::in);

    addressees.clear();

    if (!addressBook.good()){
        return 0;
    }
    else{
        Addressee myFriend;
        string line;
        cin.sync();

        while (getline(addressBook, line)){
            myFriend.id = stoi(getSubstringAndIncreaseCounter(line, counter));
            myFriend.idOfLoggedUser = stoi(getSubstringAndIncreaseCounter(line, counter));
            myFriend.name = getSubstringAndIncreaseCounter(line, counter);
            myFriend.surname = getSubstringAndIncreaseCounter(line, counter);
            myFriend.phoneNumber = getSubstringAndIncreaseCounter(line, counter);
            myFriend.email = getSubstringAndIncreaseCounter(line, counter);
            myFriend.address = getSubstringAndIncreaseCounter(line, counter);

            theBiggestId = myFriend.id;

            if (myFriend.idOfLoggedUser == idOfLoggedUser){
                    addressees.push_back(myFriend);
            }
            counter = 0;
            cin.sync();
        }
        return theBiggestId;
    }
}

int addFriend(vector<Addressee>& addressees, int idOfLoggedUser, int theBiggestId){
    Addressee newFriend;

    cout << "Podaj imie: ";
    newFriend.name = readLine();

    cout << "Podaj nazwisko: ";
    newFriend.surname = readLine();

    cout << "Podaj numer telefonu: ";
    newFriend.phoneNumber = readLine();

    cout << "Podaj adres e-mail: ";
    newFriend.email = readLine();

    cout << "Podaj adres: ";
    newFriend.address = readLine();

    newFriend.id = (theBiggestId == 0) ? 1 : theBiggestId + 1;
    newFriend.idOfLoggedUser = idOfLoggedUser;

    addressees.push_back(newFriend);

    fstream addressBook;
    addressBook.open("KsiazkaAdresowa.txt", ios::out | ios::app);

    addressBook << addressees[addressees.size() - 1].id << "|" << addressees[addressees.size() - 1].idOfLoggedUser << "|"
    << addressees[addressees.size() - 1].name << "|" << addressees[addressees.size() - 1].surname << "|"
    << addressees[addressees.size() - 1].phoneNumber << "|" << addressees[addressees.size() - 1].email << "|"
    << addressees[addressees.size() - 1].address << "|" << endl;

    cout << "Kontakt zostal dodany." << endl;
    Sleep(3000);
    system("cls");
    return theBiggestId++;
}

void displayByName(vector<Addressee> addressees){
    if (addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("cls");
    }
    else{
        cout << "Podaj imie, ktore mam wyszukac: ";
        string name = readLine();
        bool thereIsAMatch = false;

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].name == name){
                cout << endl << "ID: " << addressees[i].id << endl;
                cout << addressees[i].name << " " << addressees[i].surname << endl;
                cout << "Numer telefonu: " << addressees[i].phoneNumber << endl;
                cout << "E-mail: " << addressees[i].email << endl;
                cout << "Adres: " << addressees[i].address << endl;

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

void displayBySurname(vector<Addressee> addressees){
    if (addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("cls");
    }
    else{
        cout << "Podaj nazwisko, ktore mam wyszukac: ";
        string name = readLine();
        bool thereIsAMatch = false;

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].surname == name){
                cout << endl << "ID: " << addressees[i].id << endl;
                cout << addressees[i].name << " " << addressees[i].surname << endl;
                cout << "Numer telefonu: " << addressees[i].phoneNumber << endl;
                cout << "E-mail: " << addressees[i].email << endl;
                cout << "Adres: " << addressees[i].address << endl;

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

void displayAddressBook(vector<Addressee> addressees){
    if (addressees.size() == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Plik pusty, najpierw dodaj dane!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else{
        for (int i = 0; i < (int) addressees.size(); i++){
            cout << endl << "ID: " << addressees[i].id << endl;
            cout << addressees[i].name << " " << addressees[i].surname << endl;
            cout << "Numer telefonu: " << addressees[i].phoneNumber << endl;
            cout << "E-mail: " << addressees[i].email << endl;
            cout << "Adres: " << addressees[i].address << endl;
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}

void exportAfterDeletion(int id){
    int counter = 0;
    string line;
    int idToCompare;
    fstream addressBook;
    addressBook.open( "KsiazkaAdresowa.txt", ios::in);
    fstream addressBookTemporary;
    addressBookTemporary.open("KsiazkaAdresowa_temporary.txt", ios::out);

    while (getline(addressBook, line)){
        idToCompare = stoi(getSubstringAndIncreaseCounter(line, counter));
        if (idToCompare != id){
            addressBookTemporary << line << endl;
        }
        counter = 0;
    }
    addressBook.close();
    addressBookTemporary.close();
    system("del KsiazkaAdresowa.txt");
    rename("KsiazkaAdresowa_temporary.txt", "KsiazkaAdresowa.txt");
}

void exportAfterEdition(vector<Addressee> addressees, int id, int counterInAddressees){
    int counter = 0;
    string line;
    int idToCompare;
    fstream addressBook;
    addressBook.open( "KsiazkaAdresowa.txt", ios::in);
    fstream addressBookTemporary;
    addressBookTemporary.open("KsiazkaAdresowa_temporary.txt", ios::out);

    while (getline(addressBook, line)){
        idToCompare = stoi(getSubstringAndIncreaseCounter(line, counter));
        if (idToCompare != id){
            addressBookTemporary << line << endl;
        }
        else{
            addressBookTemporary << addressees[counterInAddressees].id << "|" << addressees[counterInAddressees].idOfLoggedUser << "|"
            << addressees[counterInAddressees].name << "|" << addressees[counterInAddressees].surname << "|"
            << addressees[counterInAddressees].phoneNumber << "|" << addressees[counterInAddressees].email << "|"
            << addressees[counterInAddressees].address << "|" << endl;
        }
        counter = 0;
    }
    addressBook.close();
    addressBookTemporary.close();
    system("del KsiazkaAdresowa.txt");
    rename("KsiazkaAdresowa_temporary.txt", "KsiazkaAdresowa.txt");
}

void deleteAddressee(vector<Addressee>& addressees){
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
            idFromReadLine = readLine();
        }while (!isNumber(idFromReadLine));

        id = stoi(idFromReadLine);

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].id == id){
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
                auto it = addressees.begin() + counterToDelete;
                addressees.erase(it);
                exportAfterDeletion(id);
                cout << "Adresat zostal usuniety." << endl;
            }
            else{
                cout << "Adresat nie zostal usuniety." << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

void editAddressee(vector<Addressee>& addressees){
    string idFromReadLine;
    int id;
    string choiceFromReadLine;
    int choice;
    int counterInAddressees = -1;

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
            idFromReadLine = readLine();
        }while (!isNumber(idFromReadLine));

        id = stoi(idFromReadLine);

        for (int i = 0; i < (int) addressees.size(); i++){
            if (addressees[i].id == id){
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
            cout << "1. Imie: " << addressees[counterInAddressees].name << endl;
            cout << "2. Nazwisko: " << addressees[counterInAddressees].surname << endl;
            cout << "3. Numer telefonu: " << addressees[counterInAddressees].phoneNumber << endl;
            cout << "4. E-mail: " << addressees[counterInAddressees].email << endl;
            cout << "5. Adres: " << addressees[counterInAddressees].address << endl;
            cout << "6. Powrot do menu glownego." << endl;
            do{
                cout << "Co chcesz edytowac? Wpisz numer od 1 do 6: ";
                choiceFromReadLine = readLine();
            }while (!isNumber(choiceFromReadLine));

            choice = stoi(choiceFromReadLine);

            while (choice >= 1 && choice < 6){
                switch (choice){
                case 1:
                    cout << addressees[counterInAddressees].name << " zamienic na: ";
                    addressees[counterInAddressees].name = readLine();
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 2:
                    cout << addressees[counterInAddressees].surname << " zamienic na: ";
                    addressees[counterInAddressees].surname = readLine();
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 3:
                    cout << addressees[counterInAddressees].phoneNumber << " zamienic na: ";
                    addressees[counterInAddressees].phoneNumber = readLine();
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 4:
                    cout << addressees[counterInAddressees].email << " zamienic na: ";
                    addressees[counterInAddressees].email = readLine();
                    cout << "Adresat zostal zaktualizowany." << endl;
                    break;
                case 5:
                    cout << addressees[counterInAddressees].address << " zamienic na: ";
                    addressees[counterInAddressees].address = readLine();
                    cout << "Adresat zostal zaktualizowany." << endl;
                }
                do{
                    cout << "Co chcesz edytowac? Wpisz numer od 1 do 6: ";
                    choiceFromReadLine = readLine();
                }while (!isNumber(choiceFromReadLine));
                choice = stoi(choiceFromReadLine);
            }
            exportAfterEdition(addressees, id, counterInAddressees);
            system("cls");
        }
    }
}

void exportRegisteredUsersToExternalFile(vector<User> users){
    fstream registeredUsers;
    registeredUsers.open("Registered users.txt", ios::out);

    for (int i = 0; i < (int) users.size(); i++){
        registeredUsers << users[i].id << "|" << users[i].login << "|"
        << users[i].password << "|" << endl;
    }
}

void changePassword(vector<User>& users, int idOfLoggedUser){
    string password;
    cout << "Podaj nowe haslo: ";
    cin >> password;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].id == idOfLoggedUser){
            users[i].password = password;
            exportRegisteredUsersToExternalFile(users);
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(2000);
            break;
        }
    }
}

void displayMenu(vector<Addressee>& addressees, vector<User>& users, int& idOfLoggedUser){
    int choice;
    string choiceFromReadLine;
    int theBiggestId;

    theBiggestId = loadAddressBookToAddressees(addressees, idOfLoggedUser);

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
            choiceFromReadLine = readLine();
        }while (!isNumber(choiceFromReadLine));

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        choice = stoi(choiceFromReadLine);

        switch (choice){
        case 1:
            theBiggestId = addFriend(addressees, idOfLoggedUser, theBiggestId);
            break;
        case 2:
            displayByName(addressees);
            break;
        case 3:
            displayBySurname(addressees);
            break;
        case 4:
            displayAddressBook(addressees);
            break;
        case 5:
            deleteAddressee(addressees);
            break;
        case 6:
            editAddressee(addressees);
            break;
        case 7:
            changePassword(users, idOfLoggedUser);
            break;
        default:
            idOfLoggedUser = 0;
        }
    }while (choice >= 1 && choice < 8);
}

void registration (vector<User>& users){
    User newUser;
    string login, password;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].login == login){
            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> login;
            i = -1;
        }
    }

    cout << "Podaj haslo: ";
    cin >> password;
    newUser.login = login;
    newUser.password = password;
    newUser.id = (users.size() == 0) ? 1 : users.back().id + 1;
    users.push_back(newUser);

    fstream registeredUsers;
    registeredUsers.open("Registered users.txt", ios::out | ios::app);

    registeredUsers << users[users.size() - 1].id << "|" << users[users.size() - 1].login << "|"
    << users[users.size() - 1].password << "|" << endl;

    cout << "Konto zalozone." << endl;
    Sleep(2000);
}

int loggingIn (vector<User> users){
    string login, password;

    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].login == login){
            for (int j = 0; j < 3; j++){
                cout << "Podaj haslo. Pozostalo prob (" << 3 - j << "): ";
                cin >> password;
                if (password == users[i].password)
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(2000);
                    return users[i].id;
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba." << endl;
            Sleep(3000);

            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem." << endl;
    Sleep(2000);

    return 0;
}

void loadRegisteredUsersToUsers(vector<User>& users){
    int counter = 0;
    fstream registeredUsers;
    registeredUsers.open( "Registered users.txt", ios::in);

    if (!registeredUsers.good()){
        return;
    }
    else{
        User user;
        string line;
        cin.sync();

        while (getline(registeredUsers, line)){
            user.id = stoi(getSubstringAndIncreaseCounter(line, counter));
            user.login = getSubstringAndIncreaseCounter(line, counter);
            user.password = getSubstringAndIncreaseCounter(line, counter);

            users.push_back(user);
            counter = 0;
            cin.sync();
        }
    }
}

int main(){
    vector <Addressee> addressees;
    vector <User> users;
    int idOfLoggedUser = 0;
    int choice;
    string choiceFromReadLine;

    loadRegisteredUsersToUsers(users);

    while (1){
        if (idOfLoggedUser == 0){
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
                choiceFromReadLine = readLine();
            }while (!isNumber(choiceFromReadLine));

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            choice = stoi(choiceFromReadLine);

            switch(choice){
            case 1:
                registration(users);
                break;
            case 2:
                idOfLoggedUser = loggingIn(users);
                break;
            default:
                exit(0);
            }
        }
        else{
            displayMenu(addressees, users, idOfLoggedUser);
        }
    }

    return 0;
}
