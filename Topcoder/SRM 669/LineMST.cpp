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

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

struct LineMST {

    ll dp[222][222];
    int L;
    ll get(int n, int l){
        if(dp[n][l]!=-1) return dp[n][l];
        if(n==1) return 1;
        if(l==0) return 0;
        ll &res = dp[n][l];
        res=get(n,l-1);
        for(int i=1; i<n; ++i)
            res = (res + get(i,l-1)*get(n-i,l)%oo * mypow(L-l+1, i*(n-i)-1) )%oo;
        return res;
    }

    int count( int N, int _L ) {
        L = _L;
        reset(dp,-1);
        ll res = get(N,L);
        for(int i=1; i<=N; ++i) res=res*i%oo;
        res=res*mypow(2,oo-2)%oo;
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
			int N                     = 3;
			int L                     = 2;
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int L                     = 10;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int L                     = 1;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 8;
			int L                     = 41;
			int expected__            = 655468587;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 200;
			int L                     = 200;
			int expected__            = 152699064;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LineMST().count(N, L);
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
