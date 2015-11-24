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

struct Snowflakes {

    vector<string> arr;
    int n;

    char get(int i, int j){
        if(i<n) i=n+(n-i)-1;
        if(j<n) j=n+(n-j)-1;
        i-=n; j-=n;
        if(i<j) swap(i,j);
        return arr[i][j];
    }

    vector <string> flareOut( vector <string> snowflake ) {
        arr=snowflake;
        n=sz(arr);
        vector<string> res;
        for(int i=0; i<n*2; ++i){
            string s="";
            for(int j=0; j<n*2; ++j) s+=get(i,j);
            res.pb(s);
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

	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) {
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
			string snowflake[]        = {".",
 "..",
 "*.*"};
			string expected__[]       = {"*.**.*", "......", "*....*", "*....*", "......", "*.**.*" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string snowflake[]        = {"*",
 "..",
 ".*.",
 ".**.",
 ".*.**"};
			string expected__[]       = {"**.*..*.**", "*.**..**.*", ".*.*..*.*.", "***....***", "....**....", "....**....", "***....***", ".*.*..*.*.", "*.**..**.*", "**.*..*.**" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string snowflake[]        = {".",
 "..",
 "***"};
			string expected__[]       = {"******", "*....*", "*....*", "*....*", "*....*", "******" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string snowflake[]        = {"*",
 ".*",
 "***"};
			string expected__[]       = {"******", "**..**", "*.**.*", "*.**.*", "**..**", "******" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string snowflake[]        = {".",
 "..",
 "***",
 "...."};
			string expected__[]       = {"........", ".******.", ".*....*.", ".*....*.", ".*....*.", ".*....*.", ".******.", "........" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string snowflake[]        = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string snowflake[]        = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string snowflake[]        = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
