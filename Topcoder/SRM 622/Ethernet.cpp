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

struct Ethernet {
    int n,f[55][555],minf[55][555],d;
    vector<pii> a[55];

    void updatef(int u){
        minf[u][0]=(f[u][0]!=-1?f[u][0]:oo);
        FOR(dep,1,d) minf[u][dep] = min ((f[u][dep]!=-1?f[u][dep]:oo), minf[u][dep-1]);
    }

    void dp(int u){
        if(sz(a[u])==0){
            f[u][0]=0;
            updatef(u);
            return;
        }
        int v,w;
        REP(i,sz(a[u])){
            v=a[u][i].fi;
            dp(v);
        }

        FOR(dep,0,d){
            if(dep*2<=d){
                f[u][dep]=0;
                REP(i,sz(a[u])){
                    v=a[u][i].fi;
                    w=a[u][i].se;

                    if(dep-w<0) f[u][dep]+=minf[v][d]+1;
                    else
                        f[u][dep]+=min(minf[v][dep-w],minf[v][d]+1);
                }
            }else{
                int dep2=d-dep;
                int tmp=0;
                REP(i,sz(a[u])){
                    v=a[u][i].fi;
                    w=a[u][i].se;
                    if(dep2-w<0) tmp+=minf[v][d]+1;
                    else tmp+=min(minf[v][dep2-w],minf[v][d]+1);
                }
                f[u][dep]=oo;
                REP(i,sz(a[u])){
                    v=a[u][i].fi;
                    w=a[u][i].se;
                    int tmp2=tmp;

                    if(dep2-w<0) tmp2-=minf[v][d]+1;
                    else tmp2-=min(minf[v][dep2-w],minf[v][d]+1);

                    if(dep-w<0) tmp2+=minf[v][d]+1;
                    else tmp2+=min(minf[v][dep-w],minf[v][d]+1);
                    f[u][dep]=min(f[u][dep],tmp2);
                }
            }
        }

        updatef(u);
    }

	int connect(vector <int> parent, vector <int> dist, int maxDist) {
        n=sz(parent);
        d=maxDist;
        REP(i,n) a[parent[i]].pb(pii(i+1,dist[i]));
        ++n;
        reset(f,-1);
        dp(0);
        int res=oo;
        FOR(dep,0,d) if(f[0][dep]!=-1) res=min(res,f[0][dep]);
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
			int parent[]              = {0,0,0};
			int dist[]                = {1,1,1};
			int maxDist               = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0,0,0,0,0,0,0};
			int dist[]                = {1,2,3,4,5,6,7};
			int maxDist               = 8;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0,1,2,3,4,5};
			int dist[]                = {1,2,3,4,5,6};
			int maxDist               = 6;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0,0,0,1,1};
			int dist[]                = {1,1,1,1,1};
			int maxDist               = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2};
			int dist[]                = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4};
			int maxDist               = 162;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int parent[]              = ;
			int dist[]                = ;
			int maxDist               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int dist[]                = ;
			int maxDist               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int parent[]              = ;
			int dist[]                = ;
			int maxDist               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Ethernet().connect(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), vector <int>(dist, dist + (sizeof dist / sizeof dist[0])), maxDist);
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
