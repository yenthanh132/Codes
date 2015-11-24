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

const int maxn = 1007;

int n,a[maxn][maxn],next[maxn],d[maxn];
bool free1[maxn];
vector<pii> list;
set<pii> oldedge;

void prim(){
    d[1]=0;
    next[1]=0;
    FOR(i,2,n) d[i]=oo;
    reset(free1,1);
    int minv,u;        
    
    REP(k,n-1){
        minv=oo;
        FOR(i,1,n) if(free1[i] && minv>d[i]) minv=d[i],u=i;
        free1[u]=0;
        FOR(v,1,n) if(free1[v] && d[v]>a[u][v]){
            d[v]=a[u][v];
            next[v]=u;
        }
    }
}

#include <conio.h>
int main(){
    int u,v;
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(u,1,n) FOR(v,1,n) a[u][v]=1;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u][v]=a[v][u]=0;
        if(u>v) swap(u,v);
        oldedge.insert(pii(u,v));
    }
    prim();
    FOR(i,2,n){
        v=i;
        u=next[v];
        if(u>v) swap(u,v);
        if(a[u][v]==1) list.pb(pii(u,v)); else oldedge.erase(oldedge.find(pii(u,v)));
    }
    printf("%d\n",sz(list));
    REP(i,sz(list)){
        printf("%d %d %d %d\n",oldedge.begin()->fi,oldedge.begin()->se,list[i].fi,list[i].se);
        oldedge.erase(oldedge.begin());
    }
    //getch();
    return 0;
}
