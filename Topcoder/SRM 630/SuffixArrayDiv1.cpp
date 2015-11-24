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
#define oo 1000000007ll


#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=57;

struct SuffixArrayDiv1 {
    int n;
    vector<int> sa;
    int pos[maxn],inc[maxn],ans[maxn];
//    ll dp[maxn][maxn];
//
//    ll cal(int m){
//        reset(dp,0);
//        dp[n][n+1]=1;
//        for(int i=n-1; i>=0; --i){
//            ll sum=dp[i+1][n+1];
//            for(int j=n; j>=1; --j){
//                dp[i][j]=min(sum,oo);
//                if(i+1<n && !inc[i+1]) dp[i][j]=min(oo,dp[i][j]+dp[i+1][j]);
//                sum=min(oo,sum+dp[i+1][j]);
//                if(sa[i]<=m && j!=ans[sa[i]]) dp[i][j]=0;
//            }
//        }
//        ll res=0;
//        for(int i=1; i<=n; ++i) res=min(oo,res+dp[0][i]);
//        return res;
//    }



    int minimalCharacters( vector <int> _SA ) {
        n=sz(_SA);
        sa=_SA;
        reset(pos,-1);
        for(int i=0; i<n; ++i) pos[sa[i]]=i;
        reset(inc,0);
        for(int i=1; i<n; ++i) if(pos[sa[i-1]+1] > pos[sa[i]+1]) inc[i]=1;

//        for(int i=0; i<n; ++i){
//            for(int v=1; v<=n; ++v){
//                ans[i]=v;
//                if(cal(i)>0) break;
//            }
//        }
        int res = 0;
        for(int i=0; i<n; ++i) res+=inc[i];
        return res + 1;
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
//			int SA[]                  = {3,0,1,2};
//			int expected__            = 2;
//
//			std::clock_t start__      = std::clock();
//			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 1: {
//			int SA[]                  = {3,2,1,0};
//			int expected__            = 1;
//
//			std::clock_t start__      = std::clock();
//			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 2: {
//			int SA[]                  = {0,1,2,3};
//			int expected__            = 2;
//
//			std::clock_t start__      = std::clock();
//			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 3: {
//			int SA[]                  = {7,4,8,6,1,5,2,9,3,0};
//			int expected__            = 4;
//
//			std::clock_t start__      = std::clock();
//			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
		case 4: {
			int SA[]                  = {14, 4, 11, 13, 21, 19, 5, 3, 0, 18, 15, 7, 17, 9, 10, 20, 8, 12, 1, 2, 16, 6};
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int SA[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int SA[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int SA[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuffixArrayDiv1().minimalCharacters(vector <int>(SA, SA + (sizeof SA / sizeof SA[0])));
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
