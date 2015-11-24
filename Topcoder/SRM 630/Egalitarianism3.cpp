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

const int maxn=56;

struct Egalitarianism3 {

    int d[maxn][maxn];
    vector<int> list;

    int maxCities( int n, vector <int> a, vector <int> b, vector <int> len ) {
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) d[i][j]=(i==j?0:oo);
        for(int i=0; i<n-1; ++i) d[a[i]][b[i]]=d[b[i]][a[i]]=len[i];
        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        int res = min(2,n);
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
            int dis = d[i][j];
            list.clear();
            list.pb(i); list.pb(j);
            for(int k=j+1; k<=n; ++k){
                bool ok=1;
                for(int x=0; x<sz(list); ++x) if(d[list[x]][k]!=dis){
                    ok=0;
                    break;
                }
                if(ok) list.pb(k);
            }
            res=max(res,sz(list));
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
			int n                     = 4;
			int a[]                   = {1,1,1};
			int b[]                   = {2,3,4};
			int len[]                 = {1,1,1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 6;
			int a[]                   = {1,2,3,2,3};
			int b[]                   = {2,3,4,5,6};
			int len[]                 = {2,1,3,2,3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 10;
			int a[]                   = {1,1,1,1,1,1,1,1,1};
			int b[]                   = {2,3,4,5,6,7,8,9,10};
			int len[]                 = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 1;
			int a[]                   = {};
			int b[]                   = {};
			int len[]                 = {};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int len[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int len[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int len[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Egalitarianism3().maxCities(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(len, len + (sizeof len / sizeof len[0])));
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
