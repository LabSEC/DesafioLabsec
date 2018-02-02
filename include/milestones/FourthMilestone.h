#ifndef FOURTHMILESTONE_H
#define FOURTHMILESTONE_H

#include <libcryptosec/Pkcs12Builder.h>
#include <libcryptosec/KeyPair.h>

#include "utils/FileIo.h"
#include "utils/trace.h"
#include "utils/paths.h"

/**
 * @brief <b>Fourth Milestone - PKCS12 Key Repository</b><p>
 *
 * It is not a good idea to keep Private Keys in plain text files.
 * You should protect the keys you've just created by using
 * encryption. There are several ways to protect cryptographic keys,
 * the one you are about to implement is a standard called PKCS#12.
 * To create a PKCS#12 file (extension .p12) you will pack together
 * the Private Key and its respective certificate. Both assets have
 * been produced on previous milestones.
 * The key repository's structure is somewhat like this:<br>
 *
 * <Alias, <Certificate, PrivateKey> > <br>
 *
 * Alias is the nickname or friendly name given to the tuple
 * <Certificate, PrivateKey>.<p>
 *
 * - Use <b>Pkcs12Builder</b> class to build a <b>PKCS12</b>;<br>
 * - Write the PKCS12 to using DER encoding;<br>
 *   - paths::userP12Path;<br>
 *   - paths::rootCaP12Path.<p>
 *
 * @see libcryptosec/Pkcs12Builder
 * @see libcryptosec/Pkcs12
 *
 * <b>SELF EVALUATION</b> (Requires previous milstones to run)<br>
 * In evaluation folder run '$make fourth'.<br>
 * You need to implement the evaluation for this milestone.<p>
 *
 * @author Lucas Perin
 */
class FourthMilestone {

public:

	FourthMilestone();

	virtual ~FourthMilestone();

	/**
     * TODO Implement this function in the cpp file.
     */
	void createUserRepository(Certificate* userCert,
		KeyPair& userKeyPair);

	/**
     * TODO Implement this function in the cpp file.
     */
	void createRootCaRepository(Certificate* rootCaCert,
		KeyPair& rootCaKeyPair);


	/**
 	* PKCS12 alias (friendly name)
 	*/
	const char* userAlias = "userP12";
	const char* rootCaAlias = "rootP12";

	/**
 	* PKCS12 password
 	*/
	const char* userPass = "userpassword";
	const char* rootCaPass = "rootcapassword";
};

#endif /*FOURTHMILESTONE_H*/
