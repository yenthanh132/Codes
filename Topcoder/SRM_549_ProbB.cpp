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

int r[15],c[15],m,n,Count,ce,dat[15];
vector<pii> p;
vector< vector<int> > save;

void duyet(int i, const int& id, const int& ccoin){
    if(i>ccoin){
        REP(i,m) if(r[i]&1) return;
        REP(j,n) if(c[j]&1) return;
        vector<int> ds(dat+1,dat+ccoin+1);
        save.pb(ds);
        return;
    }
    FOR(j,dat[i-1]+1,Count) if((id>>j)&1){
        dat[i]=j;
        r[p[j].fi]++; c[p[j].se]++;
        duyet(i+1,id,ccoin);
        r[p[j].fi]--; c[p[j].se]--;
    }
}
        

int getval(int id, int num, int ccoin){
    if(num==0) return 0;
    duyet(1,id,ccoin);
    if(save.empty()) return 0;
    REP(i,sz(save)){
        
    

class MagicalHats {
public:
	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
		m=sz(board); n=sz(board[0]);
		reset(r,0); reset(c,0);
		Count=0;
		REP(i,m) REP(j,n) if(s[i][j]=='H'){
            Count++;
            p.pb(pii(i,j));
            r[i]++; c[j]++;
        }
        ce=sz(coins);
        dat[0]=-1;
        duyet(1,(1<<Count)-1,ce);
        if(save.empty()) return -1;
    
        int val=getval(1<<Count-1,numGuesses,ce);
	}
};

