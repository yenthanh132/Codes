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

const int INF = 1000000000;

struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), g(n), q(n) {
        e.clear();
        for(int i=0; i<n; ++i) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            for(int i=0; i<n; ++i) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        for(int i=0; i<n; ++i) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            for(int i=0; i<sz(g[v]); ++i) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

struct SegmentDrawing {

    int n,N;

    int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
        int v = (y3-y1)*(x2-x1)-(y2-y1)*(x3-x1);
        if(v>0) return 1;
        if(v<0) return -1;
        return 0;
    }

    bool cut(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
        return ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4)<=0 &&
               ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)<=0;
    }

    int maxScore( vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore ) {
        n=sz(x);
        N=n*n;
        MaxFlow mf(N*2+2);
        int S=N*2, F=N*2+1;
        int total=0;
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
            mf.addEdge(S,i*n+j,redScore[i*n+j]);
            total+=redScore[i*n+j];
        }
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
            mf.addEdge(i*n+j+N,F,blueScore[i*n+j]);
            total+=blueScore[i*n+j];
        }
        for(int i1=0; i1<n; ++i1) for(int j1=0; j1<n; ++j1)
            for(int i2=0; i2<n; ++i2) for(int j2=0; j2<n; ++j2)
                if(cut(x[i1],y[i1],x[j1],y[j1], x[i2],y[i2],x[j2],y[j2]))
                    mf.addEdge(i1*n+j1,i2*n+j2+N,oo);
        return (total-mf.getMaxFlow(S,F))/2;
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
			int x[]                   = {0,1,0,-1};
			int y[]                   = {1,0,-1,0};
			int redScore[]            = {0, 1, 2, 3, 1, 0, 6, 4, 2, 6, 0, 5, 3, 4, 5, 0};
			int blueScore[]           = {0, 2, 3, 7, 2, 0, 4, 6, 3, 4, 0, 5, 7, 6, 5, 0};
			int expected__            = 27;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 1};
			int y[]                   = {1, 0};
			int redScore[]            = {0, 101, 101, 0};
			int blueScore[]           = {0, 100, 100, 0};
			int expected__            = 101;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-3, -1, -1, 1, 1, 3};
			int y[]                   = { 0, -2, 2, -2, 2, 0};
			int redScore[]            = {0, 2, 1, 2, 1, 2, 2, 0, 2, 1, 2, 1, 1, 2, 0, 2, 1, 2, 2, 1, 2, 0, 2, 1, 1, 2, 1, 2, 0, 2, 2, 1, 2, 1, 2, 0};
			int blueScore[]           = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {-100, 100, 0, -10, 10, 0};
			int y[]                   = {0, 0, 100, 10, 10, 1};
			int redScore[]            = { 0, 96, 96, 25, 25, 25, 96, 0, 96, 25, 25, 25, 96, 96, 0, 25, 25, 25, 25, 25, 25, 0, 10, 10, 25, 25, 25, 10, 0, 10, 25, 25, 25, 10, 10, 0};
			int blueScore[]           = { 0, 30, 30, 20, 20, 20, 30, 0, 30, 20, 20, 20, 30, 30, 0, 20, 20, 20, 20, 20, 20, 0, 86, 86, 20, 20, 20, 86, 0, 86, 20, 20, 20, 86, 86, 0};
			int expected__            = 546;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int y[]                   = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
			int redScore[]            = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9, 15, 0, 15, 2, 3, 4, 5, 6, 7, 8, 2, 15, 0, 15, 2, 3, 4, 5, 6, 7, 3, 2, 15, 0, 15, 2, 3, 4, 5, 6, 4, 3, 2, 15, 0, 15, 2, 3, 4, 5, 5, 4, 3, 2, 15, 0, 15, 2, 3, 4, 6, 5, 4, 3, 2, 15, 0, 15, 2, 3, 7, 6, 5, 4, 3, 2, 15, 0, 15, 2, 8, 7, 6, 5, 4, 3, 2, 15, 0, 15, 9, 8, 7, 6, 5, 4, 3, 2, 15, 0} ;
			int blueScore[]           = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0, 0, 2, 3, 4, 5, 6, 7, 3, 2, 0, 0, 0, 2, 3, 4, 5, 6, 4, 3, 2, 0, 0, 100, 2, 3, 4, 5, 5, 4, 3, 2, 100, 0, 0, 2, 3, 4, 6, 5, 4, 3, 2, 0, 0, 0, 2, 3, 7, 6, 5, 4, 3, 2, 0, 0, 0, 2, 8, 7, 6, 5, 4, 3, 2, 0, 0, 0, 9, 8, 7, 6, 5, 4, 3, 2, 0, 0};
			int expected__            = 300;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int redScore[]            = ;
			int blueScore[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int redScore[]            = ;
			int blueScore[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int redScore[]            = ;
			int blueScore[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
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
