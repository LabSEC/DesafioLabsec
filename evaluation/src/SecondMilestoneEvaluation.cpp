#include <stdio.h>

#include "gtest.h"
#include "milestones/SecondMilestone.h"

const char* peppy = "Never give up. Trust your istinct.";
const char* nintendo = "Everything not saved will be lost.";


TEST(SecondMilestoneEvaluation, WriteFile)
{
	const char* path = "files/nintendo.txt";
	std::remove(path);
	EXPECT_THROW(FileIo::readFile(path), IoException);

	ByteArray data(nintendo);
	FileIo::writeToFile(path, data);
    ByteArray readData = FileIo::readFile(path);
    if (readData.size() <= 0) {
        FAIL() << "You should implement FileIo readFile first.";
    }
    EXPECT_STRCASEEQ(nintendo, readData.toString().c_str());
}

TEST(SecondMilestoneEvaluation, WriteFileException)
{
    ByteArray data(peppy);
    EXPECT_THROW(FileIo::writeToFile("files/Peppy.txt", data), IoException);
}

TEST(SecondMilestoneEvaluation, writeKeyPairs)
{
    SecondMilestone sm;
    sm.generateKeyPairs();

    ByteArray usr = FileIo::readFile(paths::userKeyPairPath);
    if (usr.size() <= 0) {
        FAIL() << "You should implement FileIo readFile first.";
    }
    ByteArray ca = FileIo::readFile(paths::rootCaKeyPairPath);
    if (ca.size() <= 0) {
        FAIL() << "You should implement FileIo readFile first.";
    }
    KeyPair usrkp(usr);
    KeyPair cakp(ca);
    EXPECT_EQ(AsymmetricKey::RSA, usrkp.getAlgorithm());
    EXPECT_EQ(1024, usrkp.getSizeBits());
    EXPECT_EQ(AsymmetricKey::RSA, cakp.getAlgorithm());
    EXPECT_EQ(2048, cakp.getSizeBits());
}
