
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

int n,k,p,a[maxn],id[maxn],com[maxn],cnt;
vector<int> e[maxn];

bool cmp(const int &i, const int &j){
    return a[i]<a[j];
}

void dfs(int u){
    com[u]=cnt;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(com[v]==0) dfs(v);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&p);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) id[i]=i;
    sort(id+1,id+n+1,cmp);
    FOR(i,1,n-1){
        int u=id[i], v=id[i+1];
        if(a[v]-a[u]>k) continue;
        e[u].pb(v); e[v].pb(u);

    }
    reset(com,0);
    FOR(u,1,n) if(com[u]==0){
        ++cnt;
        dfs(u);
    }

    REP(i,p){
        int u,v;
        scanf("%d%d",&u,&v);
        if(com[u]==com[v]) puts("Yes"); else puts("No");
    }

    return 0;
}
