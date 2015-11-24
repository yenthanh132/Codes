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

struct ShoppingSurveyDiv1 {

    bool check(int n, int k, vector<int> &s){
        int sum=0, maxv=0;
        for(int i=0; i<sz(s); ++i) sum+=s[i], maxv=max(maxv,s[i]);
        if(sum > n*(k-1)) return 0;
        if(maxv > n) return 0;
        return 1;
    }

    int minValue( int N, int K, vector <int> s ) {
        for(int r=0; r<=N; ++r){
            if(check(N-r,K,s)) return r;
            for(int i=0; i<sz(s); ++i){
                s[i]=max(s[i]-1,0);
            }
        }
        return -1;
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
			int N                     = 10;
			int K                     = 2;
			int s[]                   = {1, 2, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int K                     = 2;
			int s[]                   = {1, 2, 3};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 4;
			int K                     = 4;
			int s[]                   = {4, 4, 4, 2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 20;
			int K                     = 3;
			int s[]                   = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 4;
			int K                     = 2;
			int s[]                   = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 2;
			int K                     = 3;
			int s[]                   = {1, 1, 1, 2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int K                     = ;
			int s[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int s[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int K                     = ;
			int s[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoppingSurveyDiv1().minValue(N, K, vector <int>(s, s + (sizeof s / sizeof s[0])));
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
