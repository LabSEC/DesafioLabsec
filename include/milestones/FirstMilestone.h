#ifndef FIRSTMILESTONE_H
#define FIRSTMILESTONE_H

#include <libcryptosec/MessageDigest.h>
#include <libcryptosec/ByteArray.h>

#include "utils/FileIo.h"
#include "utils/trace.h"
#include "utils/paths.h"
#include "utils/macros.h"
/**
 * @brief <b>First Milestone - Obtain the Hash of a document.</b><p>
 *
 * The first milestone is simple. Compute the hash value of the
 * document <b>plainText.txt</b>, available at <b>assets/texts</b>. <p>
 *
 * - Implement the <b>FileIo::readFile</b> static function;<br>
 *   - read file from paths::plainText
 * - Use <b>MessageDigest</b> from LibcryptoSec for the Hash function;<br>
 * - Initialize MessageDigest with SHA1 algorithm;<br>
 * - Use ByteArray from LibcryptoSEC to handle binary data.<p>
 *
 * @see libcryptosec/ByteArray
 * @see libcryptosec/MessageDigest
 * @see FileIo
 *
 * <b>SELF EVALUATION</b><br>
 * In evaluation folder run '$make first'.<p>
 *
 * @author Lucas Perin
 */
class FirstMilestone {

public:
    virtual ~FirstMilestone();

    /**
     * TODO Implement this function in the cpp file.
     */
    ByteArray computeHash();
};
#endif /*FIRSTMILESTONE_H*/
