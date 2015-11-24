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

struct SpeedTyper {


    string lettersToPractice( string a, vector <int> times ) {
        string s="";
        for(int i=0; i<sz(a); ++i){
            int v;
            if(i==0) v=times[i];
            else v=times[i]-times[i-1];
            if(v*sz(a)>times[sz(a)-1]) s+=a[i];
        }
        return s;
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

	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
			std::cerr << "    Received: \"" << received << "\"" << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string letters            = "dcab";
			int times[]               = {250, 300, 400, 800};
			string expected__         = "db";

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string letters            = "keyboard";
			int times[]               = {100,200,300,500,600,800,900,1200};
			string expected__         = "bad";

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string letters            = "rewq";
			int times[]               = {500, 1000, 1500, 4000};
			string expected__         = "q";

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string letters            = "abc";
			int times[]               = {2000, 4000, 6000};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string letters            = ;
			int times[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string letters            = ;
			int times[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letters            = ;
			int times[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SpeedTyper().lettersToPractice(letters, vector <int>(times, times + (sizeof times / sizeof times[0])));
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
