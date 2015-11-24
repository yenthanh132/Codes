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

const double eps=1e-7;
int n,code[100],p[100];
vector<int> a[100],b[100];
bool chua[100];
set<int> myset;

bool inside(int i, int j, vector<int> &x, vector<int> &y, vector<int>&r){
    double dis=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    dis=sqrt(dis);
    if(dis+r[i]<=r[j]+eps) return 1;
    return 0;
}

int grundy;

void dfs(int u, int &del){
    if(!chua[u]){
        grundy^=code[u];
        return;
    }
    REP(i,sz(a[u])) dfs(a[u][i],del);
}

void cal(int u){
    int v;
    if(a[u].empty()){
        code[u]=1;
        return;
    }

    REP(i,sz(a[u])) cal(a[u][i]);
    myset.clear();
    REP(i,sz(b[u])){
        v=b[u][i];
        reset(chua,0);
        while(v!=u){
            chua[v]=1;
            v=p[v];
        }   
        chua[u]=1;
        grundy=0;
        v=b[u][i];
        dfs(u,v);
        myset.insert(grundy);
    }
    grundy=0;
    REP(i,sz(a[u])) grundy^=code[a[u][i]];
    myset.insert(grundy);
    v=0;
    while(myset.count(v)>0) v++;
    code[u]=v;
}
        

class CirclesGame {
public:
	string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
		n=sz(x);
		reset(p,-1);
        REP(i,n) REP(j,n) if(i!=j && inside(i,j,x,y,r)){
            b[j].pb(i);
            bool ok=1;
            REP(z,n) if(z!=i && z!=j && inside(i,z,x,y,r) && inside(z,j,x,y,r)) ok=0;
            if(!ok) continue;
            a[j].pb(i);
            p[i]=j;
        }
        int res=0;
        REP(i,n) if(p[i]==-1){       		
            cal(i);
            res^=code[i];
        }
        if(res!=0) return "Alice"; else return "Bob";
	}
};




<%:testing-code%>
//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
