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
typedef pair<int, pii> iii;


const int maxn=1007;

struct CandyCollection {

    vector<iii> e[maxn];
    bool free1[maxn];
    int n,dp[maxn];
    vector<pii> arr;

    void dfs(int u, int p){
        free1[u]=0;
        if(e[u][0].first == e[u][1].first){
            free1[e[u][0].first]=0;
            arr.pb(e[u][0].second);
            pii t = e[u][1].second;
            swap(t.first,t.second);
            arr.pb(t);
            return;
        }

        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first;
            if(v==p) continue;
            arr.pb(e[u][i].second);
            if(free1[v]) dfs(v,u);
            return;
        }
    }

    int calc(){
        int res = oo;
        int n=sz(arr);
        for(int r=0; r<n; ++r){
            for(int i=0; i<=n; ++i) dp[i]=oo; dp[0]=0;
            for(int i=1; i<=n; ++i){
                dp[i]=min(dp[i], dp[i-1]+arr[i-1].first+1);
                dp[i]=min(dp[i], dp[i-1]+arr[i%n].second+1);
                dp[i]=min(dp[i], min(dp[i-1],(i>=2?dp[i-2]:oo)) + max(arr[i-1].first, arr[i-1].second)+1);
            }
            res = min(res,dp[n]);
            pii tmp = arr[0];
            for(int i=0; i<n-1; ++i) arr[i]=arr[i+1];
            arr[n-1]=tmp;
        }
        return res;
    }

    int solve( vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2 ) {
        n=sz(Type1);
        for(int i=0; i<n; ++i){
            int u=Type1[i], v=Type2[i];
            int w1=Number1[i], w2=Number2[i];
            e[u].pb(iii(v,pii(w1,w2)));
            e[v].pb(iii(u,pii(w2,w1)));
        }

        reset(free1,1);
        int res = 0;

        for(int u=0; u<n; ++u) if(free1[u]){
            arr.clear();
            dfs(u,-1);
            res += calc();
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
			int Type1[]               = {0,0};
			int Number1[]             = {1,1};
			int Type2[]               = {1,1};
			int Number2[]             = {1,1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int Type1[]               = {0,0};
			int Number1[]             = {2,5};
			int Type2[]               = {1,1};
			int Number2[]             = {2,5};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int Type1[]               = {0,0,2,3};
			int Number1[]             = {1,1,2,2};
			int Type2[]               = {1,1,3,2};
			int Number2[]             = {1,1,2,2};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int Type1[]               = {0,1,2,3};
			int Number1[]             = {5,5,10,13};
			int Type2[]               = {1,2,3,0};
			int Number2[]             = {8,8,10,15};
			int expected__            = 20;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int Type1[]               = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
			int Number1[]             = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
			int Type2[]               = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
			int Number2[]             = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
			int expected__            = 5101;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int Type1[]               = ;
			int Number1[]             = ;
			int Type2[]               = ;
			int Number2[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int Type1[]               = ;
			int Number1[]             = ;
			int Type2[]               = ;
			int Number2[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int Type1[]               = ;
			int Number1[]             = ;
			int Type2[]               = ;
			int Number2[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CandyCollection().solve(vector <int>(Type1, Type1 + (sizeof Type1 / sizeof Type1[0])), vector <int>(Number1, Number1 + (sizeof Number1 / sizeof Number1[0])), vector <int>(Type2, Type2 + (sizeof Type2 / sizeof Type2[0])), vector <int>(Number2, Number2 + (sizeof Number2 / sizeof Number2[0])));
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
