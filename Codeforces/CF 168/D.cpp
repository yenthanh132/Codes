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

int n,m,cnt,ans[maxn*2];
struct node{int v,id;} list[maxn];
vector<int> a[maxn*2];
bool indfs[maxn*2],free1[maxn*2],found_cycle;

bool cmp(const node &a, const node &b){
    return a.v<b.v;
}

void dfs(int u){
    if(found_cycle) return;
    int v;
    free1[u]=0;
    indfs[u]=1;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v);
        else if(indfs[v]){
            found_cycle=1;
            return;
        }
    }
    ans[cnt--]=u;
    indfs[u]=0;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int v,x,y,N=m+1,z;
    REP(j,n){
        cnt=0;
        FOR(i,1,m){
            scanf("%d",&v);
            if(v==-1) continue;
            list[++cnt].v=v;
            list[cnt].id=i;
        }
        sort(list+1,list+cnt+1,cmp);
        x=1; z=m+1;
        while(x<=cnt){
            y=x;
            while(y<cnt && list[y+1].v==list[x].v) y++;
            FOR(it,x,y) a[z].pb(list[it].id);
            z=++N;
            FOR(it,x,y) a[list[it].id].pb(z);
            x=y+1;
        }
    }
    reset(free1,1); reset(indfs,0);
    cnt=N; found_cycle=0;
    FOR(i,1,N) if(free1[i]) dfs(i);
    
    if(found_cycle) puts("-1");
    else
        FOR(i,1,N) if(ans[i]<=m) printf("%d ",ans[i]);
    
    return 0;
}
