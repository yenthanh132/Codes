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

const int maxn=4007;

struct TreesAnalysis {
    vector<int> a[maxn],b[maxn],id[maxn];
    int num[maxn],r[maxn],d[maxn],cnt;
    int n;
    ll res;

    void dfs1(int u, int p){
        ++cnt;
        num[u]=1;
        int v;
        REP(i,sz(b[u])){
            v=b[u][i];
            if(v==p) continue;
            dfs1(v,u);
        }
    }

    void dfs2(int u, int p){
        d[u]=0;
        if(num[u]) d[u]++;
        int v,idx;
        REP(i,sz(a[u])){
            v=a[u][i];
            if(v==p) continue;
            dfs2(v,u);
            d[u]+=d[v];

            idx=id[u][i];
            r[idx]=max(r[idx],max(cnt-d[v],d[v]));
        }
    }

	long long treeSimilarity(vector <int> tree1, vector <int> tree2) {
        n=sz(tree1)+1;
        REP(i,n-1){
            a[i].pb(tree1[i]); id[i].pb(i);
            a[tree1[i]].pb(i); id[tree1[i]].pb(i);
            b[i].pb(tree2[i]);
            b[tree2[i]].pb(i);
        }
        res=0;
        REP(i,n-1){
            int u=i, v=tree2[i];
            reset(r,0);

            cnt=0;
            reset(num,0);
            dfs1(u,v);
            dfs2(0,-1);

            cnt=n-cnt;
            REP(i,n) num[i]^=1;
            dfs2(0,-1);
            REP(i,n) res+=r[i]*r[i];
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
//		case 0: {
//			int tree1[]               = {1};
//			int tree2[]               = {1};
//			long long expected__      = 1;
//
//			std::clock_t start__      = std::clock();
//			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
		case 1: {
			int tree1[]               = {2, 4, 1, 0};
			int tree2[]               = {1, 4, 4, 4};
			long long expected__      = 111;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int tree1[]               = {1, 2, 3, 4};
			int tree2[]               = {1, 2, 3, 4} ;
			long long expected__      = 128;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int tree1[]               = {2, 3, 4, 4, 5, 8, 5, 6, 10, 8};
			int tree2[]               = {9, 0, 1, 0, 3, 0, 5, 0, 7, 10};
			long long expected__      = 6306;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int tree1[]               = {222, 261, 167, 133, 174, 150, 165, 311, 208, 268, 111, 222, 154, 277, 282, 201, 46, 124, 194, 331, 4, 216, 111, 275, 72, 322, 137, 216, 241, 48, 72, 101, 232, 165, 151, 263, 139, 16, 122, 140, 84, 135, 314, 106, 309, 126, 102, 151, 208, 27, 242, 93, 83, 314, 136, 77, 82, 215, 16, 232, 286, 156, 294, 38, 67, 204, 206, 137, 174, 282, 188, 143, 84, 279, 236, 136, 158, 10, 65, 332, 122, 44, 329, 62, 174, 67, 102, 216, 245, 296, 287, 307, 93, 197, 169, 268, 266, 294, 157, 277, 95, 68, 214, 135, 211, 127, 82, 108, 212, 161, 243, 212, 207, 119, 119, 158, 97, 290, 21, 217, 230, 85, 171, 13, 138, 294, 304, 204, 318, 115, 70, 210, 195, 223, 37, 164, 149, 3, 164, 328, 316, 108, 330, 48, 38, 324, 222, 193, 50, 41, 184, 93, 148, 41, 151, 139, 106, 301, 264, 80, 249, 110, 244, 109, 212, 223, 279, 330, 67, 27, 301, 165, 236, 194, 3, 157, 1, 217, 311, 87, 105, 4, 286, 37, 6, 31, 111, 66, 230, 227, 244, 322, 196, 65, 69, 305, 112, 133, 231, 68, 153, 206, 309, 248, 329, 58, 69, 69, 328, 0, 29, 233, 243, 305, 167, 80, 65, 194, 190, 179, 142, 196, 324, 206, 134, 50, 272, 261, 10, 147, 329, 322, 14, 142, 169, 21, 296, 284, 241, 55, 304, 150, 166, 230, 167, 304, 87, 156, 156, 97, 274, 324, 196, 101, 82, 106, 260, 242, 233, 207, 305, 10, 166, 53, 18, 154, 233, 217, 296, 263, 168, 138, 30, 115, 135, 188, 98, 309, 292, 204, 150, 210, 332, 330, 166, 96, 70, 24, 229, 215, 201, 285, 40, 287, 142, 68, 133, 208, 268, 161, 310, 41, 203, 73, 275, 184, 163, 227, 89, 110, 328, 108, 112, 125, 164, 127, 179, 267, 221, 49, 139, 1, 84, 136, 38, 6, 70, 246, 243, 3, 188, 297};
			int tree2[]               = {174, 262, 195, 288, 157, 278, 36, 133, 230, 273, 222, 138, 97, 23, 189, 141, 296, 55, 45, 301, 81, 199, 188, 289, 187, 164, 113, 58, 138, 300, 289, 282, 329, 91, 130, 178, 92, 143, 48, 81, 311, 133, 151, 286, 171, 196, 199, 80, 83, 121, 65, 151, 277, 136, 49, 111, 58, 36, 259, 14, 31, 9, 136, 181, 122, 324, 249, 114, 9, 37, 259, 242, 165, 174, 34, 36, 298, 92, 301, 237, 178, 82, 65, 295, 110, 311, 274, 235, 68, 56, 259, 180, 195, 52, 110, 68, 140, 71, 52, 296, 290, 115, 213, 82, 209, 209, 74, 178, 302, 131, 99, 205, 296, 309, 288, 180, 329, 71, 143, 58, 152, 273, 196, 7, 169, 88, 231, 331, 213, 181, 80, 249, 170, 246, 16, 127, 75, 276, 332, 174, 21, 180, 163, 78, 242, 312, 295, 199, 89, 142, 85, 195, 115, 119, 95, 94, 279, 290, 3, 33, 93, 284, 20, 47, 47, 78, 331, 271, 113, 179, 249, 331, 92, 324, 9, 71, 232, 46, 28, 289, 80, 28, 80, 134, 20, 280, 277, 48, 205, 107, 52, 320, 4, 191, 160, 182, 189, 227, 295, 115, 54, 195, 78, 292, 189, 273, 301, 69, 305, 36, 222, 167, 326, 106, 48, 45, 74, 61, 181, 311, 292, 270, 201, 34, 314, 218, 214, 92, 269, 18, 37, 151, 142, 209, 11, 227, 327, 198, 28, 272, 152, 22, 47, 143, 332, 253, 273, 35, 78, 130, 295, 223, 181, 329, 18, 238, 300, 186, 274, 99, 300, 322, 41, 185, 311, 288, 198, 2, 37, 83, 238, 133, 122, 178, 107, 106, 66, 238, 69, 90, 38, 109, 246, 278, 288, 250, 321, 269, 130, 28, 115, 122, 33, 185, 275, 99, 130, 99, 152, 268, 133, 249, 180, 30, 210, 201, 324, 29, 290, 143, 3, 269, 68, 106, 230, 1, 269, 29, 120, 259, 324, 328, 23, 243, 9, 61, 14, 118, 199, 146, 237, 14};
			long long expected__      = 11478648052LL;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int tree1[]               = ;
			int tree2[]               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int tree1[]               = ;
			int tree2[]               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int tree1[]               = ;
			int tree2[]               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TreesAnalysis().treeSimilarity(vector <int>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <int>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])));
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
