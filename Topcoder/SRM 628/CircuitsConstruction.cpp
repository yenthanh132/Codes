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

const int maxn=10007;
struct CircuitsConstruction {

    string circuit;
    int len,cnt;
    char key[maxn];
    int lnode[maxn], rnode[maxn];
    int val[maxn];

    pii build(int i){
        key[++cnt]=circuit[i];
        if(key[cnt]=='X') return pii(cnt,i);
        int cur = cnt;
        pii tmp = build(i+1);
        lnode[cur] = tmp.first;
        tmp = build(tmp.second+1);
        rnode[cur] = tmp.first;
        return pii(cur,tmp.second);
    }

    void dfs(int u){
        if(key[u]=='X'){
            val[u]=1;
            return;
        }
        dfs(lnode[u]); dfs(rnode[u]);
        if(key[u]=='A'){
            val[u] = val[lnode[u]] + val[rnode[u]];
        }else{
            val[u] = max(val[lnode[u]], val[rnode[u]]);
        }
    }

	int maximizeResistance(string _circuit, vector <int> arr) {
        circuit = _circuit;
        len=sz(circuit);
        if(len==1) return arr[0];
        cnt=0;
        pii tmp = build(0);
        dfs(1);
        sort(arr.begin(), arr.end(), greater<int>());
        int res=0;
        for(int i=0; i<val[1]; ++i) res+=arr[i];
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
			string circuit            = "BXBXX";
			int conductors[]          = {8, 2, 3};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string circuit            = "AAXXAXAXX";
			int conductors[]          = {1, 1, 2, 8, 10};
			int expected__            = 22;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string circuit            = "AXBXX";
			int conductors[]          = {8, 2, 3};
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string circuit            = "BAAXBXXBXAXXBBAXXBXXAAXXX";
			int conductors[]          = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
			int expected__            = 454;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string circuit            = ;
			int conductors[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string circuit            = ;
			int conductors[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string circuit            = ;
			int conductors[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CircuitsConstruction().maximizeResistance(circuit, vector <int>(conductors, conductors + (sizeof conductors / sizeof conductors[0])));
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
