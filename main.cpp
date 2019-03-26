#include "ReadFile.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ReadFile hello;
    string name;
    bool flag = true;
    bool check;
    if(argc == 2)
    {
        name = argv[1];
        if(hello.isFile(name))
        {
            check = hello.checkFile();
            flag = check;
        }
        if(check)
        {
            cout << "Syntax for this file is correct." << endl;
        }
    }
    else
    {
        cout << "Invalid Arguements." << endl;
    }
    return 0;
}
