#include "pch.h"
#include "../TDD_CheckStringSimilarity/similarity.cpp"

TEST(TestCaseName, TestName) {
	SimilarityChecker checker;
	int ret = checker.getSimilarity("ABC", "DEF");
	EXPECT_EQ(ret, 60);
}