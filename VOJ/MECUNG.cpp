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

vector<pii> a[maxn];
int n,d[maxn],myq[maxn],first,last,m,minv[maxn],color[maxn];
vector<int> list;
pii myq2[maxn],trace[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v,c;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&c);
        a[u].pb(pii(v,c));
        a[v].pb(pii(u,c));
    }
    //BFS 1
    reset(d,-1);
    d[n]=0;
    myq[first=last=1]=n;
    while(first<=last){
        u=myq[first++];
        REP(i,sz(a[u])){
            v=a[u][i].fi;
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            myq[++last]=v;
        }
    }
    
    //BFS 2
    first=1; last=0;
    FOR(i,1,d[1]) minv[i]=oo;
    FOR(i,1,n) color[i]=oo;
    REP(i,sz(a[1])){
        v=a[1][i].fi; c=a[1][i].se;
        if(d[v]+1==d[1] && color[v]>c){
            color[v]=c;
            minv[1]=min(minv[1],c);
            trace[v]=pii(1,c);
            myq2[++last]=pii(v,1);
        }
    }
    int step;
    while(first<=last){
        u=myq2[first].fi; step=myq2[first++].se;
        if(color[u]>minv[step]) continue;
        REP(i,sz(a[u])){
            v=a[u][i].fi; c=a[u][i].se;
            if(d[v]+step+1==d[1] && color[v]>c){
                color[v]=c;
                minv[step+1]=min(minv[step+1],c);
                trace[v]=pii(u,c);
                myq2[++last]=pii(v,step+1);
            }
        }
    }
    
    //Trace back
    printf("%d\n",d[1]);
    u=n;
    while(u!=1){
        list.pb(trace[u].se);
        u=trace[u].fi;
    }
    REPD(i,sz(list)) printf("%d ",list[i]);
    puts("");
    
    //getch();
    return 0;
}
