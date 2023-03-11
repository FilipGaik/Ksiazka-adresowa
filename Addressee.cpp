#include "Addressee.h"

void Addressee::setId(int newId){
    if (newId >= 0){
        id = newId;
    }
}

void Addressee::setIdOfLoggedUser(int newIdOfLoggedUser){
    if (newIdOfLoggedUser >= 0){
        idOfLoggedUser = newIdOfLoggedUser;
    }
}

void Addressee::setName(string newName){
    if ((int) newName.size() > 0){
        name = newName;
    }
}

void Addressee::setSurname(string newSurname){
    if ((int) newSurname.size() > 0){
        surname = newSurname;
    }
}

void Addressee::setPhoneNumber(string newPhoneNumber){
    if ((int) newPhoneNumber.size() > 0){
        phoneNumber = newPhoneNumber;
    }
}

void Addressee::setEmail(string newEmail){
    if ((int) newEmail.size() > 0){
        email = newEmail;
    }
}

void Addressee::setAddress(string newAddress){
    if ((int) newAddress.size() > 0){
        address = newAddress;
    }
}

int Addressee::getId(){
    return id;
}

int Addressee::getIdOfLoggedUser(){
    return idOfLoggedUser;
}

string Addressee::getName(){
    return name;
}

string Addressee::getSurname(){
    return surname;
}

string Addressee::getPhoneNumber(){
    return phoneNumber;
}

string Addressee::getEmail(){
    return email;
}

string Addressee::getAddress(){
    return address;
}
