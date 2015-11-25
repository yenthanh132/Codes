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

const int maxn = 20007;

int T,n,val[maxn],f[maxn];
vector<int> a[maxn],b[maxn];

void dfs(int u, int p){
    val[u]=f[u]=0;
    int v;
    REP(i,sz(b[u])) if(b[u][i]!=p){
        v=b[u][i];
        dfs(v,u);
        f[u]+=f[v];
        if(val[v]>0) val[u]+=val[v];
        else{
            val[u]++;
            f[u]++;
        }
    }
    REP(i,sz(a[u])) if(a[u][i]!=p){
        v=a[u][i];
        dfs(v,u);
        f[u]+=f[v];
        if(val[v]<0){
            if(val[u]+val[v]>=0){
                f[u]+=val[v];
                val[u]+=val[v];
            }else{
                f[u]-=max(val[u],0);
                val[u]+=val[v];
            }
        }else{
            val[u]--;
            if(val[u]<0) f[u]++;
        }
    }
}
                   
int main(){
    scanf("%d",&T);
    int u,v;
    REP(index,T){
        scanf("%d",&n);
        REP(i,n) a[i].clear(), b[i].clear();
        REP(i,n-1){
            scanf("%d%d",&u,&v);
            a[u].pb(v);
            b[v].pb(u);
        }
        dfs(0,-1);
        printf("Case %d: %d\n",index+1,f[0]);
    }
    return 0;
}
