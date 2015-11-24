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

const int dx[]={1,0,-1,0,0,0};
const int dy[]={0,1,0,-1,0,0};
const int dz[]={0,0,0,0,1,-1};

struct ShadowSculpture {

    int n;
    bool mark[11][11][11];
    vector<string> xy,yz,zx;
    vector<string> txy,tyz,tzx;

    bool cmp(){
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
            if(xy[i][j]!=txy[i][j] || yz[i][j]!=tyz[i][j] || zx[i][j]!=tzx[i][j]) return 0;
        return 1;
    }

    void init(){
        txy.clear(); tyz.clear(); tzx.clear();
        for(int i=0; i<n; ++i){
            string s="";
            for(int j=0; j<n; ++j) s+="N";
            txy.pb(s); tyz.pb(s); tzx.pb(s);
        }
    }

    bool ok(int i, int j, int k){
        return xy[i][j]=='Y' && yz[j][k]=='Y' && zx[k][i]=='Y';
    }

    bool inside(int i, int j, int k){
        return 0<=i && i<n && 0<=j && j<n && 0<=k && k<n;
    }

    void dfs(int i, int j, int k){
        mark[i][j][k]=0;
        txy[i][j]='Y'; tyz[j][k]='Y'; tzx[k][i]='Y';
        for(int r=0; r<6; ++r){
            int ii=i+dx[r], jj=j+dy[r], kk=k+dz[r];
            if(!inside(ii,jj,kk) || !mark[ii][jj][kk]) continue;
            dfs(ii,jj,kk);
        }
    }

    string possible( vector <string> XY, vector <string> YZ, vector <string> ZX ) {
        n=sz(XY);
        xy=XY; yz=YZ; zx=ZX;
        reset(mark,0);
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k) if(ok(i,j,k)) mark[i][j][k]=1;
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
            bool found=0;
            for(int k=0; k<n; ++k) found |= (mark[i][j][k]);
            if(found != (xy[i][j]=='Y')) return "Impossible";
        }
        for(int j=0; j<n; ++j) for(int k=0; k<n; ++k){
            bool found=0;
            for(int i=0; i<n; ++i) found |= mark[i][j][k];
            if(found != (yz[j][k]=='Y')) return "Impossible";
        }
        for(int k=0; k<n; ++k) for(int i=0; i<n; ++i){
            bool found=0;
            for(int j=0; j<n; ++j) found |= mark[i][j][k];
            if(found != (zx[k][i]=='Y')) return "Impossible";
        }

        int cnt=0;
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k) if(mark[i][j][k]){
            ++cnt;
            init();
            dfs(i,j,k);
            if(cmp()) return "Possible";
        }
        if(cnt<=1) return "Possible";
        return "Impossible";
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
			string XY[]               = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
			string YZ[]               = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
			string ZX[]               = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string XY[]               = {"YN","NY"};
			string YZ[]               = {"YN","NY"};
			string ZX[]               = {"YN","NY"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string XY[]               = {"YYY","YNY","YYY"};
			string YZ[]               = {"YYY","YNY","YYY"};
			string ZX[]               = {"YYY","YNY","YYY"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string XY[]               = {"YYY","YNY","YYY"};
			string YZ[]               = {"NYY","YNY","YYY"};
			string ZX[]               = {"YYY","YNY","YYN"};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string XY[]               = {"N"};
			string YZ[]               = {"N"};
			string ZX[]               = {"N"};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string XY[]               = ;
			string YZ[]               = ;
			string ZX[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string XY[]               = ;
			string YZ[]               = ;
			string ZX[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string XY[]               = ;
			string YZ[]               = ;
			string ZX[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ShadowSculpture().possible(vector <string>(XY, XY + (sizeof XY / sizeof XY[0])), vector <string>(YZ, YZ + (sizeof YZ / sizeof YZ[0])), vector <string>(ZX, ZX + (sizeof ZX / sizeof ZX[0])));
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
