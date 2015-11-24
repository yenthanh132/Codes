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

const int maxn=50;

vector<int> a[maxn],tmp,alone;
vector< vector<int> > list;
int m,n,deg[maxn];
bool free1[maxn];

void dfs(int u){
    free1[u]=0;
    tmp.pb(u);
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v);
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    int u,v;
    REP(i,m){
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
        deg[u]++; deg[v]++;
    }
    FOR(i,1,n) if(deg[i]==0) alone.pb(i);
    reset(free1,1); 
    FOR(i,1,n) if(free1[i] && deg[i]){
        tmp.clear();
        dfs(i);
        if(sz(tmp)>3 || 3-sz(tmp)>sz(alone)){
            puts("-1");
            return 0;
        }
        REP(j,3-sz(tmp)){        
            tmp.pb(alone.back());
            alone.pop_back();
        }
        list.pb(tmp);
    }    
    while(!alone.empty()){
        tmp.clear();
        REP(j,3){        
            tmp.pb(alone.back());
            alone.pop_back();
        }
        list.pb(tmp);
    }
    REP(i,n/3){
        REP(j,3) cout<<list[i][j]<<' ';
        cout<<endl;
    }
    
    //getch();
    return 0;
}
