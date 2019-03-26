#include "GenStack.h"
#include <iostream>

using namespace std;

class ReadFile
{
    private:
        int lines;
        string fileName;
        GenStack<char> *delimStack;
        GenStack<int> *lineStack;

    public:
        ReadFile();
        ~ReadFile();
        bool isFile(string name);
        bool checkFile();
        char complement(char d);
};
