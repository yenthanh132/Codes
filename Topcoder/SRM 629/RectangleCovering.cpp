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

struct RectangleCovering {

    int minimumNumber( int H, int W, vector <int> h, vector <int> w ) {
        vector<int> arr;
        int n = sz(h);
        int res = oo,sum;
        //try h
        arr.clear();
        for(int i=0; i<n; ++i) if(max(h[i],w[i])>H){
            if(min(h[i],w[i]) > H ) arr.pb(max(h[i],w[i]));
            else arr.pb(min(h[i],w[i]));
        }
        sort(arr.begin(),arr.end(),greater<int>());
        sum=0;
        for(int i=0; i<sz(arr); ++i){
            sum+=arr[i];
            if(sum>=W) res=min(res,i+1);
        }

        //try w
        arr.clear();
        for(int i=0; i<n; ++i) if(max(h[i],w[i])>W){
            if(min(h[i],w[i]) > W ) arr.pb(max(h[i],w[i]));
            else arr.pb(min(h[i],w[i]));
        }
        sort(arr.begin(),arr.end(),greater<int>());
        sum=0;
        for(int i=0; i<sz(arr); ++i){
            sum+=arr[i];
            if(sum>=H) res=min(res,i+1);
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
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {8,8,8};
			int boardW[]              = {2,3,4};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int holeH                 = 10;
			int holeW                 = 10;
			int boardH[]              = {6,6,6,6};
			int boardW[]              = {6,6,6,6};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {5};
			int boardW[]              = {5};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int holeH                 = 3;
			int holeW                 = 5;
			int boardH[]              = {6};
			int boardW[]              = {4};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int holeH                 = 10000;
			int holeW                 = 5000;
			int boardH[]              = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
			int boardW[]              = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
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
