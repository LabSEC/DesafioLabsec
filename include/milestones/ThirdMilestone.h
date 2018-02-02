#ifndef THIRDMILESTONE_H
#define THIRDMILESTONE_H

#include <libcryptosec/certificate/CertificateBuilder.h>
#include <libcryptosec/KeyPair.h>

#include "utils/FileIo.h"
#include "utils/trace.h"
#include "utils/paths.h"
#include "utils/macros.h"

/**
 * @brief <b> Third Milestone - x.509 Certificates</b><p>
 *
 * From now on, milestones may get harder. For this milestone,
 * you will create two Certificates. The first one for the
 * Root Certification Authority and the second is for yourself.
 * The Root CA's certificate is <b>self signed</b>, meaning it
 * will use its own Private Key to sign its certificate. Your
 * certificate will be signed by the Root CA's Private Key as
 * well. You should read about Public Key Infrastructure to
 * better understand about this next task. <p>
 *
 * - Define <b>serial</b> and <b>commonName</b> variables as
 *   instructed below;<br>
 * - Implement the <b>setCommonName</b> function using
 *   RNDSequence;<br>
 * - Implement the <b>createCertificates</b> function;<br>
 * - Use <b>CertificateBuilder</b> from Libcryptosec to build
 *   and sign the certificates;<br>
 * - Write both certificates to file using PEM format;<br>
 *   -paths::userCertificatePath;<br>
 *   -paths::rootCaCertificatePath;<br>
 * - Certificates must have Subject, Issuer, Serial,
 *   NotBefore, NotAfter and a public key.<p>
 *
 * Tips:
 * The <b>Subject</b> of a x.509 certificate is a sequence of
 * fields {Common Name, Country, Organization, ...}. For this
 * milestone, you need only to add the Common Name entry to
 * the data structure (RDNSequence). <br>
 *
 * The <b>Issuer</b> of a certificate is the subject of the
 * certificate used to sign it. For a ROOT Certification
 * Authority, the issuer is its own subject. For you certificate,
 * the issuer will be the subject of the Root CA.<br>
 *
 * The <b>NotBefore</b> and <b>NotAfter</b> fields are used to
 * determine whetheri the certificate is valid or not.<p>
 *
 * @see libcryptosec/RDNSequence
 * @see libcryptosec/CertificateBuilder
 * @see libcryptosec/KeyPair
 *
 * <b>SELF EVALUATION</b> (Requires previous milstones to run)<br>
 * In evaluation folder run '$make third'.<p>
 *
 * @author {Lucas Perin}
 */
class ThirdMilestone {

public:

	virtual ~ThirdMilestone();

	/**
 	* TODO define serial as your enrollment number.
 	*/
	const long serial = 12345678;

	/**
 	* TODO define commonName as you name.
 	*/
	const char* commonName = "yourName";

	/**
 	* TODO Implement this function in the cpp file.
 	*/
	void setCommonName(CertificateBuilder& builder,
		const char* cn);

	/**
 	* TODO Implement this function in the cpp file.
 	*/
	void createCertificates(KeyPair& rootCaKeyPair,
		KeyPair& userKeyPair);

	/**
 	* Root CA subject.
 	*/
	const long rootCaSerial = 1;
	const char* rootCaCommonName = "ROOT-CA";

	/**
 	* UTCtime to use for NotBefore and NotAfter.
 	* (YYMMDDHHMMSSZ)
	*/
	const std::string time1 = "1501010000000";
	const std::string time2 = "1502010000000";
	const std::string time3 = "1602010000000";
	const std::string time4 = "2001010000000";


};
#endif /*THIRDMILESTONE_H*/
