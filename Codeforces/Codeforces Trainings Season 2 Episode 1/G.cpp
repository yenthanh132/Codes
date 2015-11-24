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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;

int x[maxn],y[maxn],n,m;
int lab[maxn],d[maxn],trace[maxn];
bool free1[maxn];

int dis(int i, int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void join(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) lab[i]=-1;
    int u,v;
    for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
    scanf("%d",&m);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        int r1=getroot(u), r2=getroot(v);
        if(r1!=r2) join(r1,r2);
    }

    d[1]=0; for(int i=2; i<=n; ++i) d[i]=oo;
    reset(free1,1); reset(trace,0);
    for(int rr=0; rr<n-1; ++rr){
        int u=-1, minv=oo;
        for(int i=1; i<=n; ++i) if(free1[i] && minv>d[i]){
            u=i;
            minv=d[i];
        }
        free1[u]=0;
        for(int v=1; v<=n; ++v) if(free1[v]){
            int vd=dis(u,v);
            if(getroot(u)==getroot(v)) vd=0;
            if(d[v]>vd){
                d[v]=vd;
                trace[v]=u;
            }
        }
    }

    for(int u=1; u<=n; ++u) if(trace[u]){
        int v=trace[u];
        if(getroot(u)!=getroot(v)) printf("%d %d\n",u,v);
    }
}
