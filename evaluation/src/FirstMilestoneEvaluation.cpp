#ifndef FIRST_EVAL_H
#define FIRST_EVAL_H


#include "gtest.h"
#include "milestones/FirstMilestone.h"

TEST(FirstMilestoneEvaluation, ReadFile)
{
	ByteArray file = FileIo::readFile("files/OldMan.txt");
    if (file.size() <= 0) {
        FAIL() << "No file was read.";
    }
    EXPECT_STRCASEEQ("It's dangerous to go alone, take this.", file.toString().c_str());
}

TEST(FirstMilestoneEvaluation, ReadFileException)
{
        EXPECT_THROW(FileIo::readFile("files/iDoNotExist.txt"), IoException);
}

TEST(FirstMilestoneEvaluation, Sha1HashEvaluation)
{
	const char * expectedString = "81ae029ac1c49ef2af207a140be97dc452a944f9";

	ByteArray expected(expectedString);
	FirstMilestone fm;
	EXPECT_STRCASEEQ(expectedString, fm.computeHash().toHex().c_str());
}

#endif /*FIRST_EVAL_H*/
