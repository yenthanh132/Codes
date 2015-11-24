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

const int maxn=57;

struct BlackWhitePlane {

    int n;
    int x[maxn],y[maxn],r[maxn],d[maxn];
    int deg[maxn];
    vector<int> e[maxn];
    int myq[maxn],first,last;

    double dis(int i, int j){
        return hypot(x[i]-x[j],y[i]-y[j]);
    }

    double area( vector <string> s ) {
        n=sz(s);
        for(int i=0; i<n; ++i){
            stringstream ss;
            ss<<s[i];
            ss>>x[i]>>y[i]>>r[i];
        }
        reset(deg,0);
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
            if(r[i]>r[j] && dis(i,j)<=r[i]){
                e[i].pb(j);
                ++deg[j];
            }

        double res=0;
        first=1; last=0;
        for(int i=0; i<n; ++i) if(deg[i]==0){
            myq[++last]=i;
            d[i]=0;
        }

        while(first<=last){
            int u=myq[first++];
            if(d[u]&1) res-=acos(-1)*r[u]*r[u];
            else res+=acos(-1)*r[u]*r[u];
            for(int i=0; i<sz(e[u]); ++i){
                int v=e[u][i];
                deg[v]--;
                if(deg[v]==0){
                    myq[++last]=v;
                    d[v]=d[u]+1;
                }
            }
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
			string circles[]          = {"1 1 1"};
			double expected__         = 3.141592653589793;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string circles[]          = {"4 3 1", "3 2 3", "8 1 1"};
			double expected__         = 28.274333882308138;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string circles[]          = {"15 15 4", "15 25 4", "25 25 4", "25 15 4", "25 25 100"};
			double expected__         = 31214.86460606818;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string circles[]          = {"2549 8482 11", "9175 5927 35", "2747 6177 93", "5512 8791 81", "4487 8456 60",
 "6899 610 77", "9716 2202 3", "9312 5625 79", "4020 9851 85", "1640 7179 54",
 "5761 4348 51","5917 3436 88","6547 386 33","182 7676 1","6329 4496 89"};
			double expected__         = 194250.95695676407;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string circles[]          = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string circles[]          = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string circles[]          = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = BlackWhitePlane().area(vector <string>(circles, circles + (sizeof circles / sizeof circles[0])));
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
