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

const int maxn=1007;

int g[maxn][4][4];
bool mark[maxn];

struct PathGame {

    int n;

    int get(int x1, int x2, int y1, int y2){
        if(x1>x2 && y1>y2) return 0;
        else if(x1>x2){
            if(y1==y2) return grundy(0,2,0);
            else return grundy(0,2,2);
        }else if(y1>y2){
            if(x1==x2) return grundy(0,1,0);
            else return grundy(0,1,1);
        }
        int left = max(x1,y1), right = min(x2,y2);
        int len=right-left+1; len=max(len,0);
        int l=0,r=0;
        if(x1<left) l=1; else if(y1<left) l=2;
        if(x2>right) r=1; else if(y2>right) r=2;
        return grundy(len,l,r);
    }

    int grundy(int len, int l, int r){
        if(l==2){
            l=1;
            if(r>0) r=3-r;
        }
        if(len==0 && l==0 && r==0) return 0;
        if(g[len][l][r]!=-1) return g[len][l][r];
        int &res=g[len][l][r];
        set<int> mys;
        int l1=1, l2=1, r1=len, r2=len;
        if(l == 1) --l1; else if(l == 2) --l2;
        if(r == 1) ++r1; else if(r == 2) ++r2;
        //top
        for(int i=l1; i<=r1; ++i){
            int v1=get(l1,i-1,l2,i-2);
            int v2=get(i+1,r1,i+2,r2);
            mys.insert(v1^v2);
        }
        //bot
        for(int i=l2; i<=r2; ++i){
            int v1=get(l1,i-2,l2,i-1);
            int v2=get(i+2,r1,i+1,r2);
            mys.insert(v1^v2);
        }
        for(res=0; mys.find(res)!=mys.end(); ++res);
        return res;
    }

    string judge( vector <string> board ) {
        reset(g,-1);
        n=sz(board[0]);
        for(int i=0; i<2; ++i) for(int j=0; j<n; ++j) if(board[i][j]=='#'){
            for(int v=-1; v<=1; ++v){
                int p=j+v;
                if(0<=p && p<n && board[i^1][p]=='.') board[i^1][p]='X';
            }
        }
        int res = 0;
        for(int j=0; j<n; ++j) if(board[0][j]=='.' || board[1][j]=='.'){
            int j2=j;
            while(j2+1<n && (board[0][j2+1]=='.' || board[1][j2+1]=='.')) ++j2;
            int len=j2-j+1;
            int l=0, r=0;
            if(board[0][j]!='.'){
                --len;
                l=2;
            }else if(board[1][j]!='.'){
                --len;
                l=1;
            }
            if(j2>j){
                if(board[0][j2]!='.'){
                    --len;
                    r=2;
                }else if(board[1][j2]!='.'){
                    --len;
                    r=1;
                }
            }
            res ^= grundy(len,l,r);
            for(int x=j; x<=j2; ++x) board[0][x]=board[1][x]='X';
        }
        if(res) return "Snuke"; else return "Sothe";
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
			string board[]            = {".."
,".."};
			string expected__         = "Sothe";

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"#"
,"."};
			string expected__         = "Sothe";

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"....."
,"..#.."};
			string expected__         = "Sothe";

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {".#..."
,"....."};
			string expected__         = "Snuke";

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".....#..#........##......."
,"..........#..........#...."};
			string expected__         = "Snuke";

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PathGame().judge(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
