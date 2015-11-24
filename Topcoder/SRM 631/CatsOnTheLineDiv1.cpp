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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;


const int maxn=1007;

pii a[maxn];
ll dp[maxn][maxn];
int n;

struct CatsOnTheLineDiv1 {




    int getNumber( vector <int> position, vector <int> count, int time ) {
        n=sz(position);
        for(int i=0; i<n; ++i) a[i+1]=pii(position[i],count[i]);
        sort(a+1,a+n+1);
        for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dp[i][j] = oo;
        dp[0][0]=-oo;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                ll left = dp[i-1][j];
                ll x = max(left+1,a[i].first-time);
                ll y = x + a[i].second - 1;
                if(y <= a[i].first + time) dp[i][j] = min(dp[i][j], y);
                if(x <= a[i].first + time) dp[i][j+1] = min(dp[i][j+1], x);
            }
            int k = i;
            while(k-1 > 0 && a[i].first - time <= a[k-1].first + time) --k;
            for(int j=0; j<=n; ++j){
                ll left = dp[k-1][j];
                ll x = max(left+1,a[i].first-time);
                if(x <= a[i].first + time) dp[i][j+1] = min(dp[i][j+1], left);
            }
        }

        for(int r=0; r<=n; ++r) if(dp[n][r]<oo) return r;
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
//		case 0: {
//			int position[]            = {0};
//			int count[]               = {7};
//			int time                  = 3;
//			int expected__            = 0;
//
//			std::clock_t start__      = std::clock();
//			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 1: {
//			int position[]            = {0};
//			int count[]               = {6};
//			int time                  = 2;
//			int expected__            = 1;
//
//			std::clock_t start__      = std::clock();
//			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 2: {
//			int position[]            = {4, 7, 47};
//			int count[]               = {4, 7, 4};
//			int time                  = 1;
//			int expected__            = 3;
//
//			std::clock_t start__      = std::clock();
//			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 3: {
//			int position[]            = {3, 0, 7, 10};
//			int count[]               = {3, 7, 4, 5};
//			int time                  = 2;
//			int expected__            = 2;
//
//			std::clock_t start__      = std::clock();
//			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
		case 4: {
			int position[]            = {-5, 0, 7};
			int count[]               = {47, 85, 10};
			int time                  = 6;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int position[]            = {-8, 12, -15, -20, 17, -5, 7, 10};
			int count[]               = {20, 10, 7, 9, 2, 8, 11, 10};
			int time                  = 2;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int position[]            = {1, 3, 5};
			int count[]               = {4, 3, 4};
			int time                  = 1;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int position[]            = ;
			int count[]               = ;
			int time                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int position[]            = ;
			int count[]               = ;
			int time                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatsOnTheLineDiv1().getNumber(vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(count, count + (sizeof count / sizeof count[0])), time);
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
