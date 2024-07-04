#include "pch.h"
#include "../TDD_CheckStringSimilarity/similarity.cpp"

TEST(StringSimilarityTest, SameLength) {
	SimilarityChecker checker;
	int ret = checker.getLengthScore("ABC", "DEF");
	EXPECT_EQ(ret, 60);
}

TEST(StringSimilarityTest, TwoTimesLonger) {
	SimilarityChecker checker;
	int ret = checker.getLengthScore("ABC", "DEFGHI");
	EXPECT_EQ(ret, 0);
}

TEST(StringSimilarityTest, PartialScore) {
	SimilarityChecker checker;
	int ret = checker.getLengthScore("ABC", "DEFGH");
	EXPECT_EQ(ret, 20);
}

TEST(StringSimilarityTest, NotCapital) {
	SimilarityChecker checker;
	int ret = checker.getCharScore("ABC", "DEFGa");
	EXPECT_EQ(ret, 00);
}

