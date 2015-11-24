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

vector<string> s;
int n,len,dis[maxn];
pii ds[2][maxn*maxn];
int cnt[2];
bool inDFS[maxn], mark[maxn][maxn];

int dfs(int u){
    inDFS[u]=1;
    int len=sz(s[u]);
    int res=len;
    for(int v=0; v<n; ++v) if(s[u][len-1]==s[v][0]){
        if(inDFS[v]){
            inDFS[u]=0;
            return oo;
        }
        else res=max(res,len-1+dfs(v));
    }
    inDFS[u]=0;
    return res;
}


struct StickedWords {

    string constructLine( vector <string> dict, int _len ) {
        s = dict;
        n=sz(s);
        len=_len;

        reset(inDFS,0);
        for(int v=0; v<n; ++v) dis[v]=dfs(v);

        string res="";
        reset(cnt,0);
        for(int v=0; v<n; ++v) if(dis[v]>=len) ds[0][++cnt[0]]=pii(v,0);

        int flag=0;
        reset(mark,0);
        for(int i=1; ; ++i){
            flag^=1;
            int minv=oo;
            cnt[flag]=0;
            for(int j=1; j<=cnt[1^flag]; ++j){
                if(s[ds[1^flag][j].first][ds[1^flag][j].second] < minv)
                    minv=s[ds[1^flag][j].first][ds[1^flag][j].second];
            }
            if(minv==oo) return "";
//            printf("%c",minv);
            res+=char(minv);
            bool foundend=0;
            for(int j=1; j<=cnt[1^flag]; ++j)
                if(s[ds[1^flag][j].first][ds[1^flag][j].second] == minv){
                    int u=ds[1^flag][j].first, p=ds[1^flag][j].second;
                    if(p+1<sz(s[u])){
                        if(mark[u][p+1]) continue;
                        mark[u][p+1]=1;
                        ds[flag][++cnt[flag]]=pii(u,p+1);
                    }else{
                        foundend=1;
                        int minv=-1;
                        for(int v=0; v<n; ++v){
                            if(s[u][p]==s[v][0] && sz(s[v])>1 && dis[v]+i-1>=len){
                                if(minv==-1 || s[minv][
                                ds[flag][++cnt[flag]]=pii(v,1);
                            }
                        }
                    }
                }

            for(int i=1; i<=cnt[flag]; ++i)
                mark[ds[flag][i].first][ds[flag][i].second]=0;
            if(foundend && i>=len) break;
        }
//        puts("");
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
			string dict[]             = {"salad", "sandwich", "hamburger", "rings"};
			int len                   = 35;
			string expected__         = "hamburgeringsandwichamburgeringsalad";

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string dict[]             = {"salad", "hamburger", "rings"};
			int len                   = 35;
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string dict[]             = {"aba", "aac", "czz"};
			int len                   = 10;
			string expected__         = "abababaaczz";

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string dict[]             = {"aarb", "bcb", "bbd", "dzz"};
			int len                   = 15;
			string expected__         = "aarbcbcbcbcbbdzz";

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string dict[]             = {"abd", "dgga", "abdg", "gga", "gg", "gaader"};
			int len                   = 22;
			string expected__         = "abdggabdggabdggabdgaader";

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string dict[]             = ;
			int len                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string dict[]             = ;
			int len                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string dict[]             = ;
			int len                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = StickedWords().constructLine(vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), len);
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
