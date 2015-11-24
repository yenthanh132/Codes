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

struct seg{
    int x, y1,y2;
    seg(){}
    seg(int a, int b, int c):x(a), y1(b), y2(c){}
};

bool cmp1(const seg &a, const seg &b){
    return a.x<b.x || (a.x==b.x && a.y1<b.y1);
}

struct Hieroglyphs {


    vector<seg> v1,v2,h1,h2;

    bool get(string &s, int &x1, int &y1, int &x2, int &y2){
        if(s=="") return 0;
        string st="";
        int i;
        for(i=0; i<sz(s); ++i){
            if(s[i]==',') break;
            st+=s[i];
        }
        if(i>sz(s)) s=""; else s.erase(0,i+1);
        stringstream ss;
        ss<<st;
        ss>>x1>>y1>>x2>>y2;
        return 1;
    }



    int insect(int x1, int x2, int y1, int y2){
        int minv=max(x1,y1);
        int maxv=min(x2,y2);
        return max(0,maxv-minv);
    }

    int calc(vector<seg> &v1, vector<seg> &v2, int x0, int y0){
        int ans=0;
        for(int i=0,j=0; i<sz(v1); ++i){
            while(j<sz(v2) && (v2[j].x + x0) < v1[i].x) ++j;
            while(j<sz(v2) && (v2[j].x + x0) == v1[i].x && (v2[j].y2+y0)<=v1[i].y2){
                ans += insect(v1[i].y1, v1[i].y2, v2[j].y1+y0, v2[j].y2+y0);
                ++j;
            }
            if(j<sz(v2) && (v2[j].x + x0) == v1[i].x )
                ans += insect(v1[i].y1, v1[i].y2, v2[j].y1+y0, v2[j].y2+y0);
        }
        return ans;
    }

    int calc(int sum, int x0, int y0){
        int ans = 0;
        ans += calc(v1,v2,x0,y0);
        ans += calc(h1,h2,y0,x0);
        return sum-ans;
    }



    int minimumVisible( vector <string> hier1, vector <string> hier2 ) {
        int sum=0;
        for(int i=0; i<sz(hier1); ++i){
            string s=hier1[i];
            int x1,y1,x2,y2;
            while(get(s,x1,y1,x2,y2)){
                if(x1==x2) v1.pb(seg(x1,y1,y2));
                else h1.pb(seg(y1,x1,x2));
                sum+=(x2-x1)+(y2-y1);
            }
        }
        for(int i=0; i<sz(hier2); ++i){
            string s=hier2[i];
            int x1,y1,x2,y2;
            while(get(s,x1,y1,x2,y2)){
                if(x1==x2) v2.pb(seg(x1,y1,y2));
                else h2.pb(seg(y1,x1,x2));
                sum+=(x2-x1)+(y2-y1);
            }
        }
        sort(v1.begin(),v1.end(),cmp1);
        sort(v2.begin(),v2.end(),cmp1);
        sort(h1.begin(),h1.end(),cmp1);
        sort(h2.begin(),h2.end(),cmp1);
        int res=sum;
        for(int x0=-100; x0<=100; ++x0) for(int y0=-100; y0<=100; ++y0) res=min(res,calc(sum,x0,y0));
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
			string hier1[]            = {"0 0 10 0,10 0 10 3"};
			string hier2[]            = {"0 1 10 1","5 1 5 4"};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string hier1[]            = {"1 1 1 5"};
			string hier2[]            = {"3 2 5 2"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string hier1[]            = {"0 2 6 2"};
			string hier2[]            = {"5 1 6 1,8 1 9 1"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string hier1[]            = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"};
			string hier2[]            = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}
;
			int expected__            = 65;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string hier1[]            = {"10 10 10 20,10 30 10 40","10 10 20 10"};
			string hier2[]            = {"10 0 10 20,10 27 10 35","10 0 20 0"};
			int expected__            = 45;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string hier1[]            = ;
			string hier2[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string hier1[]            = ;
			string hier2[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string hier1[]            = ;
			string hier2[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Hieroglyphs().minimumVisible(vector <string>(hier1, hier1 + (sizeof hier1 / sizeof hier1[0])), vector <string>(hier2, hier2 + (sizeof hier2 / sizeof hier2[0])));
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
