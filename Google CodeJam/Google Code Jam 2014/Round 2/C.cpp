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

const int maxn=1111;

struct rec{
    ll x1, y1, x2, y2;
}a[maxn];
ll d[maxn][maxn],n,w,h;

ll dist(int i, int j){
    if(a[i].x1>a[j].x1) swap(i,j);
    ll max1=max(0ll,a[j].x1-a[i].x2-1);
    if(a[i].y1>a[j].y1) swap(i,j);
    ll max2=max(0ll,a[j].y1-a[i].y2-1);
    return max(max1,max2);
}

bool free1[maxn];
ll dis[maxn];

ll dijkstra(int s, int t){
    FOR(i,1,n) dis[i]=oo;
    dis[s]=0;
    reset(free1,1);
    while(1){
        int u=-1,minv=oo;
        FOR(i,1,n) if(free1[i] && dis[i]<minv){
            u=i;
            minv=dis[i];
        }
        if(u==-1) break;
        free1[u]=0;
        FOR(v,1,n) if(free1[v] && dis[v]>dis[u]+d[u][v]) dis[v]=dis[u]+d[u][v];
    }
    return dis[t];
}

int main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    int T;
    cin>>T;
    FOR(tt,1,T){
        cin>>w>>h>>n;
        FOR(i,1,n){
            cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        }
        a[++n].y1=0;
        a[n].y2=h;
        a[n].x1=a[n].x2=-1;

        a[++n].y1=0;
        a[n].y2=h;
        a[n].x1=a[n].x2=w;

        FOR(i,1,n) FOR(j,i+1,n) d[i][j]=d[j][i]=dist(i,j);

        printf("Case #%d: %I64d\n",tt,dijkstra(n-1,n));
    }
}

