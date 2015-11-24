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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int > plli;

const int maxn = 100007;

set<plli> myset;
vector<pii> a[maxn];
vector<int> list;
bool free1[maxn];
int n,m,trace[maxn];
ll d[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v,w;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&w);
        a[u].pb(pii(v,w));
        a[v].pb(pii(u,w));
    }
    reset(free1,1);
    d[1]=0; 
    FOR(i,2,n) d[i]=oo;
    myset.insert(pii(0,1));
    while(!myset.empty()){
        u=myset.begin()->se; myset.erase(myset.begin());
        free1[u]=0;
        REP(i,sz(a[u])){
            v=a[u][i].fi; w=a[u][i].se;
            if(free1[v] && d[v]>d[u]+w){
                if(d[v]!=oo) myset.erase(myset.find(plli(d[v],v)));
                d[v]=d[u]+w;
                trace[v]=u;
                myset.insert(plli(d[v],v));
            }
        }
    }
    
    if(d[n]==oo) printf("-1\n");
    else{
        u=n;
        while(u!=1){
            list.pb(u);
            u=trace[u];
        }
        list.pb(1);
        REPD(i,sz(list)) printf("%d ",list[i]);
    }
    //getch();
    return 0;
}
    
