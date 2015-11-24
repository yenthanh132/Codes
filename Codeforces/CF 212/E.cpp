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

const int maxn=55;
int c[maxn][maxn],f[maxn][maxn],n,k;
int trace[maxn],d[maxn],myq[maxn];
bool free1[maxn];

bool findpath(){
    int first=1, last=0;
    reset(trace,0);
    trace[1]=-1;
    myq[++last]=1;
    int u;
    while(first<=last){
        u=myq[first++];
        FOR(v,1,n) if(f[u][v]<c[u][v] && trace[v]==0){
            trace[v]=u;
            myq[++last]=v;
        }
    }
    return trace[n]!=0;
}

void incflow(){
    int delta=oo;
    int u,v;
    v=n;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        v=u;
    }while(v!=1);
    v=n;
    do{
        u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }while(v!=1);
}



int minpath(){
    FOR(u,1,n) d[u]=oo;
    d[1]=0; trace[1]=-1;
    reset(free1,1);
    while(1){
        int u=-1, minv=oo;
        FOR(v,1,n) if(free1[v] && d[v]<minv){
            minv=d[v];
            u=v;
        }
        if(u==-1) break;
        free1[u]=0;
        FOR(v,1,n) if(free1[v] && c[u][v]!=oo && d[v]>d[u]+(c[u][v]==0)){
            d[v]=d[u]+(c[u][v]==0);
            trace[v]=u;
        }
    }
    if(d[n]==oo) return oo;
    int v=n,u;
    do{
        u=trace[v];
        if(c[u][v]) c[u][v]--;
        v=u;
    }while(v!=1);
    return d[n];
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>k;
    FOR(i,1,n) FOR(j,1,n) cin>>c[i][j];
    reset(f,0);
    while(findpath()) incflow();
    int res=0;
    FOR(v,1,n) res+=f[1][v];
    FOR(u,1,n) FOR(v,1,n){
        if(u==v) c[u][v]=0;
        else if(c[u][v]==0) c[u][v]=oo;
        else c[u][v]-=f[u][v];
    }
    int x;
    while((x=minpath())<=k){
        k-=x;
        ++res;
    }
    cout<<res<<endl;
}

