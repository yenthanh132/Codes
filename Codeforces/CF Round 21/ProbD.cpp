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

int n,m,deg[16],lab[16];
ll a[16][16],res,f[1<<16];

ll getv(int id){
    if(id==0) return 0;
    if(f[id]!=-1) return f[id];
    f[id]=oo;
    vector<int> bit; REP(i,n) if((id>>i)&1) bit.pb(i);
    REP(i,sz(bit)-1) FOR(j,i+1,sz(bit)-1)
        f[id]=min(f[id],getv(id-(1<<bit[i])-(1<<bit[j]))+a[bit[i]][bit[j]]);
    return f[id];
}

int getroot(int u){
    if(lab[u]<0) return u;
    int r=getroot(lab[u]);
    lab[u]=r;
    return r;
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v,w;
    REP(i,n) REP(j,n) a[i][j]=oo; 
    reset(deg,0); REP(i,n) lab[i]=-1;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&w);
        u--; v--;
        deg[u]++; deg[v]++;
        dsu(u,v);
        a[u][v]=a[v][u]=min(a[u][v],ll(w));
        res+=w;
    }
    FOR(j,1,n-1) if(deg[j]>0 && getroot(j)!=getroot(0)){
        printf("-1\n");
        //getch();
        return 0;
    }
    REP(k,n) REP(i,n) REP(j,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    REP(i,1<<n) f[i]=-1;
    int id=0; REP(i,n) if(deg[i]&1) id|=1<<i;
    printf("%I64d\n",res+getv(id));
    //getch();
    return 0;
}
    
