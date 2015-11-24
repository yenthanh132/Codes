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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct StringsNightmareAgain {
	long long UniqueSubstrings(int a, int b, int c, int d, int n) {
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int n                     = 4;
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 2;
			int b                     = 3;
			int c                     = 1;
			int d                     = 1;
			int n                     = 6;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 4;
			int b                     = 3;
			int c                     = 1;
			int d                     = 1;
			int n                     = 6;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 4;
			int b                     = 3;
			int c                     = 3;
			int d                     = 3;
			int n                     = 10;
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 5;
			int b                     = 3;
			int c                     = 2;
			int d                     = 3;
			int n                     = 11;
			long long expected__      = 9;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int a                     = 10;
			int b                     = 1000000;
			int c                     = 1000000;
			int d                     = 1;
			int n                     = 51;
			long long expected__      = 63;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int n                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int n                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int n                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = StringsNightmareAgain().UniqueSubstrings(a, b, c, d, n);
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
