#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::readLine(){
    string line;
    cin.sync();
    getline(cin, line);
    return line;
}

bool AuxiliaryFunctions::isNumber(string line){
    for (int i = 0; i < (int) line.size(); i++){
        if (!isdigit(line[i])){
            return false;
        }
    }
    return true;
}

string AuxiliaryFunctions::getSubstringAndIncreaseCounter(string line, int& counter){
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
