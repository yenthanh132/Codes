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
typedef pair<pii, int> piii;

const int maxn = 507;

int n,m,d[maxn][maxn][2],trace[maxn][maxn][2];
vector<int> a[maxn];
vector<pii> list;
queue<piii> myqueue;

#include <conio.h>
int main(){
    int u,v,x,y,k;
    
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    REP(i,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
    }
    
    FOR(i,1,n) FOR(j,1,n) REP(k,2) d[i][j][k]=oo;
    d[1][n][0]=0;
    myqueue.push(mp(mp(1,n),0));
    
    while(!myqueue.empty() && d[n][1][0]==oo){
        u=myqueue.front().fi.fi; v=myqueue.front().fi.se; k=myqueue.front().se; myqueue.pop();
        if(k==0)
            REP(i,sz(a[u])){
                x=a[u][i];
                if(d[x][v][1]!=oo) continue;
                d[x][v][1]=d[u][v][0];
                trace[x][v][1]=u;
                myqueue.push(mp(mp(x,v),1));
            }
        else
            REP(i,sz(a[v])){
                y=a[v][i];
                if(d[u][y][0]!=oo || y==u) continue;
                d[u][y][0]=d[u][v][1]+1;
                trace[u][y][0]=v;
                myqueue.push(mp(mp(u,y),0));
            }
    }
    
    if(d[n][1][0]==oo) printf("-1\n");
    else{
        printf("%d\n",d[n][1][0]);
        u=n; v=1; list.pb(mp(u,v));
        while(u!=1 || v!=n){
            y=trace[u][v][0]; x=trace[u][y][1];
            u=x; v=y;
            list.pb(mp(x,y));
        }
        REPD(i,sz(list)) printf("%d ",list[i].fi);
        printf("\n");
        REPD(i,sz(list)) printf("%d ",list[i].se);
    }
    
    //getch();
    return 0;
}
        
            
        
