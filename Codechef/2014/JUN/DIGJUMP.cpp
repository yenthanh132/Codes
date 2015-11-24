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

const int maxn=111111;
char s[maxn];
int n,d[maxn],free1[maxn];
vector<pii> e[maxn];
set<pii> mys;

void dijkstra(){
    FOR(u,1,n+10) d[u]=oo;
    d[1]=0;
    reset(free1,1);
    mys.insert(pii(0,1));
    while(!mys.empty()){
        int u=mys.begin()->se; mys.erase(mys.begin());
        free1[u]=0;
        REP(i,sz(e[u])){
            int v=e[u][i].fi, w=e[u][i].se;
            if(free1[v] && d[v]>d[u]+w){
                if(d[v]!=oo) mys.erase(pii(d[v],v));
                d[v]=d[u]+w;
                mys.insert(pii(d[v],v));
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    FOR(i,1,n){
        if(i>1) e[i].pb(pii(i-1,2));
        if(i<n) e[i].pb(pii(i+1,2));
        e[i].pb(pii(n+s[i]-'0'+1,1));
        e[n+s[i]-'0'+1].pb(pii(i,1));
    }
    dijkstra();
    printf("%d\n",d[n]/2);
}
