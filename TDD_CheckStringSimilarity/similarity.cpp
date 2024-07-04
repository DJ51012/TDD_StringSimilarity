#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getSimilarity(const string& str1, const string& str2) {

		return getLengthScore(str1, str2);
	}

	int getLengthScore(const string& str1, const string& str2)
	{
		if (checkLengthSame(str1, str2))
			return 60;

		int longLength, shortLength;

		if (str1.length() > str2.length()) {
			longLength = str1.length();
			shortLength = str2.length();
		}
		else {
			longLength = str2.length();
			shortLength = str1.length();
		}

		if (checkMoreThanDoubleLength(longLength, shortLength))
			return 0;

		return calculateLengthScore(longLength, shortLength);
	}

	bool checkLengthSame(const string& str1, const string& str2)
	{
		return (str1.length() == str2.length());
	}
	bool checkMoreThanDoubleLength(int longLength, int shortLength)
	{
		return (longLength >= shortLength * 2);
	}
	int calculateLengthScore(int longLength, int shortLength)
	{
		int gap = longLength - shortLength;
		return (60 - 60 * gap / shortLength);
	}
};