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

const int maxn=100007;
const int maxp=200007;
const int maxv=2000000;

bool isprime[maxv+7];
int list[maxp],idx[maxv+7],cnt,n,q;
int val[maxn],ans[maxn];
vector<int> e[maxn];
vector<pii> pv[maxp];

void verify(pii &best, int fac){
     if(!pv[idx[fac]].empty()) best=max(best,pv[idx[fac]].back());
}

void dfs(int u, int p, int depth){
    int x=val[u];
    pii best=pii(-1,-1);
    for(int i=1; list[i]*list[i]<=x; ++i) if(x%list[i]==0){
        int fac = list[i];
        while(x%fac==0) x/=fac;
        verify(best,fac);
        pv[idx[fac]].pb(pii(depth,u));
    }
    if(x>1){
        verify(best,x);
        pv[idx[x]].pb(pii(depth,u));
    }

    if(best.first!=-1) ans[u]=best.second; else ans[u]=-1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u,depth+1);
    }
    x=val[u];
    for(int i=1; list[i]*list[i]<=x; ++i) if(x%list[i]==0){
        int fac = list[i];
        while(x%fac==0) x/=fac;
        pv[idx[fac]].pop_back();
    }
    if(x>1) pv[idx[x]].pop_back();
}

int main(){

    //freopen("input.txt","r",stdin);

    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; ++i) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=i*2) isprime[j]=0;
    list[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) list[++cnt]=i, idx[i]=cnt;


    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&val[i]);
    int x,y,t;
    for(int i=0; i<n-1; ++i){
        scanf("%d%d",&x,&y);
        e[x].pb(y); e[y].pb(x);
    }
    dfs(1,-1,0);

    for(int i=0; i<q; ++i){
        scanf("%d%d",&t,&x);
        if(t==1) printf("%d\n",ans[x]);
        else{
            scanf("%d",&y);
            val[x]=y;
            dfs(1,-1,0);
        }
    }

    return 0;
}
