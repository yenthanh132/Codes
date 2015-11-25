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

const int maxn=100007;

int n,f[maxn][17],num[maxn],cnt,d[maxn],m,list[maxn],res;
vector<int> a[maxn];

int dfs(int u){
    num[u]=++cnt;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!num[v]){
            f[v][0]=u;
            d[v]=d[u]+1;
            dfs(v);
        }
    }
}

int lca(int u,int v){
    if(d[u]>d[v]) swap(u,v);
    REPD(i,17) if(((d[v]-d[u])>>i)&1) v=f[v][i];
    if(u==v) return u;
    REPD(i,17) if(f[u][i]!=f[v][i]){
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}

int dis(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-d[r]*2;
}

bool cmp(const int &a, const int &b){
    return num[a]<num[b];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int u,v;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    cnt=0; reset(num,0);
    d[1]=0;
    dfs(1);
    FOR(i,1,16) FOR(u,1,n) f[u][i]=f[f[u][i-1]][i-1];
    FOR(i,1,n){
        m=0;
        for(int j=i; j<=n; j+=i) list[m++]=j;
        sort(list,list+m,cmp);
        res=dis(1,list[0])+dis(1,list[m-1]);
        REP(i,m-1) res+=dis(list[i],list[i+1]);
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
