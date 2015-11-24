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

pii p[407];
int cnt,m,n;
double C[407][407];

struct ClosestRabbit {



    ll dis(int x1, int y1, int x2, int y2){
        ll a=x1-x2, b=y1-y2;
        return a*a+b*b;
    }

    double getExpected( vector <string> a, int r ) {
        cnt=0;
        m=sz(a); n=sz(a[0]);
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(a[i][j]=='.') p[++cnt]=pii(i,j);
        double res = 0;
        C[0][0]=1;
        for(int i=1; i<=400; ++i){
            C[i][0]=1;
            for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
        double val0 = 1.0*r*(r-1) / (cnt*(cnt-1));
        for(int i=1; i<cnt; ++i) for(int j=i+1; j<=cnt; ++j){
            int x1=p[i].first, y1=p[i].second;
            int x2=p[j].first, y2=p[j].second;
            int d=0;
            for(int k=1; k<=cnt; ++k) if(k!=i && k!=j){
                int x3=p[k].first, y3=p[k].second;
                int tmp = 1;
                if(dis(x1,y1,x3,y3) < dis(x1,y1,x2,y2) || (dis(x1,y1,x3,y3) == dis(x1,y1,x2,y2) && pii(x3,y3) < pii(x2,y2))) tmp=0;
                if(dis(x2,y2,x3,y3) < dis(x1,y1,x2,y2) || (dis(x2,y2,x3,y3) == dis(x1,y1,x2,y2) && pii(x3,y3) < pii(x1,y1))) tmp=0;
                d+=tmp;
            }
            double val = val0;
            val = val*C[d][r-2]/C[cnt-2][r-2];
            res += val;
        }
        return res;
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
			string board[]            = {".#.#."};
			int r                     = 2;
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"..###.",
 ".###.#"};
			int r                     = 4;
			double expected__         = 1.6;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"..###.",
 ".###.#"};
			int r                     = 5;
			double expected__         = 2.0;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {".....",
 "#...."};
			int r                     = 4;
			double expected__         = 1.253968253968254;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".#####.#####..#....#",
 "#......#....#.##..##",
 ".####..#####..#.##.#",
 ".....#.#...#..#....#",
 "#####..#....#.#....#"};
			int r                     = 19;
			double expected__         = 5.77311527122319;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int r                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int r                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int r                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ClosestRabbit().getExpected(vector <string>(board, board + (sizeof board / sizeof board[0])), r);
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
