#include "JdgExceptions.h"



ManagerException::ManagerException(int errorCode, std::string errorDescription) throw() : _errorCode(errorCode), _errorDescription(errorDescription)
{
}

ManagerException::~ManagerException() throw()
{
}

const char* ManagerException::what() const throw()
{
	return ("ManagerException: " + _errorCode + _errorDescription).c_str();
}

const char* ManagerException::getDescription() const throw()
{
	return _errorDescription.c_str();
}

const int ManagerException::getErrorCode() const throw()
{
	return _errorCode;
}