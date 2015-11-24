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

const int maxn = 107;

int n,m,c,res;
vector<int> a[maxn];
bool free1[maxn],indfs[maxn], ck;

void dfs(int u, int p){
    int v;
    free1[u]=0; indfs[u]=1; c++;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v,u);
        else if(v!=p && indfs[v]) ck=1;
    }
    indfs[u]=0;
}

#include <conio.h>
int main(){
    ///freopen("test.txt","r",stdin);
    cin>>n>>m;
    int u,v,ckle=0;
    REP(i,m){
        cin>>u>>v;
        a[u].pb(v); a[v].pb(u);
    }
    reset(free1,1); reset(indfs,0);
    FOR(i,1,n) if(free1[i]){
        c=0; ck=0;
        dfs(i,0);
        if(ck && (c&1)) res++;
        else if(c&1) ckle++;
    }
    if(ckle&1) res++;
    cout<<res<<endl;
    //getch();
    return 0;
}
        
