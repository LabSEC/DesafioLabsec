#ifndef FIFTHMILESTONE_H
#define FIFTHMILESTONE_H

#include <libcryptosec/Pkcs12.h>
#include <libcryptosec/AsymmetricCipher.h>

#include "utils/paths.h"
#include "utils/trace.h"

/**
 * @brief <b>Fifth Milestone - Asymmetric Encryption</b><br>
 *
 * At this point you should have read a little about asymmetric and
 * symmetric cryptography. If you haven't done so, please refer to
 * the Wikipedia website for a brief reading.<p>
 *
 * For this milestone you will implement data encryption using your
 * public and secret key. The goal is to encrypt the plain text file
 * (same one from milestone one). Understaning asymmetric encryption
 * is the first step to understand Digital Signatures.
 *
 * - Use your PKCS12 file to extract your certificate and Private Key;<br>
 * - In your certificate you may find your Public Key;<br>
 * - Construct a <b>RSAPublicKey</b> and a <b>RSAPrivateKey</b>.<br>
 * - Use the static functions <b>encrypt</b> and <b>decrypt</b><p>
 *
 * @see libcryptosec/RSAPrivateKey
 * @see libcryptosec/RSAPublicKey
 * @see libcryptosec/AsymmetricCipher
 *
 * <b>SELF EVALUATION</b> (Requires previous milstones to run)<br>
 * In evaluation folder run '$make fifth'.<br>
 * You need to implement the evaluation for this milestone.<p>
 *
 * @author Lucas Perin
 */
class FifthMilestone {

public:
    FifthMilestone();

    virtual ~FifthMilestone();

	/**
     * TODO Implement this function in the cpp file.
     */
    ByteArray encryptData(ByteArray& data, Pkcs12& userP12);

	/**
     * TODO Implement this function in the cpp file.
     */
    ByteArray decryptData(ByteArray& data, Pkcs12& userP12);
};


#endif /*FIFTHMILESTONE_H*/
