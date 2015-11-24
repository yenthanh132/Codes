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
typedef pair<int, pii> iii;

const int maxn=3007;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const char dch[4]={'A','>','V','<'};

struct edge{
    int x,y,c,f;
}e[maxn*maxn];
int Next[maxn*maxn],head[maxn];
int M,m,n,N,S,F,sum;
map<iii,int> mid;

struct LaserTowersDiv1 {

    void init(){
        N=2;
        S=1; F=2;
        M=0;
        sum=0;
        reset(head,-1);
        mid.clear();
    }

    void push(int u, int v, int c){
        e[M].x=u; e[M].y=v; e[M].c=c; e[M].f=0;
        Next[M]=head[u]; head[u]=M++;
        e[M].x=v; e[M].y=u; e[M].c=e[M].f=0;
        Next[M]=head[v]; head[v]=M++;
    }

    int getid(int d, int x, int y, bool addnew=1){
        if(mid.count(iii(d,pii(x,y)))==0){
            if(addnew){
                mid[iii(d,pii(x,y))]=++N;
                return N;
            }else return -1;
        }else return mid[iii(d,pii(x,y))];
    }

    //For flow
    int trace[maxn],myq[maxn];

    bool findpath(){
        FOR(u,1,N) trace[u]=-1;
        trace[S]=-1;
        int first,last;
        myq[first=last=1]=S;
        while(first<=last){
            int u=myq[first++];
            for(int i=head[u]; i!=-1; i=Next[i]){
                if(e[i].c>e[i].f){
                    if(trace[e[i].y]!=-1) continue;
                    trace[e[i].y]=i;
                    if(e[i].y==F) return 1;
                    myq[++last]=e[i].y;
                }
            }
        }
        return 0;
    }

    void incflow(){
        int delta=oo, i, v=F;
        do{
            i=trace[v];
            delta=min(delta,e[i].c-e[i].f);
            v=e[i].x;
        }while(v!=S);
        v=F;
        do{
            i=trace[v];
            e[i].f+=delta;
            e[i^1].f-=delta;
            v=e[i].x;
        }while(v!=S);
    }

    int getMaxFlow(){
        int res=0;
        while(findpath()) incflow();
        for(int i=head[S]; i!=-1; i=Next[i]) res+=e[i].f;
        return res;
    }

	int countMaxEnemies(vector <string> board) {
        m=sz(board); n=sz(board[0]);
        init();
        REP(x,m) REP(y,n) REP(k,4) if(board[x][y]==dch[k] && (k==1 || k==3)){
            int maxv=0;
            for(int xx=x+dx[k], yy=y+dy[k]; (0<=xx && xx<m) && (0<=yy && yy<n); xx+=dx[k], yy+=dy[k]){
                if(board[xx][yy]=='.') continue;
                int v=board[xx][yy]-'0';
                if(v<=maxv) continue;
                push(S,getid(k,xx,yy),v-maxv);
                sum+=v-maxv;
                maxv=v;
            }
        }
        REP(x,m) REP(y,n) REP(k,4) if(board[x][y]==dch[k] && (k==0 || k==2)){
            int maxv=0;            
            vector<int> idlist;
            for(int xx=x+dx[k], yy=y+dy[k]; (0<=xx && xx<m) && (0<=yy && yy<n); xx+=dx[k], yy+=dy[k]){
                REP(k2,4) if(k2==1 || k2==3){
                    for(int yt=yy; (0<=yt && yt<n); yt+=dy[k2]){
                        if(board[xx][yt]=='>' || board[xx][yt]=='<') break;
                        int id=getid(k2,xx,yt,0);
                        if(id==-1) continue;
                        idlist.pb(id);
                    }
                }
                if(board[xx][yy]=='.') continue;
                int v=board[xx][yy]-'0';
                if(v<=maxv) continue;
                int id2=getid(k,xx,yy);
                push(id2,F,v-maxv);
                sum+=v-maxv;
                maxv=v;
                REP(i,sz(idlist)){
                    cout<<idlist[i]<<' '<<id2<<endl;
                    push(idlist[i],id2,oo);
                }
            }
        }

        return sum-getMaxFlow();
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
//		case 0: {
//			string board[]            = {
//".9",
//">3",
//".A"
//}
//;
//			int expected__            = 9;
//
//			std::clock_t start__      = std::clock();
//			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
	//	case 1: {
//			string board[]            = {
//".6...",
//"1.<>1",
//".4...",
//"9A..."
//}
//;
//			int expected__            = oo;
//
//			std::clock_t start__      = std::clock();
//			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
		case 2: {
			string board[]            = {
"..V.",
">7..",
"..1."
}
;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
	
	}
	//	case 3: {
//			string board[]            = {
//"........7..7......4...<...V9.5.",
//">.........2.........5..46......",
//".6...........9..<..>...5.......",
//".6...................<..A>...5.",
//".V>....................6.......",
//".....57.............<...>....7.",
//"..............6.........<V....7",
//"V..V7..V..AA>..............61..",
//"..V.......V..A.....>.....5.....",
//"......7....V....>.........7....",
//"1...........<>..............6..",
//"............5...........<......",
//".........6..V.......V...V..A...",
//".2...........<....A..>....7....",
//"5..........................<...",
//".............V...5...>.....6...",
//"........5.......V.V....A...>.8.",
//".....A.........7.....>......5..",
//"96.........................<...",
//"....AV..............7V.....VA.A",
//"..............5....6........<.V",
//"..6................<........V..",
//"....V..............>.......5..6",
//"8.6................<...>....6..",
//".........A.............V.....A.",
//".....6A........A.A.>.....6.....",
//"69....<.A>.............3.......",
//"...2.....<....A.......>...2.6..",
//"...76..5.....7..7..5........7<.",
//"...8.......6..<..V5>.....9..7..",
//"....7.....5.5.<>.4...7.556.4..."}
//;
//			int expected__            = 328;
//
//			std::clock_t start__      = std::clock();
//			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}

		// custom cases

/*      case 4: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LaserTowersDiv1().countMaxEnemies(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
#include <conio.h>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
	getch();
}
// END CUT HERE
