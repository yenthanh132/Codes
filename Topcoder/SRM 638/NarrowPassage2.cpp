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

struct NarrowPassage2 {
    int n,m;
    vector<pii> ds,arr;
    int count( vector <int> a, int M ) {
        n=sz(a);
        m=M;
        for(int i=0; i<n; ++i) ds.pb(pii(a[i],i));
        sort(ds.begin(),ds.end(),greater<pii>());

        int res=1;

        arr.pb(pii(oo,-1)); arr.pb(pii(oo,n));
        for(int i=0; i<n; ++i){
            int j=0;
            while(arr[j].second<ds[i].second) ++j;
            arr.insert(arr.begin() + j, ds[i]);
            while(arr[j-1].first + ds[i].first <= M){
                --j;
            }
            int len=1;
//            for(int j=0; j<sz(arr); ++j) cout<<arr[j].first<<' '; cout<<endl;
            while(arr[j+1].first+ds[i].first<=M){
                ++j;
                ++len;

            }
            res=(1ll*res*len)%oo;
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
			int size[]                = {1, 2, 3};
			int maxSizeSum            = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int size[]                = {1, 2, 3};
			int maxSizeSum            = 1000;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int size[]                = {1, 2, 3};
			int maxSizeSum            = 4;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int size[]                = {1,1,1,1,1,1,1,1,1,1,1,1,1};
			int maxSizeSum            = 2;
			int expected__            = 227020758;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int size[]                = {2,4,6,1,3,5};
			int maxSizeSum            = 8;
			int expected__            = 60;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int size[]                = {1000000000};
			int maxSizeSum            = 1000000000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int size[]                = ;
			int maxSizeSum            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int size[]                = ;
			int maxSizeSum            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int size[]                = ;
			int maxSizeSum            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NarrowPassage2().count(vector <int>(size, size + (sizeof size / sizeof size[0])), maxSizeSum);
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
