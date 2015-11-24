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

const int maxn=555;
int a[maxn][maxn],odeg[maxn];
int mX[maxn],mY[maxn],dis[maxn],myq[maxn];
vector<int> e[maxn];
int n,m;

bool findpath(){
    int first=1, last=0;
    FOR(u,1,n) if(mX[u]==0){
        dis[u]=0;
        myq[++last]=u;
    }else dis[u]=oo;
    dis[0]=oo;
    while(first<=last){
        int u=myq[first++];
        REP(i,sz(e[u])){
            int v=e[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]!=0) myq[++last]=mY[v];
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

int calc(int u){
    int cnt=0;
    if(a[u][u]==0) ++cnt;
    FOR(v,1,n) if(v!=u) cnt+=2-a[u][v]-a[v][u];

    reset(mX,0), reset(mY,0);
    FOR(v,1,n) e[v].clear();
    int ce=0,f=0;
    FOR(x,1,n) if(x!=u) FOR(y,1,n) if(y!=u) if(a[x][y]) e[x].pb(y), ++ce;

    while(findpath())
        FOR(v,1,n) if(mX[v]==0 && dfs(v)) ++f;
    cnt+=ce-f;

    FOR(v,1,n) if(v!=u && mX[v]==0) ++cnt;

    return cnt;
}

int main(){
    //freopen("input.txt","r",stdin);
    int x,y;
    cin>>n>>m;
    REP(i,m){
        cin>>x>>y;
        a[x][y]=1;
    }
    int res=oo;
    FOR(u,1,n) res=min(res,calc(u));

    cout<<res<<endl;
}

