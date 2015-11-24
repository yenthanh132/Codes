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

int n;
ll val[maxn],Dec[maxn],inc[maxn];
vector<int> a[maxn];
bool free1[maxn];

void dfs(int u, int p){
    int v;
    ll maxDec,maxinc,maxval,minval;
    maxDec=maxinc=maxval=minval=0;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        dfs(v,u);
        maxDec=max(maxDec,Dec[v]);
        maxinc=max(maxinc,inc[v]);
    }
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        if(val[v]<0){
            if(inc[v]<maxinc) val[v]=min(val[v]+maxinc-inc[v],0ll);
        }else{
            if(Dec[v]<maxDec) val[v]=max(val[v]-(maxDec-Dec[v]),0ll);
        }
        maxval=max(maxval,val[v]);
        minval=min(minval,val[v]);
    }
    val[u]-=maxval+minval;
    val[u]+=maxinc;
    val[u]-=maxDec;
    inc[u]=maxinc-minval;
    Dec[u]=maxDec+maxval;
}
    
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int u,v;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    FOR(i,1,n) scanf("%I64d",&val[i]);
    dfs(1,-1);
    printf("%I64d\n",inc[1]+Dec[1]+abs(val[1]));
    return 0;
}
