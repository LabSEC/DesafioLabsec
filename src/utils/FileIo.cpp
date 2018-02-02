#include "utils/FileIo.h"

FileIo::~FileIo() {}

ByteArray FileIo::readFile(const char* filePath)
{
    /**
     * TODO(milestone1)
     */
    ByteArray ret;
    fstream file (filePath, ios::in|ios::binary|ios::ate);
    if (file.is_open()) {
        TRACE(NOT_IMPLEMENTED);
        file.close();
    } else {
        TRACE(NOT_IMPLEMENTED);
    }
	return ret;
}

void FileIo::writeToFile(const char* filePath, ByteArray& data)
{
    /**
     * TODO(milestone2)
     */
    fstream file (filePath, ios::out|ios::binary|ios::trunc);
    if (file.is_open()) {
        TRACE(NOT_IMPLEMENTED);
        file.close();
    } else {
        TRACE(NOT_IMPLEMENTED);
    }
}
