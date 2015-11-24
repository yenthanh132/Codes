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

int n,m,start[maxn],finish[maxn],num,ans[maxn];
vector<int> a[maxn], query[maxn];
bool free1[maxn];

void dfs(int u){
    start[u]=++num;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(start[v]) continue;
        dfs(v);
    }
    finish[u]=num;
}

//IT-------
struct{int minv,c,t;} IT[maxn*4];

void init(int i, int l, int r){
    IT[i].minv=0;
    IT[i].c=r-l+1;
    if(l==r) return;
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
}

void lazy_update(int &i, int &l, int &r){
    if(!IT[i].t) return;
    IT[i].minv+=IT[i].t;
    if(l<r){
        IT[i*2].t+=IT[i].t;
        IT[i*2+1].t+=IT[i].t;
    }
    IT[i].t=0;
}

void update(int i, int l, int r, int &s, int &f, int v){
    lazy_update(i,l,r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        IT[i].t+=v;       
        lazy_update(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,v);
    update(i*2+1,mid+1,r,s,f,v);
    IT[i].minv=min(IT[i*2].minv,IT[i*2+1].minv);
    IT[i].c=0;
    if(IT[i*2].minv==IT[i].minv) IT[i].c+=IT[i*2].c;
    if(IT[i*2+1].minv==IT[i].minv) IT[i].c+=IT[i*2+1].c;
}
    
void dfs2(int u){
    int l,r,v;
    free1[u]=0;
    
    if(!query[u].empty()) update(1,1,n,start[u],finish[u],1);
    REP(i,sz(query[u])){
        l=start[query[u][i]]; r=finish[query[u][i]];
        update(1,1,n,l,r,1);
    }
    
    ans[u]=n-IT[1].c*(IT[1].minv==0);
    if(ans[u]) ans[u]--;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs2(v);
    }
    
    REP(i,sz(query[u])){
        l=start[query[u][i]]; r=finish[query[u][i]];
        update(1,1,n,l,r,-1);
    }
    if(!query[u].empty()) update(1,1,n,start[u],finish[u],-1);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int u,v;
    FOR(i,1,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    num=0;
    dfs(1);
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        query[u].pb(v);
        query[v].pb(u);
    }
    reset(free1,1);
    init(1,1,n);
    dfs2(1);
    FOR(i,1,n) printf("%d ",ans[i]);
    puts("");
    return 0;
}
