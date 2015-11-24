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

const int maxn=2007;

double dp[maxn][maxn*2];
int n;
struct DoraemonPuzzleGame {

	double solve(vector <int> X, vector <int> Y, int m) {
        n=sz(X);

	}
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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

	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}

	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int X[]                   = {800};
			int Y[]                   = {200};
			int m                     = 2;
			double expected__         = 5.0;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {1,999,999};
			int Y[]                   = {999,1,1};
			int m                     = 3;
			double expected__         = 3.0;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {500,500};
			int Y[]                   = {500,500};
			int m                     = 3;
			double expected__         = 2.5;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {250,250,250,250};
			int Y[]                   = {250,250,250,250};
			int m                     = 5;
			double expected__         = 8.25;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {250,500,250};
			int Y[]                   = {500,250,500};
			int m                     = 5;
			double expected__         = 4.962962962962963;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int X[]                   = {600,900,800,500,900,200,400,100,800,300,900,300,800,700,800,600,800,900,400,100,100,700,600,100,500, 800,700,600,900,600,300,100,300,100,700,500,900,200,800,400,300,700,300,400,700,300,400,800,300,200};
			int Y[]                   = {400,100,200,500,100,800,600,900,200,700,100,700,200,300,200,400,200,100,600,900,900,300,400,900,500, 200,300,400,100,400,700,900,700,900,300,500,100,800,200,600,700,300,700,600,300,700,600,200,700,800};
			int m                     = 95;
			double expected__         = 119.33578280666175;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			int m                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X[]                   = ;
			int Y[]                   = ;
			int m                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int X[]                   = ;
			int Y[]                   = ;
			int m                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DoraemonPuzzleGame().solve(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), m);
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
