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

typedef long long ll;
typedef pair<ll,ll> pii;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

void refine(pii &a){
    ll g=gcd(a.first,a.second);
    a.first /= g;
    a.second /= g;
}

const int maxn=1007;

map<pii,ll> BIT[maxn];

void update(int i, pii p){
    for( ; i; i-=i&(-i)) ++BIT[i][p];
}

ll get(int i, pii p, int n){
    ll res=0;
    for( ; i<=n; i+=i&(-i))
        if(BIT[i].count(p)) res+=BIT[i][p];
    return res;
}

struct BearDarts {
    int n;

    long long count( vector <int> w ) {
        n=sz(w);
        for(int i=1; i<=n; ++i) BIT[i].clear();
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
            pii p=pii(w[j-1],w[i-1]);
            refine(p);
            update(i,p);
        }
        ll res=0;
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
            pii p=pii(w[i-1],w[j-1]);
            refine(p);
            res += get(j+1, p, n);
        }
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
			int w[]                   = {6,8,4,3,6};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w[]                   = {3,4,12,1};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w[]                   = {42,1000000,1000000,42,1000000,1000000};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w[]                   = {1,1,1,1,1};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int w[]                   = {1,2,3,4,5,6,5,4,3,2,1};
			long long expected__      = 22;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int w[]                   = {33554432, 33554432, 67108864, 134217728};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int w[]                   = {6,1,1,6};
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int w[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int w[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
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
