#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getSimilarity(const string& str1, const string& str2) {

		return getLengthScore(str1, str2) + getCharScore(str1, str2);
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

	int getCharScore(const string& str1, const string& str2) {
		if (!checkStringValid(str1) || !checkStringValid(str2))
			return 0;

		setUsedAlphabet(str1, 0);
		setUsedAlphabet(str2, 1);

		checkAlphabetCount();

		return calculateAlphabetScore();
	}

private:
	// Length Score
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


	// Alphabet Score
	bool checkStringValid(const string& str) {
		for (char ch : str) {
			if (!isCapital(ch))
				return false;
		}
		return true;
	}
	bool isCapital(char ch) {
		return (ch >= 'A' && ch <= 'Z');
	}
	void setUsedAlphabet(const string& str, int stringNum) {
		for (char ch : str) {
			isAlphabetUsed[ch - 'A'][stringNum] = true;
		}
	}
	void checkAlphabetCount() {
		for (int i = 0; i < MAX_ALPHABET_COUNT; i++) {
			if (isAlphabetUsed[i][0] || isAlphabetUsed[i][1])
				totalCount++;
			if (isAlphabetUsed[i][0] && isAlphabetUsed[i][1])
				sameCount++;
		}
	}
	int calculateAlphabetScore() {
		return (40 * sameCount) / totalCount;
	}



private:
	static const int MAX_ALPHABET_COUNT = 26;
	bool isAlphabetUsed[MAX_ALPHABET_COUNT][2] = { { false } };
	int totalCount = 0;
	int sameCount = 0;
};

