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

struct BuildingRoutes {
    vector<string> a;
    int n,f[55][55];

	int build(vector <string> dist, int T) {
        a=dist;
        n=sz(a);
        REP(i,n) REP(j,n) f[i][j]=a[i][j]-'0';
        REP(k,n) REP(i,n) REP(j,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        int res=0;
        REP(i,n) REP(j,n) if(i!=j){
            int c=0,w=a[i][j]-'0';
            REP(u,n) REP(v,n) if(u!=v && f[u][i]+w+f[j][v]==f[u][v]) ++c;
            if(c>=T) res+=w;
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
			string dist[]             = {"011",
 "101",
 "110"};
			int T                     = 1;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string dist[]             = {"033",
 "309",
 "390"};
			int T                     = 1;
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string dist[]             = {"0123",
 "1023",
 "1203",
 "1230"};
			int T                     = 2;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string dist[]             = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"};
			int T                     = 3;
			int expected__            = 40;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingRoutes().build(vector <string>(dist, dist + (sizeof dist / sizeof dist[0])), T);
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
