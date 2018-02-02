#include "gtest.h"
#include "milestones/ThirdMilestone.h"
#include "utils/macros.h"

class ThirdMilestoneEvaluation : public ::testing::Test {

protected:
	static ThirdMilestone* tm;
	static Certificate *root, *user;

	static void SetUpTestCase()
	{
		ByteArray rootKeyData = FileIo::readFile(paths::rootCaKeyPairPath);
		ByteArray userKeyData = FileIo::readFile(paths::userKeyPairPath);

        if (rootKeyData.size() <= 0) {
            FAIL()<< "You should implement FileIo::readFile first.";
        }

        KeyPair rootkp(rootKeyData);
        KeyPair userkp(userKeyData);

		ThirdMilestoneEvaluation::tm = new ThirdMilestone();

        ThirdMilestoneEvaluation::tm->createCertificates(rootkp, userkp);
        ByteArray aux = FileIo::readFile(paths::rootCaCertificatePath);
        ThirdMilestoneEvaluation::root = new Certificate(aux.toString());
        aux = FileIo::readFile(paths::userCertificatePath);
        ThirdMilestoneEvaluation::user = new Certificate(aux.toString());
    };

    static void TearDownTestCase()
    {
        if (ThirdMilestoneEvaluation::tm)
            delete ThirdMilestoneEvaluation::tm;
        if (ThirdMilestoneEvaluation::user)
            delete ThirdMilestoneEvaluation::user;
        if (ThirdMilestoneEvaluation::root)
            delete ThirdMilestoneEvaluation::root;

    }

    bool testStaticAtributes()
    {
        if (!ThirdMilestoneEvaluation::tm) {
            return true;
        }
        if (!ThirdMilestoneEvaluation::user) {
            return true;
        }
        if (!ThirdMilestoneEvaluation::root) {
            return true;
        }
        return false;
    }
};

ThirdMilestone* ThirdMilestoneEvaluation::tm = NULL;
Certificate* ThirdMilestoneEvaluation::root = NULL;
Certificate* ThirdMilestoneEvaluation::user = NULL;

TEST_F(ThirdMilestoneEvaluation, RootCaCertificateSubject)
{
    if(testStaticAtributes()) {
        FAIL() << "can't read or load instantiate certificates.";
    }
    EXPECT_STRCASEEQ(ThirdMilestoneEvaluation::tm->rootCaCommonName,
                     ThirdMilestoneEvaluation::root->getSubject().getEntries(RDNSequence::COMMON_NAME)
                     .at(0).c_str());
    EXPECT_EQ(ThirdMilestoneEvaluation::tm->rootCaSerial, root->getSerialNumber());
}

TEST_F(ThirdMilestoneEvaluation, RootCaCertificateIssuer)
{
    if(testStaticAtributes()) {
        FAIL() << "can't read or load instantiate certificates.";
    }
    EXPECT_STRCASEEQ(ThirdMilestoneEvaluation::root->getSubject().getXmlEncoded().c_str(),
                     ThirdMilestoneEvaluation::root->getIssuer().getXmlEncoded().c_str());
}

TEST_F(ThirdMilestoneEvaluation, UserCertificateSubject)
{
    if(testStaticAtributes()) {
        FAIL() << "can't read or load instantiate certificates.";
    }
    EXPECT_STRCASEEQ(ThirdMilestoneEvaluation::tm->commonName,
                     ThirdMilestoneEvaluation::user->getSubject().getEntries(RDNSequence::COMMON_NAME)
                     .at(0).c_str());
    EXPECT_EQ(ThirdMilestoneEvaluation::tm->serial, ThirdMilestoneEvaluation::user->getSerialNumber());
}

TEST_F(ThirdMilestoneEvaluation, UserCertificateIssuer)
{
    if(testStaticAtributes()) {
        FAIL() << "can't read or load instantiate certificates.";
    }
    EXPECT_STRCASEEQ(ThirdMilestoneEvaluation::tm->rootCaCommonName,
                     ThirdMilestoneEvaluation::user->getIssuer().getEntries(RDNSequence::COMMON_NAME)
                     .at(0).c_str());
}

TEST_F(ThirdMilestoneEvaluation, dateInterval)
    {
        if(testStaticAtributes()) {
            FAIL() << "can't read or load instantiate certificates.";
        }
        if (ThirdMilestoneEvaluation::user->getNotBefore() < ThirdMilestoneEvaluation::root->getNotBefore() )
            {
                FAIL() << "A certificate cannot be valid"
                    " before its issuer.";
            }
        else if (ThirdMilestoneEvaluation::user->getNotAfter() < ThirdMilestoneEvaluation::root->getNotBefore() )
            {
                FAIL() << "A certificate must expire within"
                    " the life cycle of its issuer.";
            }
        else if (ThirdMilestoneEvaluation::user->getNotBefore() > ThirdMilestoneEvaluation::root->getNotAfter() )
            {
                FAIL() << "A certificate cannot be valid"
                    " after its issuer.";
            }
        else if (ThirdMilestoneEvaluation::user->getNotAfter() > ThirdMilestoneEvaluation::root->getNotAfter() )
            {
                FAIL() << "A certificate cannot expire after"
                    " its issuer.";
            }
        else
            {
                SUCCEED();
            }
    }
