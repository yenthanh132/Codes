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

struct Procrastination {

    vector<ll> save[11111];
    map<ll,int> mm;
    int idx;

    int getIdx(ll n){
        if(mm.count(n)) return mm[n];
        mm[n] = ++idx;
        save[idx].clear();
        for(ll i=2; i*i<=n; ++i) if(n%i==0){
            save[idx].pb(i);
            if(i*i!=n) save[idx].pb(n/i);
        }
        sort(save[idx].begin(),save[idx].end());
        return idx;
    }


    ll go(ll i, ll n){
        int pos=getIdx(n);
        int t=lower_bound(save[pos].begin(), save[pos].end(), i+1)-save[pos].begin();
        if(t<sz(save[pos])) return save[pos][t];
        return -1;
    }
    ll solve(ll n){
        idx=0;
        ll i=1;
        ll minv=n;
        ll maxv=n;
        while(1){
            ll x=go(i,n);
            ll y=go(i,n-1);
            if(x==-1 && y==-1) break;
            if(y==-1 || (x!=-1 && x<y)){
                i=x;
                ++n;
            }else{
                i=y;
                --n;
            }
            minv=min(minv,n);
            maxv=max(maxv,n);
        }
        return n;
    }

    long long findFinalAssignee( long long n ) {
        return solve(n);
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
			long long n               = 3;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 8;
			long long expected__      = 11;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 20;
			long long expected__      = 20;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 196248;
			long long expected__      = 196259;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long n               = 5587021440LL;
			long long expected__      = 5587021440LL;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
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
