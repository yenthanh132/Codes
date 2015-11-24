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

struct GreaterGame {

    int n;
    int mark[107],check[107];
    vector<int> ds,ds2;

    double calc( vector <int> hand, vector <int> sothe ) {
        n=sz(hand);
        reset(mark,0); reset(check,0);
        for(int i=0; i<n; ++i) mark[hand[i]]=check[hand[i]]=1;
        double res=0;
        int c=0;
        for(int i=0; i<n; ++i){
            int v=sothe[i];
            if(v==-1) ++c;
            else{
                check[v]=1;
                int x=v+1;
                while(x<=n*2 && !mark[x]) ++x;
                if(mark[x]){
                    ++res;
                    mark[x]=0;
                }
            }
        }
        ds.clear(); ds2.clear();

        for(int v=n*2, t=c; v>=1 && t>0; --v) if(mark[v]){
            --t;
            ds.pb(v);
        }

        for(int v=1; v<=n*2; ++v) if(!check[v]) ds2.pb(v);

        for(int i=0; i<c; ++i){
            int v=ds[i];
            double dem=0;
            for(int j=0; j<c; ++j) if(ds2[j]<v) dem+=1;
            res += dem/c;
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
			int hand[]                = {3,4};
			int sothe[]               = {-1,-1};
			double expected__         = 1.5;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hand[]                = {4,2};
			int sothe[]               = {1,3};
			double expected__         = 2.0;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hand[]                = {2};
			int sothe[]               = {-1};
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hand[]                = {1,3,5,7};
			int sothe[]               = {8,-1,4,-1};
			double expected__         = 2.5;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int hand[]                = {6,12,17,14,20,8,16,7,2,15};
			int sothe[]               = {-1,-1,4,-1,11,3,13,-1,-1,18};
			double expected__         = 8.0;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int hand[]                = ;
			int sothe[]               = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hand[]                = ;
			int sothe[]               = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int hand[]                = ;
			int sothe[]               = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = GreaterGame().calc(vector <int>(hand, hand + (sizeof hand / sizeof hand[0])), vector <int>(sothe, sothe + (sizeof sothe / sizeof sothe[0])));
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
