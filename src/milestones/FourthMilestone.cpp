#include "milestones/FourthMilestone.h"

FourthMilestone::FourthMilestone()
{
	/**
 	* Like any other C++ code,
 	* this one needs little hack.
 	*/
	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
}

FourthMilestone::~FourthMilestone() {}

void FourthMilestone::createUserRepository(Certificate* userCert,
	KeyPair& userKeyPair)
{
    /**
     * TODO(milestone4)
     */
}

void FourthMilestone::createRootCaRepository(Certificate* rootCaCert,
    KeyPair& rootCaKeyPair)
{
    /**
     * TODO(milestone4)
     */
}
