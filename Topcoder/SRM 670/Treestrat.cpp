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

const int maxn=57;

struct Treestrat {

    int n,d[maxn];
    bool mark[maxn][maxn];

    vector<int> e[maxn];
    queue<int> myq;
    queue<pii> myq2;


    int check(int r){
        int res=0;
        reset(mark,0);
        if(d[r] > 0){
            mark[r][0]=1;
            myq2.push(pii(r,0));
        }
        while(!myq2.empty()){
            int u=myq2.front().first, time=myq2.front().second; myq2.pop();
            res = max(res, time);
            for(int i=0; i<sz(e[u]); ++i){
                int v=e[u][i];
                if(d[v] > time + 1 && !mark[v][time+1]){
                    mark[v][time+1]=1;
                    myq2.push(pii(v,time+1));
                }
            }
        }
        return res;
    }

    int roundcnt( vector <int> tree, vector <int> A, vector <int> B ) {
        n=sz(tree)+1;
        for(int i=0; i<n-1; ++i){
            int u=i+1, v=tree[i];
            e[u].pb(v);
            e[v].pb(u);
        }
        for(int u=0; u<n; ++u) e[u].pb(u);

        for(int i=0; i<n; ++i) d[i]=oo;
        for(int i=0; i<sz(B); ++i){
            int u=B[i];
            if(d[u]==oo){
                d[u]=0;
                myq.push(u);
            }
        }
        while(!myq.empty()){
            int u=myq.front(); myq.pop();
            for(int i=0; i<sz(e[u]); ++i){
                int v=e[u][i];
                if(d[v]!=oo) continue;
                d[v] = d[u] + 1;
                myq.push(v);
            }
        }

        int res=oo;
        for(int i=0; i<sz(A); ++i) res=min(res, check(A[i]));
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
			int tree[]                = {0};
			int A[]                   = {0};
			int B[]                   = {1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int tree[]                = {0,1};
			int A[]                   = {1};
			int B[]                   = {2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int tree[]                = {0,0,0,3,4};
			int A[]                   = {2};
			int B[]                   = {1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6,5};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {4,1};
			int B[]                   = {3,6};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Treestrat().roundcnt(vector <int>(tree, tree + (sizeof tree / sizeof tree[0])), vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
