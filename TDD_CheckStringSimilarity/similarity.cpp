#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getSimilarity(const string& str1, const string& str2) {

		return getLengthScore(str1, str2);
	}

	int getLengthScore(const string& str1, const string& str2)
	{
		if (str1.length() == str2.length())
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

		if (longLength >= shortLength * 2)
			return 0;

		int gap = longLength - shortLength;
		return (60 - 60 * gap / shortLength);
	}
};