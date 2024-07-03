#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getSimilarity(const string& str1, const string& str2) {
		if (str1.length() == str2.length())
			return 60;
		return 0;
	}
};