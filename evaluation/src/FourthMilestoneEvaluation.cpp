#include <libcryptosec/Pkcs12Factory.h>

#include "gtest.h"
#include "milestones/FourthMilestone.h"
#include "utils/macros.h"
#include "utils/trace.h"

class FourthMilestoneEvaluation : public ::testing::Test {

protected:


	static FourthMilestone* fm;
	static Pkcs12 *user, *root;

	static Pkcs12* readPkcs12(const char* path)
	{
		ByteArray der = FileIo::readFile(path);
		return Pkcs12Factory::fromDerEncoded(der);
	}

	static void SetUpTestCase()
	{
        TRACE(NOT_IMPLEMENTED);
    };

    static void TearDownTestCase()
    {
        TRACE(NOT_IMPLEMENTED);
    };

};

FourthMilestone* FourthMilestoneEvaluation::fm = NULL;
Pkcs12* FourthMilestoneEvaluation::user = NULL;
Pkcs12* FourthMilestoneEvaluation::root = NULL;



TEST_F(FourthMilestoneEvaluation, SomeTest)
{
    FAIL()<< NOT_IMPLEMENTED;
}

TEST_F(FourthMilestoneEvaluation, SomeOtherTest)
{
    FAIL()<< NOT_IMPLEMENTED;
}
