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

const int maxn=3007;

int T,n,m,k,low[maxn],num[maxn],cnt,child[maxn];
bool khop[maxn];
vector<int> a[maxn];

void dfs(int u){
    int v;
    num[u]=++cnt; low[u]=oo;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(num[v]==0){
            child[u]++;
            dfs(v);
            if(low[v]>=num[u]) khop[u]=1;
            low[u]=min(low[v],low[u]);
        }else low[u]=min(low[u],num[v]);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    int u,v;
    REP(tt,T){
        scanf("%d%d%d",&n,&m,&k);
        REP(i,n) a[i].clear();
        REP(i,n) khop[i]=child[i]=num[i]=0;
        REP(i,m){
            scanf("%d%d",&u,&v);
            a[u].pb(v);
            a[v].pb(u);
        }
        cnt=0;
        dfs(0);
        if(child[0]<2) khop[0]=0;
        int res=0;
        REP(i,n) if(khop[i]) res+=k;
        printf("%d\n",res);
    }
    
   // getch();
    return 0;
}
