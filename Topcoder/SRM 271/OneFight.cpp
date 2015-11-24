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

struct OneFight {

    int n;
    int p[20];

    int monsterKilling( vector <int> life, vector <int> damage, int yourDamage ) {
        n=sz(life);
        for(int i=0; i<n; ++i) p[i]=i;
        int res=oo;
        do{
            int s=0,val=0;
            for(int i=n-1; i>=0; --i) s+=damage[p[i]];
            for(int i=0; i<n; ++i){
                int x=(life[p[i]]-1)/yourDamage+1;
                val+=x*s;
                s-=damage[p[i]];
            }
            res=min(res,val);
        }while(next_permutation(p,p+n));
        return res+1;
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
			int life[]                = {3};
			int damage[]              = {10};
			int yourDamage            = 2;
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int life[]                = {5,1};
			int damage[]              = {5,3};
			int yourDamage            = 3;
			int expected__            = 19;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int life[]                = {5,5,5,5,5,5,5,5,5,5};
			int damage[]              = {10,20,30,40,50,60,70,80,90,100};
			int yourDamage            = 100;
			int expected__            = 2201;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int life[]                = {6,34,21,79,31,5,8,23,9,100};
			int damage[]              = {1,65,95,32,48,9,3,13,100,4};
			int yourDamage            = 4;
			int expected__            = 6554;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int life[]                = ;
			int damage[]              = ;
			int yourDamage            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int life[]                = ;
			int damage[]              = ;
			int yourDamage            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int life[]                = ;
			int damage[]              = ;
			int yourDamage            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneFight().monsterKilling(vector <int>(life, life + (sizeof life / sizeof life[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])), yourDamage);
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
