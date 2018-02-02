#include "milestones/FifthMilestone.h"

FifthMilestone::FifthMilestone()
{
	/**
     * Like any other C++ code,
     * this one needs little hack.
     */
	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
}

FifthMilestone::~FifthMilestone() {}



ByteArray FifthMilestone::encryptData(ByteArray& data, Pkcs12& userP12)
{
    /**
     * TODO(milestone5)
     */
    ByteArray encryptedData;
    return encryptedData;
}

ByteArray FifthMilestone::decryptData(ByteArray& data, Pkcs12& userP12)
{
    /**
     * TODO(milestone5)
     */
    ByteArray decryptedData;
    return decryptedData;
}
