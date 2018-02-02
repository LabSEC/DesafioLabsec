#include <libcryptosec/Pkcs12Factory.h>

#include "gtest.h"
#include "milestones/FifthMilestone.h"
#include "utils/FileIo.h"
#include "utils/macros.h"
#include "utils/trace.h"

class FifthMilestoneEvaluation : public ::testing::Test {

protected:

    static FifthMilestone* fm;
    static Pkcs12* user;
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

FifthMilestone* FifthMilestoneEvaluation::fm = NULL;
Pkcs12* FifthMilestoneEvaluation::user = NULL;
ByteArray* FifthMilestoneEvaluation::data = NULL;



TEST_F(FifthMilestoneEvaluation, SomeTest)
{
    FAIL() << NOT_IMPLEMENTED;
}

TEST_F(FifthMilestoneEvaluation, SomeOtherTest)
{
    FAIL() << NOT_IMPLEMENTED;
}
