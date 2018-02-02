#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <libcryptosec/ByteArray.h>
#include "exceptions/IoException.h"
#include "utils/trace.h"
#include "utils/macros.h"

/**
 * @brief <b>I/O handling functions </b><p>
 *
 * This class contains functions that will help with i/o
 * throughout the milestones.
 *
 * Data read from file or to be written to file must be
 * loaded in the <b>ByteArray</b> Object from Libcryptosec. To
 * handle the i/o, use <b>fstream</b> from standard library.
 * Errors in read and write static functions should return
 * IoException with apropriate error code.
 *
 * @see std::fstream
 * @see libcryptosec/ByteArray
 * @see IoException
 *
 * @author Lucas Perin
 */
class FileIo {

public:

	virtual ~FileIo();

	/**
 	* Static function. Reads files with from file path.
 	* TODO implement this function in the cpp file.
 	*
 	* @param filePath string with path to file.
 	* @return ByteArray containing data read from file.
 	*/
	static ByteArray readFile(const char* filePath);

	/**
 	* Static function. Writes data to file.
 	* TODO implement this function in the cpp file.
 	*

 	* @param ByteArray containing data to write to file.
 	*/
	static void writeToFile(const char* filePath, ByteArray& data);
};
#endif /*FILEIO_H*/
