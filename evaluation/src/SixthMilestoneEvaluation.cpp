#include <libcryptosec/Pkcs12Factory.h>

#include "gtest.h"
#include "milestones/SixthMilestone.h"
#include "utils/FileIo.h"
#include "utils/macros.h"
#include "utils/trace.h"
#include "utils/paths.h"

class SixthMilestoneEvaluation : public ::testing::Test {

protected:



	static SixthMilestone* sm;
	static Pkcs12 *user;
    static ByteArray* data;

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

SixthMilestone* SixthMilestoneEvaluation::sm = NULL;
Pkcs12* SixthMilestoneEvaluation::user = NULL;
ByteArray* SixthMilestoneEvaluation::data = NULL;



TEST_F(SixthMilestoneEvaluation, SomeTest)
{
    FAIL() << NOT_IMPLEMENTED;
}

TEST_F(SixthMilestoneEvaluation, SomeOtherTest)
{
    FAIL() << NOT_IMPLEMENTED;
}
