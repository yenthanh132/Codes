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

const int maxn=407;

int st,fi,m,n,c[maxn][maxn],f[maxn][maxn],a[maxn][maxn],N,d[maxn],trace[maxn];
bool free1[maxn];

int val(int v){
    if(v>=0) return 1; else return -1;
}

bool findpath(){
    deque<int> q;
    reset(free1,1); free1[st]=0;
    q.push_back(st);
    FOR(i,1,N) d[i]=oo; d[st]=0;
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop_front();
        free1[u]=1;
        FOR(v,1,N) if(c[u][v]>f[u][v] && d[v]>d[u]+a[u][v]*val(f[u][v])){
            d[v]=d[u]+a[u][v]*val(f[u][v]);
            trace[v]=u;
            if(free1[v]){
                free1[v]=0;
                q.push_back(v);
            }
        }
    }
    return d[fi]!=oo;
}

void incflow(){
    int u,v=fi,delta=oo;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        v=u;
    }while(v!=st);
    v=fi;
    do{
        u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }while(v!=st);
}
           
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&m,&n);
        st=m+n+1; fi=st+1;
        N=fi;
        reset(a,0); reset(c,0); reset(f,0);
        FOR(i,1,m) scanf("%d",&c[st][i]);
        FOR(i,1,n) scanf("%d",&c[i+m][fi]);
        FOR(i,1,m) FOR(j,1,n){
            scanf("%d",&a[i][j+m]);
            c[i][j+m]=oo;
        }
        while(findpath()) incflow();
        ll res=0;
        FOR(i,1,m) FOR(j,1,n) res+=1ll*a[i][j+m]*f[i][j+m];
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
