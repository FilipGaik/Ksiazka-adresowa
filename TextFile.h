#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

using namespace std;

class TextFile{
protected:
    const string FILENAME;

public:
    TextFile(string FileName) : FILENAME(FileName){};
};

#endif
