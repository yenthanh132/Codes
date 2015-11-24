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

struct ChocolateDividingEasy {

    int a[57][57];
    int posX[5],posY[5];
    int m,n;

    int getsum(int x1, int y1, int x2, int y2){
        return a[x2][y2]-a[x1][y2]-a[x2][y1]+a[x1][y1];
    }

    int findBest( vector <string> chocolate ) {
        m=sz(chocolate);
        n=sz(chocolate[0]);
        reset(a,0);
        for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j){
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+chocolate[i-1][j-1]-'0';
        }
        int res = 0;
        for(int x1=2; x1<m; ++x1) for(int y1=2; y1<n; ++y1)
            for(int x2=x1; x2<m; ++x2) for(int y2=y1; y2<n; ++y2){
                posX[0]=0; posX[1]=x1-1; posX[2]=x2; posX[3]=m;
                posY[0]=0; posY[1]=y1-1; posY[2]=y2; posY[3]=n;
                int val=oo;
                for(int i=1; i<=3; ++i) for(int j=1; j<=3; ++j) val=min(val,getsum(posX[i-1],posY[j-1],posX[i],posY[j]));
                res=max(res,val);
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
			string chocolate[]        = {
"9768",
"6767",
"5313"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string chocolate[]        = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string chocolate[]        = {
"012",
"345",
"678"
};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string chocolate[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string chocolate[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string chocolate[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
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
