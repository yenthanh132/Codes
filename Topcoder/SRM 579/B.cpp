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

const int maxn=57;
const int maxm=17;
const int maxt=605000;
int a[maxn][maxn],start[maxn],end[maxn],dur[maxn],dp[maxt][maxm];
int n,m;

set<pii> mys;
int res;

int countbit(int u){
    int res=0;
    REP(i,m) if((u>>i)&1) res++;
    return res;
}

void solve(){
    REP(u,m) if(a[n-1][u]!=oo && a[n-1][u]<=end[u]){
        mys.insert(pii(a[n-1][u],u));        
        dp[a[n-1][u]][u]=1<<u;
    }
    int t,u,t2,mask;
    while(!mys.empty()){
        t=mys.begin()->fi; u=mys.begin()->se; mys.erase(mys.begin());   
        mask=dp[t][u];
        res=max(res,countbit(mask));
        if(t<start[u]) t2=start[u]+dur[u];
        else t2=t+dur[u];
        REP(v,m) if(a[u][v]!=oo && t2+a[u][v]<=end[v] && (((mask>>v)&1)==0)){
            dp[t2+a[u][v]][v]=mask^(1<<v);
            pii tmp=pii(t2+a[u][v],v);
            if(mys.find(tmp)==mys.end()) mys.insert(tmp);
        }
    }
}


class TravellingPurchasingMan {
public:
	int maxStores(int N, vector <string> stores, vector <string> roads) {
	    m=sz(stores);	
		n=N;
		REP(i,n) REP(j,n) if(i==j) a[i][j]=0; else a[i][j]=oo;
		REP(i,m){
            stringstream ss;
            ss<<stores[i];
            ss>>start[i]>>end[i]>>dur[i];
        }
        REP(j,sz(roads)){
            stringstream ss;
            ss<<roads[j];
            int u,v,l;
            ss>>u>>v>>l;
            a[u][v]=a[v][u]=l;
        }
        REP(k,n) REP(i,n) REP(j,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        res=0;
        solve();
        return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
