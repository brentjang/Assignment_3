//From page 94 of Textbook
#include <iostream>

using namespace std;

class InvalidStackOperationException // generic run-time exception
{
private:
    string errorMsg;

public:
    InvalidStackOperationException(const string& err)
    {
        errorMsg = err;
    }
    string getMessage() const
    {
        return errorMsg;
    }
};
