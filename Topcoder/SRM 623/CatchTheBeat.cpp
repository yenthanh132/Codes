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

const int maxn=500007;

struct pnt{
        int x,y,X,Y;
    }a[maxn];
int BIT[maxn],n;
vector<int> ylist;

bool cmp(pnt a, pnt b){
    return a.X<b.X || (a.X==b.X && a.Y<b.Y);
}

struct CatchTheBeat {



    void update(int p, int v){
        for(;p<=n;p+=p&(-p)) BIT[p]=max(BIT[p],v);
    }

    int get(int p){
        int res=0;
        for(;p; p-=p&(-p)) res=max(res,BIT[p]);
        return res;
    }



	int maxCatched(int _n, int x0, int y0, int A, int B, int C, int D, int mod1, int mod2, int offset) {
        n=_n;
        a[1].x=x0; a[1].y=y0;
        FOR(i,2,n){
            a[i].x=(1ll*a[i-1].x*A+B)%mod1;
            a[i].y=(1ll*a[i-1].y*C+D)%mod2;
        }
        a[++n].x=offset;
        a[n].y=0;
        ylist.clear();
        reset(BIT,0);
        FOR(i,1,n){
            a[i].x-=offset;
            a[i].X=a[i].x+a[i].y;
            a[i].Y=a[i].y-a[i].x;
            ylist.pb(a[i].Y);
        }
        sort(ylist.begin(),ylist.end());
        ylist.resize(unique(ylist.begin(),ylist.end())-ylist.begin());
        FOR(i,1,n) a[i].Y=lower_bound(ylist.begin(),ylist.end(),a[i].Y)-ylist.begin()+1;
        int res=0,val;
        sort(a+1,a+n+1,cmp);
        FOR(i,1,n){
            val=get(a[i].Y);
            if(val>0 || a[i].x==0){
                res=max(res,val+1);
                update(a[i].Y,val+1);
            }
        }
        return res-1;
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
			int n                     = 3;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 100;
			int mod2                  = 100;
			int offset                = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		case 1: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 1234;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 999;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 100;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 3;
			int mod2                  = 58585858;
			int offset                = 1;
			int expected__            = 66;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 500000;
			int x0                    = 123456;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 0;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 0;
			int expected__            = 376544;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 500000;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1;
			int mod2                  = 1;
			int offset                = 0;
			int expected__            = 500000;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 10;
			int x0                    = 999999957;
			int y0                    = 79;
			int a                     = 993948167;
			int b                     = 24597383;
			int c                     = 212151897;
			int d                     = 999940854;
			int mod1                  = 999999986;
			int mod2                  = 999940855;
			int offset                = 3404;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CatchTheBeat().maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
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
