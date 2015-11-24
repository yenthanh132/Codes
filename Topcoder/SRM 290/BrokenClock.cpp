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

struct BrokenClock {

    int fewestClicks( string x, string y ) {
        int h1,h2,m1,m2;
        h1=(x[0]-'0')*10+(x[1]-'0');
        m1=(x[3]-'0')*10+(x[4]-'0');
        h2=(y[0]-'0')*10+(y[1]-'0');
        m2=(y[3]-'0')*10+(y[4]-'0');
        int res = (h2-h1+24)%24;
        m1=(m1+res)%60;
        res += (m2-m1+60)%60;
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
			string clockTime          = "03:12";
			string currentTime        = "04:15";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string clockTime          = "07:07";
			string currentTime        = "13:21";
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string clockTime          = "14:55";
			string currentTime        = "14:05";
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string clockTime          = "23:14";
			string currentTime        = "00:20";
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string clockTime          = "18:43";
			string currentTime        = "18:43";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string clockTime          = ;
			string currentTime        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string clockTime          = ;
			string currentTime        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string clockTime          = ;
			string currentTime        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BrokenClock().fewestClicks(clockTime, currentTime);
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
