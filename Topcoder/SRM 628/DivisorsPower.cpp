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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct DivisorsPower {

    ll mypow(ll base, int n){
        if(n==0) return 1;
        ll t=mypow(base,n/2);
        if(t==oo) return oo;
        if((t*t)/t!=t) return oo;
        t=t*t;
        if(n&1){
            if((t*base)/base!=t) return oo;
            return t*base;
        }
        return t;
    }

    ll getsqr(ll n, ll k){
        ll l=1, r=1000000000, mid;
        while(l<=r){
            mid=(l+r)/2;
            ll v=mypow(mid,k);
            if(v==n) return mid;
            if(v>n) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }

    int countdiv(ll n){
        int res=0;
        for(ll i=1; i*i<=n; ++i) if(n%i==0){
            res++;
            if(i*i!=n) ++res;
        }
        return res;
    }



	long long findArgument(long long n) {
        ll num = pow((long double)n,(long double)1.0/2);
        cout<<num<<endl;
        if(n==1) return 1;
        ll res=oo;
        for(int k=2; k<=100; ++k){
            ll val=getsqr(n,k);
            if(val!=-1){
                if(countdiv(val)==k) res=min(res,val);
            }
        }
        if(res==oo) res=-1;
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
			long long n               = 100000007ll*100000007ll;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 10;
			long long expected__      = -1;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 64;
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 10000;
			long long expected__      = 10;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long n               = 2498388559757689LL;
			long long expected__      = 49983883;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = DivisorsPower().findArgument(n);
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
