#include "pch.h"
#include "../TDD_CheckStringSimilarity/similarity.cpp"

TEST(StringSimilarityTest, SameLength) {
	SimilarityChecker checker;
	int ret = checker.getSimilarity("ABC", "DEF");
	EXPECT_EQ(ret, 60);
}

TEST(StringSimilarityTest, TwoTimesLonger) {
	SimilarityChecker checker;
	int ret = checker.getSimilarity("ABC", "DEFGHI");
	EXPECT_EQ(ret, 0);
}

TEST(StringSimilarityTest, PartialScore) {
	SimilarityChecker checker;
	int ret = checker.getSimilarity("ABC", "DEFGH");
	EXPECT_EQ(ret, 20);
}

