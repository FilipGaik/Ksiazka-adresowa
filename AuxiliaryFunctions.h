#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>

using namespace std;

class AuxiliaryFunctions{
public:
    static string readLine();
    static bool isNumber(string line);
    static string getSubstringAndIncreaseCounter(string line, int& counter);
};

#endif
