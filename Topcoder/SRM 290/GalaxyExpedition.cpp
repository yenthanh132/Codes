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

const int maxn=57;

struct GalaxyExpedition {
    vector<int> e[maxn];
    int n,cnt;
    bool mark[maxn],len[maxn];

    void dfs(int u){
        mark[u]=0;
        ++cnt;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(mark[v]) dfs(v);
        }
    }

    vector <int> possibleValues( vector <string> dependencies ) {
        n=sz(dependencies);
        for(int i=0; i<n; ++i){
            stringstream ss;
            ss<<dependencies[i];
            int j;
            while(ss>>j){
                e[i].pb(j);
            }
        }
        reset(len,0);
        len[0]=1;
        for(int i=0; i<n; ++i){
            reset(mark,1);
            cnt=0;
            dfs(i);
            for(int v=n-cnt; v>=0; --v) if(len[v]) len[v+cnt]=1;
        }

        vector<int> res;
        for(int i=1; i<=n; ++i) if(len[i]) res.pb(i);
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

	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) {
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
			string dependencies[]     = {"1 2","0 2","3",""};
			int expected__[]          = {1, 2, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string dependencies[]     = {"1","2","0"};
			int expected__[]          = {3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string dependencies[]     = {"1","0","3","2"};
			int expected__[]          = {2, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string dependencies[]     = {"","2 0","0 1","0 4","3 0"};
			int expected__[]          = {1, 3, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string dependencies[]     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string dependencies[]     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string dependencies[]     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = GalaxyExpedition().possibleValues(vector <string>(dependencies, dependencies + (sizeof dependencies / sizeof dependencies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
