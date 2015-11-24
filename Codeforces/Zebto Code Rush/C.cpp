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

const int maxn=1007;

char s[maxn][10][10];
int m,n,a[maxn][maxn],d[maxn],free1[maxn],trace[maxn],N,w,k;
vector<int> e[maxn];

void prim(){
    reset(free1,1); reset(trace,0);
    FOR(i,1,N) d[i]=oo; d[N]=0;

    while(1){
        int u=-1, minv=oo;
        FOR(i,1,N) if(free1[i] && d[i]<minv){
            minv=d[i];
            u=i;
        }
        if(u==-1) break;
        free1[u]=0;
        FOR(v,1,N) if(free1[v] && d[v]>a[u][v]){
            d[v]=a[u][v];
            trace[v]=u;
        }
    }
}

void DFS(int u){
    if(u!=N){
        int y=trace[u];
        if(y==N) y=0;
        printf("%d %d\n",u,y);
    }
    REP(i,sz(e[u])) DFS(e[u][i]);
}

void solve(){
    int res=0;
    FOR(u,1,N) if(trace[u]!=0) res+=a[u][trace[u]], e[trace[u]].pb(u);
    printf("%d\n",res);
    DFS(N);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&k,&w);
    FOR(i,1,k) REP(j,n) scanf("%s",s[i][j]);
    reset(a,0);
    FOR(i,1,k-1) FOR(j,i+1,k){
        int cnt=0;
        REP(x,n) REP(y,m) if(s[i][x][y]!=s[j][x][y]) ++cnt;
        a[i][j]=a[j][i]=cnt*w;
    }
    N=k+1;
    FOR(i,1,k) a[i][N]=a[N][i]=m*n;
    prim();
    solve();
    return 0;
}

