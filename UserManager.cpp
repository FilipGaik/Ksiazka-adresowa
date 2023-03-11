#include "UserManager.h"

void UserManager::loadRegisteredUsersToUsers(){
    users = userFile.loadRegisteredUsersToUsers();
}

int UserManager::getIdOfLoggedUser(){
    return idOfLoggedUser;
}

void UserManager::setIdOfLoggedUser(int newId){
    if (newId >= 0){
        idOfLoggedUser = newId;
    }
}

void UserManager::registration(){
    User newUser;
    string login, password;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].getLogin() == login){
            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> login;
            i = -1;
        }
    }

    cout << "Podaj haslo: ";
    cin >> password;
    newUser.setLogin(login);
    newUser.setPassword(password);
    newUser.setId(users.size() == 0 ? 1 : users.back().getId() + 1);
    users.push_back(newUser);

    fstream registeredUsers;
    registeredUsers.open(userFile.getRegisteredUsersFileName(), ios::out | ios::app);

    registeredUsers << users[users.size() - 1].getId() << "|" << users[users.size() - 1].getLogin() << "|"
    << users[users.size() - 1].getPassword() << "|" << endl;

    cout << "Konto zalozone." << endl;
    Sleep(2000);
}

int UserManager::loggingIn (){
    string login, password;

    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].getLogin() == login){
            for (int j = 0; j < 3; j++){
                cout << "Podaj haslo. Pozostalo prob (" << 3 - j << "): ";
                cin >> password;
                if (password == users[i].getPassword())
                {
                    cout << "Zalogowales sie." << endl;
                    Sleep(2000);
                    return users[i].getId();
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

void UserManager::exportRegisteredUsersToExternalFile(){
    fstream registeredUsers;
    registeredUsers.open(userFile.getRegisteredUsersFileName(), ios::out);

    for (int i = 0; i < (int) users.size(); i++){
        registeredUsers << users[i].getId() << "|" << users[i].getLogin() << "|"
        << users[i].getPassword() << "|" << endl;
    }
}

void UserManager::changePassword(){
    string password;
    cout << "Podaj nowe haslo: ";
    cin >> password;

    for (int i = 0; i < (int) users.size(); i++){
        if (users[i].getId() == idOfLoggedUser){
            users[i].setPassword(password);
            exportRegisteredUsersToExternalFile();
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(2000);
            break;
        }
    }
}
