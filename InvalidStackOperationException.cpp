#include "InvalidStackOperationException.h"

InvalidStackOperationException::InvalidStackOperationException()
{
    errorMsg = "Invalid Stack Operation.";
}

InvalidStackOperationException::InvalidStackOperationException(const string& err)
{
    errorMsg = err;
}

string InvalidStackOperationException::getMessage() const
{
    return errorMsg;
}

InvalidStackOperationException::~InvalidStackOperationException()
{
    
}
