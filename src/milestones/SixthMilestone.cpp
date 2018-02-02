#include "milestones/SixthMilestone.h"

SixthMilestone::SixthMilestone()
{
	/**
     * Like any other C++ code,
     * this one needs little hack.
     */
	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
}

SixthMilestone::~SixthMilestone() {}

ByteArray SixthMilestone::sign(ByteArray& data, Pkcs12& userP12)
{
    /**
     * TODO(milestone6)
     */
    ByteArray signature;
    return signature;
}

bool SixthMilestone::verifySignature(ByteArray& data, ByteArray& signature,
        Pkcs12& userP12)
{
    /**
     * TODO(milestone6)
     */
    return false;
}
