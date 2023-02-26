#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Addressee{
    int id;
    string name, surname, phoneNumber, email, address;
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

void loadAddressBookToAddressees(vector<Addressee>& addressees, int& counter){
    fstream addressBook;
    addressBook.open( "Ksiazka adresowa.txt", ios::in);

    if (!addressBook.good()){
        return;
    }
    else{
        Addressee myFriend;
        string line;
        cin.sync();

        while (getline(addressBook, line)){
            myFriend.id = stoi(getSubstringAndIncreaseCounter(line, counter));
            myFriend.name = getSubstringAndIncreaseCounter(line, counter);
            myFriend.surname = getSubstringAndIncreaseCounter(line, counter);
            myFriend.phoneNumber = getSubstringAndIncreaseCounter(line, counter);
            myFriend.email = getSubstringAndIncreaseCounter(line, counter);
            myFriend.address = getSubstringAndIncreaseCounter(line, counter);

            addressees.push_back(myFriend);
            counter = 0;
            cin.sync();
        }
    }
}

void displayMenu(){
    fstream addressBook;
    addressBook.open( "Ksiazka adresowa.txt", ios::in);

    if (!addressBook.good()){
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
    cout << "7. Zakoncz program." << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Wybierz opcje (1-7): ";
}

void addFriend(vector<Addressee>& addressees){
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

    newFriend.id = (addressees.size() == 0) ? 1 : addressees.back().id + 1;

    addressees.push_back(newFriend);

    fstream addressBook;
    addressBook.open("Ksiazka adresowa.txt", ios::out | ios::app);

    addressBook << addressees[addressees.size() - 1].id << "|" << addressees[addressees.size() - 1].name << "|"
    << addressees[addressees.size() - 1].surname << "|" << addressees[addressees.size() - 1].phoneNumber << "|"
    << addressees[addressees.size() - 1].email << "|" << addressees[addressees.size() - 1].address << "|" << endl;

    cout << "Kontakt zostal dodany." << endl;
    Sleep(3000);
    system("cls");
}

void displayByName(vector<Addressee> addressees){
    if ((int) addressees.size() == 0){
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
    if ((int) addressees.size() == 0){
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
    fstream addressBook;
    addressBook.open("Ksiazka adresowa.txt", ios::in);

    if (!addressBook.good()){
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

void exportAddressesToExternalFile(vector<Addressee> addressees){
    fstream addressBook;
    addressBook.open("Ksiazka adresowa.txt", ios::out);

    for (int i = 0; i < (int) addressees.size(); i++){
        addressBook << addressees[i].id << "|" << addressees[i].name << "|"
        << addressees[i].surname << "|" << addressees[i].phoneNumber << "|"
        << addressees[i].email << "|" << addressees[i].address << "|" << endl;
    }
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
                exportAddressesToExternalFile(addressees);
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
            exportAddressesToExternalFile(addressees);
            system("cls");
        }
    }
}

int main(){
    vector <Addressee> addressees;
    int choice;
    int counter = 0;

    loadAddressBookToAddressees(addressees, counter);

    do{
        displayMenu();
        cin >> choice;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        switch (choice){
        case 1:
            addFriend(addressees);
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
        }
    } while (choice > 0 && choice < 7);

    return 0;
}
