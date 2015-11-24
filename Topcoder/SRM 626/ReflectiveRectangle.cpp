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

struct ReflectiveRectangle {
    ll mypow(ll base, ll n){
        if(n==0) return 1;
        ll t=mypow(base,n/2);
        t=t*t%oo;
        if(n&1) return t*base%oo;
        return t;
    }

    ll inv(ll n){
        return mypow(n,oo-2);
    }

    ll phi(ll n){
        ll res=n;
        for(int i=2; i*i<=n; ++i) if(n%i==0){
            res=res*(i-1)%oo * inv(i)%oo;
            while(n%i==0) n/=i;
        }
        if(n>1) res=res*(n-1)%oo * inv(n)%oo;
        return res;
    }

    ll inv_phi(ll n){
        ll res=1;
        for(int i=2; i*i<=n; ++i) if(n%i==0){
            res=res*(1-i)%oo;
            while(n%i==0) n/=i;
        }
        if(n>1) res=res*(1-n)%oo;
        return res;
    }

    ll cal(ll n){
        ll t1=n*n%oo * phi(n)%oo * inv(3)%oo;
        ll t2=n*inv_phi(n)%oo * inv(6)%oo;
        return (t1+t2+oo)%oo;
    }

	int findSum(int sideA, int sideB, int bounces) {
        if(bounces&1) return 0;
        ll sideA2=1ll*sideA*sideA%oo;
        ll sideB2=1ll*sideB*sideB%oo;
        ll res = cal(bounces+2) * (sideA2 + sideB2)%oo;
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
			int sideA                 = 3;
			int sideB                 = 4;
			int bounces               = 0;
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sideA                 = 3;
			int sideB                 = 3;
			int bounces               = 2;
			int expected__            = 180;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sideA                 = 13;
			int sideB                 = 17;
			int bounces               = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sideA                 = 59325;
			int sideB                 = 31785;
			int bounces               = 262142;
			int expected__            = 48032850;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sideA                 = 1000000;
			int sideB                 = 1000000;
			int bounces               = 1000000000;
			int expected__            = 145972110;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sideA                 = ;
			int sideB                 = ;
			int bounces               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sideA                 = ;
			int sideB                 = ;
			int bounces               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sideA                 = ;
			int sideB                 = ;
			int bounces               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReflectiveRectangle().findSum(sideA, sideB, bounces);
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
