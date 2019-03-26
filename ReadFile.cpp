#include "ReadFile.h"
#include <fstream>
#include <iostream>

using namespace std;

ReadFile::ReadFile()
{
    lines = 1;
    fileName = "";
    delimStack = new GenStack<char>();
    lineStack = new GenStack<int>();
}

ReadFile::~ReadFile()
{

}

bool ReadFile::isFile(string name)
{
    bool flag = true;
    ifstream file(name);
    if(!file.good())
    {
        cout << "Not a file." << endl;
        flag = false;
    }
    //check if the file is empty
    else if(file.peek() == ifstream::traits_type::eof())
    {
        cout << "File is empty." << endl;
        flag = false;
    }
    else
    {
        fileName = name;
    }
    return flag;
}

bool ReadFile::checkFile()
{
    ifstream file(fileName);
    string line;
    char next;
    bool flag = true;
    bool found = false;
    while(getline(file, line) && !found)
    {
        if(line[0] == '/' && line[1] == '/')
        {
            continue;
        }
        else
        {
            for(int i = 0; i < line.size(); i++)
            {
                next = line[i];

                //if the next character is an open delimiter, push to stack with line number
                if(next == '{' || next == '[' || next == '(')
                {
                    char d = complement(next);
                    delimStack->push(d);
                    lineStack->push(lines);
                }

                //if the next character is a closed delimiter, compare it to the top of the stack
                else if(next == '}' || next == ']' || next == ')')
                {
                    if(next == delimStack->peek())
                    {
                        delimStack->pop();
                        lineStack->pop();
                    }
                    else if(next != delimStack->peek())
                    {
                        cout << "Unmatched delimiter " << complement(delimStack->pop()) << " at line: " << lineStack->pop() << endl;
                        flag = false;
                        found = true;
                        break;
                    }
                    else
                    {
                        cout << "Unmatched delimiter " << next << " at line: " << lines << endl;
                        flag = false;
                        found = true;
                        break;
                    }
                }
            }
        }
        lines++;
    }

    //for an extra open delimiter
    if(!delimStack->isEmpty() && flag)
    {
        cout << "Unmatched delimiter " << complement(delimStack->pop()) << " at line: " << lineStack->pop() << endl;
        flag = false;
    }
    
    file.close();
    return flag;
}

//reverses the delimiter so its easier to compare
char ReadFile::complement(char d)
{
    switch (d)
    {
        case '{':
            d = '}';
            break;
        case '[':
            d = ']';
            break;
        case '(':
            d = ')';
            break;
        case '}':
            d = '{';
            break;
        case ']':
            d = '[';
            break;
        case ')':
            d = '(';
            break;
        default:
            break;
    }
    return d;
}
