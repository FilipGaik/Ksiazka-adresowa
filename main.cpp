#include <iostream>

#include "AddressBook.h"

using namespace std;

int main(){
    string choiceFromReadLine;
    int choice;
    AddressBook addressBook("Registered users.txt", "AddresseesBook.txt");

    while (true){
        if (addressBook.getIdOfLoggedUser() == 0){
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
                choiceFromReadLine = AuxiliaryFunctions::readLine();
            }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            choice = stoi(choiceFromReadLine);

            switch(choice){
            case 1:
                addressBook.registration();
                break;
            case 2:
                addressBook.loggingIn();
                break;
            default:
                exit(0);
            }
        }
        else{
            do{
                system("cls");
                if (addressBook.getTheBiggestId() == 0){
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
                    choiceFromReadLine = AuxiliaryFunctions::readLine();
                }while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                choice = stoi(choiceFromReadLine);

                switch (choice){
                case 1:
                    addressBook.addFriend();
                    break;
                case 2:
                    addressBook.displayByName();
                    break;
                case 3:
                    addressBook.displayBySurname();
                    break;
                case 4:
                    addressBook.displayAddressBook();
                    break;
                case 5:
                    addressBook.deleteAddressee();
                    break;
                case 6:
                    addressBook.editAddressee();
                    break;
                case 7:
                    addressBook.changePassword();
                    break;
                default:
                    addressBook.logout();
                }
            }while (choice >= 1 && choice < 8);
        }
    }

    return 0;
}
