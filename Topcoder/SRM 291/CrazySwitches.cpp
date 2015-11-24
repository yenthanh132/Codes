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

int dis[16][1<<16];
int n,first,last;
pii myq[16 * (1<<16)];

struct CrazySwitches {

    int minimumActions( vector <int> a ) {
        n=sz(a);
        reset(dis,-1);
        dis[0][1]=0;
        myq[first=last=1]=pii(0,1);
        while(first<=last){
            int u=myq[first].first, state = myq[first].second; ++first;
            for(int v=0; v<n; ++v) if(u!=v && (state>>v&1) && dis[v][state]==-1){
                dis[v][state]=dis[u][state];
                myq[++last]=pii(v,state);
            }
            if(a[u]!=u){
                int newstate = state ^ (1<<a[u]);
                for(int v=0; v<n; ++v) if((newstate>>v&1) && dis[v][newstate]==-1){
                    dis[v][newstate]=dis[u][state]+(v!=u);
                    myq[++last]=pii(v,newstate);
                }
            }
        }
        return dis[n-1][1<<(n-1)];
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
			int switches[]            = {1, 0};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int switches[]            = {0, 1};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int switches[]            = {1, 2, 0};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int switches[]            = {4, 4, 3, 0, 5, 2};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int switches[]            = {7, 11, 1, 12, 6, 3, 0, 2, 6, 0, 0, 5, 9};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int switches[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int switches[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int switches[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CrazySwitches().minimumActions(vector <int>(switches, switches + (sizeof switches / sizeof switches[0])));
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
