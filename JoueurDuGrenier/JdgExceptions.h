#ifndef INCLUDE_JDGEXCEPTION
#define INCLUDE_JDGEXCEPTION

#include <exception>
#include <string>


class ManagerException : public std::exception
{
	public:
		ManagerException(int errorCode, std::string errorDescription) throw();
		virtual ~ManagerException() throw();
		virtual const char* what() const throw();
		const char* getDescription() const throw();
		const int getErrorCode() const throw();

	private:
		int _errorCode;
		std::string _errorDescription;
};

#endif