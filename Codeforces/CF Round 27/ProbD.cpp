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

const int maxn=107;

vector<int> a[maxn];
pii e[maxn];
int n,m,col[maxn];
bool free1[maxn],ok;

bool match(int i, int j){
    return (e[j].fi<e[i].se && e[i].se<e[j].se && e[i].fi<e[j].fi && e[j].fi<e[i].se);
}

void dfs(int u, int c){
    if(!ok) return;
    free1[u]=0;
    col[u]=c;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v,1-c);
        else if(col[v]==c){
            ok=0;
            return;
        }
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    FOR(i,1,m){
        cin>>e[i].fi>>e[i].se;
        if(e[i].fi>e[i].se) swap(e[i].fi,e[i].se);
    }
    FOR(i,1,m-1) FOR(j,i+1,m) if(match(i,j) || match(j,i)){
        a[i].pb(j);
        a[j].pb(i);
    }
    reset(free1,1);
    ok=1;
    FOR(i,1,m){
        if(!ok) break;
        if(free1[i]) dfs(i,0);
    }
    if(ok){
        FOR(i,1,m) if(col[i]==0) cout<<'i'; else cout<<'o';
    }else cout<<"Impossible";
    //getch();
    return 0;
}
        
