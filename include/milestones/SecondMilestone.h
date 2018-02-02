#ifndef SECONDMILESTONE_H
#define SECONDMILESTONE_H

#include <libcryptosec/RSAKeyPair.h>

#include "utils/FileIo.h"
#include "utils/trace.h"
#include "utils/paths.h"
#include "utils/macros.h"

/**
 * @brief <b>Second Milestone - Asymmetric Key Pairs </b> <p>
 *
 * The second milestone uses Asymmetric Cryptography. You are
 * expected to generate two RSA key pairs and write them to file.
 * One key pair belongs to you, the other one will be a Root
 * Certification Authority key pair. Note that, even though one
 * key pair contains two keys, you can write them together in the
 * same file. Hence, you will write two files for this milestone.<p>
 *
 * - Implement the <b>FileIo::writeToFile</b> static function;<br>
 * - Use <b>RsaKeyPair</b> to generate the RSA Key Pairs;<br>
 * - Write both Key Pairs to file using DER format;<br>
 *   - paths::userKeyPairPath;<br>
 *   - paths::rootCaKeyPairPath;<br>
 * - Key sizes should be 2048 for the Root CA and 1024 four your key.<p>
 *
 * @see libcryptosec/RSAKeyPair
 * @see libcryptosec/KeyPair
 * @see FileIo
 *
 * SELF EVALUATION (Requires previous milstone to run)<br>
 * In evaluation folder run '$make second'.<p>
 *
 * @author Lucas Perin
 */
class SecondMilestone {

public:

	virtual ~SecondMilestone();

	/**
	 * TODO Implement this function in the cpp file.
	 */
	void generateKeyPairs();

};

#endif /*SECONDMILESTONE_H*/
