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

struct UniformBoard {
    int n,s[55][55],c;
    bool found;

    int val(char ch){
        if(ch=='.') return 1;
        if(ch=='P') return 2;
        return 0;
    }

	int getBoard(vector <string> a, int K) {
        found=0;
        c=0;
        n=sz(a);
        REP(i,n) REP(j,n){
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+val(a[i][j]);
            if(a[i][j]=='A') ++c;
            if(a[i][j]=='.') found=1;
        }
        int res=0;
        FOR(x1,1,n) FOR(y1,1,n) FOR(x2,x1,n) FOR(y2,y1,n){
            int v=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
            if(v!=0 && !found) continue;
            if((x2-x1+1)*(y2-y1+1)>c) continue;
            if(v<=K) res=max(res,(x2-x1+1)*(y2-y1+1));

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
//		case 0: {
//			string board[]            = {"AP",
// ".A"};
//			int K                     = 0;
//			int expected__            = 1;
//
//			std::clock_t start__      = std::clock();
//			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 1: {
//			string board[]            = {"AP",
// ".A"};
//			int K                     = 1;
//			int expected__            = 2;
//
//			std::clock_t start__      = std::clock();
//			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 2: {
//			string board[]            = {"PPP",
// "APA",
// "A.P"};
//			int K                     = 2;
//			int expected__            = 3;
//
//			std::clock_t start__      = std::clock();
//			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 3: {
//			string board[]            = {"AAA",
// "PPP",
// "AAA"};
//			int K                     = 10;
//			int expected__            = 3;
//
//			std::clock_t start__      = std::clock();
//			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 4: {
//			string board[]            = {"."};
//			int K                     = 1000;
//			int expected__            = 0;
//
//			std::clock_t start__      = std::clock();
//			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
		case 5: {
			string board[]            = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"};
			int K                     = 10;
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
