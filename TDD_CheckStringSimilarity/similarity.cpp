#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getSimilarity(const string& s1, const string& s2) {
		if (s1.length() == s2.length())
			return 60;
		return 0;
	}
};