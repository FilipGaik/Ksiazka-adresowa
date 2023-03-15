#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <iostream>

using namespace std;

class Addressee{
    int id;
    int idOfLoggedUser;
    string name;
    string surname;
    string phoneNumber;
    string email;
    string address;

public:
    Addressee(int id = 0, int idOfLoggedUser = 0, string name = "", string surname = "", string phoneNumber = "", string email = "", string address = ""){
        this -> id = id;
        this -> idOfLoggedUser = idOfLoggedUser;
        this -> name = name;
        this -> surname = surname;
        this -> phoneNumber = phoneNumber;
        this -> email = email;
        this -> address = address;
    }
    void setId(int newId);
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int getId();
    int getIdOfLoggedUser();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};

#endif
