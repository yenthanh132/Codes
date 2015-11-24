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

const int maxn=2007;

vector<int> ds;
int n,val[maxn],pos[maxn];
vector<int> places, cutoff;

bool cmp(const int &i, const int &j){
    return cutoff[i]<cutoff[j];
}

struct StoryFromTCO {

    int minimumChanges( vector <int> _places, vector <int> _cutoff ) {
        n=sz(_places); ds.clear();
        places=_places; cutoff=_cutoff;
        for(int i=0; i<n; ++i) ds.pb(places[i]), ds.pb(cutoff[i]);
        sort(ds.begin(),ds.end());
        ds.resize(unique(ds.begin(),ds.end())-ds.begin());
        for(int i=0; i<n; ++i){
            places[i]=lower_bound(ds.begin(),ds.end(),places[i])-ds.begin()+1;
            cutoff[i]=lower_bound(ds.begin(),ds.end(),cutoff[i])-ds.begin()+1;

        }
        reset(val,0);
        for(int i=0; i<n; ++i) val[places[i]]++, val[cutoff[i]]--;
        for(int i=1; i<=2000; ++i){
            val[i]=val[i-1]+val[i];
            if(val[i]<0) return -1;
        }

        for(int i=0; i<n; ++i) pos[i]=i;
        sort(pos,pos+n,cmp);
        int res=0;
        for(int it=0; it<n; ++it){
            int i=pos[it];
            if(places[i]>cutoff[i]) continue;
            bool ok=1;
            for(int x=places[i]; x<cutoff[i]; ++x) if(val[x]==0){
                ok=0;
                break;
            }
            if(ok){
                ++res;
                for(int x=places[i]; x<cutoff[i]; ++x) val[x]--;
            }
        }
        return n-res;
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
			int places[]              = {20,100,500,50};
			int cutoff[]              = {7500,2250,150,24};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int places[]              = {5,4,3,2,1};
			int cutoff[]              = {5,4,3,2,1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int places[]              = {1,5,5,5};
			int cutoff[]              = {8,6,4,2};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int places[]              = {3,1,5};
			int cutoff[]              = {6,4,2};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int places[]              = {14,11,42,9,19};
			int cutoff[]              = {11,16,37,41,47} ;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int places[]              = {4,1,3,3,2,4,5,5,4,4};
			int cutoff[]              = {3,3,5,2,4,4,5,4,3,5};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int places[]              = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105, 53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2};
			int cutoff[]              = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440, 442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908};
			int expected__            = 23;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int places[]              = ;
			int cutoff[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int places[]              = ;
			int cutoff[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int places[]              = ;
			int cutoff[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
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
