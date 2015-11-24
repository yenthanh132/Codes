
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

const int maxn=402;
int n,k,parent[maxn],id[maxn][maxn],se[maxn];
vector<int> e[maxn],rlist,f[maxn][maxn],trace[maxn][maxn];

void dp(int u, int p){
    int v;
    parent[u]=p;
    int cnt=0;
    REP(i,se[u]){
        v=e[u][i];
        if(v==p) continue;
        dp(v,u);
        ++cnt;
    }

    FOR(j,2,k) f[u][j][0]=oo; f[u][1][0]=cnt;
    f[u][0][0]=0;
    REP(i,se[u]){
        v=e[u][i];
        FOR(j,1,k){
            f[u][j][i+1]=f[u][j][i];
            trace[u][j][i+1]=0;
            if(v==p) continue;
            FOR(j2,1,j-1) if(f[u][j][i+1]>f[v][j2][se[v]]+f[u][j-j2][i]-1){
                f[u][j][i+1]=f[v][j2][se[v]]+f[u][j-j2][i]-1;
                trace[u][j][i+1]=j2;
            }
        }
    }

}

bool mark[maxn];

void dfs(int u, int k){
    mark[u]=1;
    int kt=k,v;
    REPD(i,se[u]){
        v=e[u][i];
        if(trace[u][kt][i+1]){
            int j2=trace[u][kt][i+1];
            kt-=j2;
            dfs(v,j2);
        }
    }
    REP(i,sz(e[u])){
        int v=e[u][i];
        if(!mark[v]){
            rlist.pb(id[u][v]);
            //cout<<u<<' '<<v<<endl;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int x,y;
    scanf("%d%d",&n,&k);
    REP(i,n-1){
        scanf("%d%d",&x,&y);
        e[x].pb(y); e[y].pb(x);
        id[x][y]=id[y][x]=i+1;
    }
    FOR(u,1,n){
        se[u]=sz(e[u]);
        FOR(j,0,k) f[u][j].resize(se[u]+1,0), trace[u][j].resize(se[u]+1,0);
    }
    dp(1,-1);
    int res=oo;
    int u=-1;
    FOR(i,1,n) if(f[i][k][se[i]]+(parent[i]!=-1)<res){
        res=f[i][k][se[i]];
        u=i;
    }
    reset(mark,0);
    if(n==135) cout<<u<<' '<<res<<endl;
    dfs(u,k);
    cout<<sz(rlist)<<endl;
    REP(i,sz(rlist)) cout<<rlist[i]<<' ';
    return 0;
}
