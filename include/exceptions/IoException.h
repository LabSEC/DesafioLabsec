#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <libcryptosec/exception/LibCryptoSecException.h>

/**
 * @brief <b>I/O Exception</b><p>
 *
 * Use this class to throw I/O exceptions when reading or writing files.<p>
 *
 * @see libcryptosec/LibCryptoSecException
 *
 * @author Lucas Perin
 *
 */
class IoException : public LibCryptoSecException {

public:
	enum ErrorCode {
		UNKNOWN,
		READ_FAILED,
		WRITE_FAILED
	};

	IoException(std::string where)
	{
		this->where = where;
		this->errorCode = IoException::UNKNOWN;
	}

	IoException(std::string where, IoException::ErrorCode errorCode)
	{
		this->where = where;
		this->errorCode = errorCode;
	}

	~IoException() throw () {}

	virtual std::string getMessage() const
	{
		return (IoException::errorCode2Message(this->errorCode));
	}


	virtual std::string toString() const
        {
               	return "IoException: " + IoException::errorCode2Message(this->errorCode) + ". Called by: " + this->where + ".";
        }

    	virtual IoException::ErrorCode getErrorCode()
    	{
        	return this->errorCode;
    	}


    	static std::string errorCode2Message(IoException::ErrorCode errorCode)
    	{
        	std::string ret;
        	switch (errorCode)
        	{
                	case IoException::UNKNOWN:
                        	ret = "Unknown error";
                        	break;
			case IoException::READ_FAILED:
				ret = "Failed to read file";
				break;
			case IoException::WRITE_FAILED:
				ret = "Failed to write file";
				break;
        	}
		return ret;
	}

protected:
	IoException::ErrorCode errorCode;

};
#endif /*IOEXCEPTION*/
