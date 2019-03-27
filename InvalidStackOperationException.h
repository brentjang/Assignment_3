//From page 94 of Textbook
#include <iostream>

using namespace std;

class InvalidStackOperationException // generic run-time exception
{
private:
    string errorMsg;

public:
    InvalidStackOperationException();
    InvalidStackOperationException(const string& err);
    string getMessage() const;
    ~InvalidStackOperationException();
};
