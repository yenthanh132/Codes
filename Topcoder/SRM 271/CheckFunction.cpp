#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
//0 consists of 6 dashes, 1 consists of 2 dashes, 2 consists of 5 dashes, 3 consists of 5 dashes, 4 consists of 4 dashes,
// 5 consists of 5 dashes, 6 consists of 6 dashes, 7 consists of 3 dashes, 8 consists of 7 dashes, 9 consists of 6 dashes.
int val[10] = {6,2,5,5,4,5,6,3,7,6};

struct CheckFunction {


    int newFunction( string code ) {
        int res=0;
        for(int i=0; i<sz(code); ++i) res+=val[code[i]-'0'];
        return res;
    }

};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string code               = "13579";
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string code               = "02468";
			int expected__            = 28;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string code               = "73254370932875002027963295052175";
			int expected__            = 157;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string code               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string code               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string code               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CheckFunction().newFunction(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
