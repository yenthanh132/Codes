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

const int maxn = 10007;

int n,list[maxn],deg[maxn],ans[maxn],m;
vector<int> a[maxn];
int mark[maxn];

bool cmp(const int &a, const int &b){
    return deg[a]>deg[b];
}


int main(){
    freopen("kgraph.in","r",stdin);
    freopen("kgraph.out","w",stdout);
    scanf("%d%d",&n,&m);
    int u,v,maxdeg=0;
    reset(deg,0);
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        deg[u]++; deg[v]++;
        a[u].pb(v); a[v].pb(u);
    }
    
    FOR(i,1,n) list[i]=i, maxdeg=max(maxdeg,deg[i]);
    sort(list+1,list+n+1,cmp);
    reset(mark,0); reset(ans,0);
    FOR(i,1,n){
        u=list[i];
        REP(j,sz(a[u])){
            v=a[u][j];
            if(ans[v]) mark[ans[v]]=i;
        }
        FOR(color,1,maxn) if(mark[color]<i){
            ans[u]=color;
            break;
        }
    }
    if(maxdeg%2==0) maxdeg++;
    printf("%d\n",maxdeg);
    FOR(i,1,n) printf("%d\n",ans[i]);
   
    return 0;
}
