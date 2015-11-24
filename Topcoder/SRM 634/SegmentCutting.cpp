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

struct SegmentCutting {

    long long maxValue( vector <int> x, vector <int> y ) {

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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int x[]                   = {0,3};
			int y[]                   = {0,4};
			long long expected__      = 25;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0,1,1};
			int y[]                   = {0,1,0,1};
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-6, 3, -4};
			int y[]                   = {2, 0, 5};
			long long expected__      = 159;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 2,-2, 4,-4, 2,-2, 0};
			int y[]                   = {1, 2, 2, 4, 4, 6, 6, 5};
			long long expected__      = 430;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int y[]                   = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
			long long expected__      = 94640;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {-24,11,-235,49,13,-247,-575,80,35,29,1,-9,-1,-1,-27,-3,-20,13,-33,111, -36,30,-303,-645,-23,-5,393,227,89,145,6,515,234,271,-901,239,-368,-642, -3,125,-63,2,221,-113,1,6,3,-31,-6,-49,-785,314,363,-2,34,15,465,11,32, -72,394,20,-8,-448,429,-7,-88,-11,-42,-8,2,-707,-231,-143,76,-10,-152, -66,24,-73,778,-29,807,-63,722,-804,413,-21,-2,-131,26,3,-23,101,-551, -58,21,180,-15,-88,410,604,74,956,62,275,-352,-93,291,184,70,564,-594, -101,-391,18,115,-329,8,-4,-218,77,218,-145,27,-34,598,-87,-243,-323,34, 211,7,-145,-49,528,-13,10,-778,184,-65,101,-232,503,-6,69,553,-14,25,26, 854,955,-10,-490,-674,-4,9,-373,42,-121,-528,67,-32,23,74,81,-752,-7, -122,-464,-174,-722,46,961,57,-105,269,48,64,-585,-107,641,9,27,297,5, -44,107,-600,113,468,-24,-104,277,10,5,75,106,-591,38};
			int y[]                   = {-1,-2,62,-8,-1,28,-47,241,-10,-3,3,-41,1,95,111,-4,-114,503,1,19,3, -26,615,762,7,-52,399,-174,-987,30,-49,165,67,551,-214,-36,-108,-242, -967,69,698,-120,-298,20,-43,32,-171,2,-9,8,50,948,-2,-30,-3,53,-411, 410,141,-8,292,41,71,-523,-329,-284,8,84,34,559,-160,2,73,12,276,-16, -33,-63,119,869,127,47,963,-7,-995,146,-161,775,17,-5,-167,-315,59, -345,10,766,-10,-6,850,12,-5,-17,295,-89,14,71,-11,-305,13,-524,181, -279,-11,15,437,349,20,10,-749,82,25,336,-6,-794,-944,895,-52,72,198, 194,-988,641,-59,-434,-524,-381,368,6,-14,125,-55,319,-666,-610,-274, 359,-39,206,28,-719,-150,51,-366,-341,89,13,-635,-287,56,35,665,103,-81, 156,-4,888,-48,96,-48,340,61,396,272,-16,335,219,-388,15,324,24,-194,9, -310,7,-25,5,39,-342,118,-92,425,-336,796,950,-419,-812,-488,428,-32,-9};
			long long expected__      = 5887914054LL;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SegmentCutting().maxValue(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
