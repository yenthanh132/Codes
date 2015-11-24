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

ll dp[2][1594323];
ll cnt[2][1594323];

struct BearDestroys {

    int sumUp( int W, int H, int MOD ) {
        reset(dp,0); reset(cnt,0);
        for(int i=0; i<(1<<H); ++i){
            int state=0;
            int destroy=0;
            for(int j=0; j<H; ++j){
                int dir = i>>j&1;
                if(state%3==1){
                    state = state*3 + 0;
                }else{
                    if(dir==0) state = state*3 + 1;
                    else state = state*3 + 2;
                    ++destroy;
                }
            }
            dp[0][state]+=destroy;
            dp[0][state]%=MOD;
            cnt[0][state]+=1;
            cnt[0][state]%=MOD;
        }

        int flag=0;
        int p3=1;
        for(int i=0; i<H; ++i) p3*=3;

        for(int y=2; y<=W; ++y) for(int x=1; x<=H; ++x){
            flag ^= 1;
            reset(dp[flag], 0); reset(cnt[flag], 0);
            for(int state=0; state<p3; ++state){

                int dir,destroy,val,newstate;


                //to east
                dir=2; destroy=1;
                val = state/(p3/3);
                if(val==2) dir=destroy=0;
                if(x>1){
                    val = state%3;
                    if(val==1) dir=destroy=0;
                }
                if(y==W) destroy=0;
                newstate = (state%(p3/3)) * 3 + dir;
                cnt[flag][newstate] += cnt[flag^1][state];
                cnt[flag][newstate] %= MOD;
                dp[flag][newstate] += cnt[flag^1][state]*destroy + dp[flag^1][state];
                dp[flag][newstate] %= MOD;

                // to south
                dir=1; destroy=1;
                if(x==H){
                    dir=2; destroy=1;
                }
                val = state/(p3/3);
                if(val==2) dir=destroy=0;
                if(x>1){
                    val=state%3;
                    if(val==1) dir=destroy=0;
                }
                newstate = (state%(p3/3)) * 3 + dir;
                cnt[flag][newstate] += cnt[flag^1][state];
                cnt[flag][newstate] %= MOD;
                dp[flag][newstate] += cnt[flag^1][state]*destroy + dp[flag^1][state];
                dp[flag][newstate] %= MOD;
            }
        }

        ll res = 0;
        for(int state=0; state<p3; ++state) res = (res + dp[flag][state])%MOD;
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
			int W                     = 4;
			int H                     = 3;
			int MOD                   = 999999937;
			int expected__            = 24064;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int W                     = 3;
			int H                     = 4;
			int MOD                   = 999999937;
			int expected__            = 24576;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int W                     = 20;
			int H                     = 2;
			int MOD                   = 584794877;
			int expected__            = 190795689;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int W                     = 10;
			int H                     = 5;
			int MOD                   = 3;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int W                     = 1;
			int H                     = 1;
			int MOD                   = 19;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int W                     = 30;
			int H                     = 13;
			int MOD                   = 312880987;
			int expected__            = 107607437;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int W                     = ;
			int H                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int W                     = ;
			int H                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int W                     = ;
			int H                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearDestroys().sumUp(W, H, MOD);
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
