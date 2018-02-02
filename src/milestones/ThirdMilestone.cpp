#include "milestones/ThirdMilestone.h"

ThirdMilestone::~ThirdMilestone() {}

void ThirdMilestone::setCommonName(CertificateBuilder& builder,
	const char* cn)
{
	RDNSequence subject;
	subject.addEntry(RDNSequence::COMMON_NAME, cn);
	builder.setSubject(subject);
}

void ThirdMilestone::createCertificates(KeyPair& rootCaKeyPair,
	KeyPair& userKeyPair)
{
	/**
     * TODO(milestone3):
     * - create Root Ca Self Signed Certificate;
     * - create your certificate issued and signed by Root CA.
     * You are allowed to create new functions to keep your code clean.
     */
    TRACE(NOT_IMPLEMENTED);
}
