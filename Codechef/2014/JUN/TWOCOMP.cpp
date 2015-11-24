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
const int maxr=17;
const int maxm=777;

int f[maxn][maxr],d[maxn];
vector<int> a[maxn];
int n,m1,m2;
int gi1[maxm],gj1[maxm],gk1[maxm],gi2[maxm],gj2[maxm],gk2[maxm];

struct edge{
    int c,f,x,y;
    edge(){}
    edge(int a, int b, int cap){
        x=a; y=b; c=cap; f=0;
    }
}e[maxm*maxm*4];
int N,M,S,F,res,head[maxm*2],next[maxm*maxm*4];

void dfs(int u, int p){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        f[v][0]=u;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    REP(r,maxr) if(((d[v]-d[u])>>r)&1) v=f[v][r];
    if(u==v) return u;
    REPD(r,maxr) if(f[u][r]!=f[v][r]){
        u=f[u][r]; v=f[v][r];
    }
    return f[u][0];
}

int dis(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-d[r]*2;
}

bool overlap(int u, int v){
    int x1=gi1[u], y1=gj1[u], x2=gi2[v], y2=gj2[v];
    int r1=lca(x1,y1), r2=lca(x2,y2);
    if( dis(x1,y1)==dis(x1,r2)+dis(r2,y1) || dis(x2,y2)==dis(x2,r1)+dis(r1,y2) ) return 1;
    return 0;
}


//=============================================
//Preflow push
void push_edge(int x, int y, int c){
    e[++M]=edge(x,y,c);
    next[M]=head[x]; head[x]=M;
    e[++M]=edge(y,x,0);
    next[M]=head[y]; head[y]=M;
}

queue<int> myq;
int current[maxm*2],exceed[maxm*2], h[maxm*2], counth[maxm*2];

void init(){
    while(!myq.empty()) myq.pop();
    FOR(u,1,N){
        current[u]=head[u];
        h[u]=1;
    }
    h[S]=N; h[F]=0;
    reset(exceed,0); reset(counth,0);
    counth[1]=N-2; counth[N]=1; counth[0]=1;
    for(int i=head[S]; i; i=next[i]){
        e[i].f = e[i].c; e[i^1].f=-e[i].f;
        exceed[S]-=e[i].f; exceed[e[i].y]+=e[i].f;
    }
    FOR(u,1,N) if(u!=S && u!=F && exceed[u]>0) myq.push(u);
}

void pushE(int i){
    int delta=min(exceed[e[i].x], e[i].c-e[i].f);
    e[i].f += delta; e[i^1].f -= delta;
    exceed[e[i].y]+=delta; exceed[e[i].x]-=delta;
}

void seth(int u, int newh){
    counth[h[u]]--;
    h[u]=newh;
    counth[newh]++;
}

void perform_gap(int gap){
    if(0<gap && gap<N && counth[gap]==0)
        FOR(u,1,N) if(u!=S && gap<h[u] && h[u]<=N){
            seth(u,N+1);
            current[u]=head[u];
        }
}

void lift(int u){
    int minh=N+1;
    for(int i=head[u]; i; i=next[i])
        if(e[i].c>e[i].f) minh=min(minh,h[e[i].y]);
    int old=h[u]; seth(u,minh+1); perform_gap(old);
}

int FIFOPreflowPush(){
    init();
    while(!myq.empty()){
        int z=myq.front(); myq.pop();
        for(;current[z]; current[z]=next[current[z]]){
            edge &ed=e[current[z]];
            if(ed.c>ed.f && h[z]>h[ed.y]){
                bool needqueue = (ed.y!=F && ed.y!=S && exceed[ed.y]==0);
                pushE(current[z]);
                if(needqueue) myq.push(ed.y);
                if(exceed[z]==0) break;
            }
        }
        if(exceed[z]>0){
            lift(z);
            current[z]=head[z];
            myq.push(z);
        }
    }
    return exceed[F];
}
//=============================================

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m1,&m2);
    int x,y;
    REP(i,n-1){
        scanf("%d%d",&x,&y);
        a[x].pb(y); a[y].pb(x);
    }
    d[1]=0;
    dfs(3,-1);
    FOR(r,1,maxr-1) FOR(u,1,n) f[u][r]=f[f[u][r-1]][r-1];

    res=0;
    FOR(i,1,m1) scanf("%d%d%d",&gi1[i],&gj1[i],&gk1[i]), res+=gk1[i];
    FOR(i,1,m2) scanf("%d%d%d",&gi2[i],&gj2[i],&gk2[i]), res+=gk2[i];

    N=m1+m2+2;
    S=N-1; F=N;
    M=1;
    reset(head,0);
    FOR(i,1,m1) push_edge(S,i,gk1[i]);
    FOR(i,1,m2) push_edge(i+m1,F,gk2[i]);
    FOR(i,1,m1) FOR(j,1,m2) if(overlap(i,j)) push_edge(i,m1+j,oo);
    res-=FIFOPreflowPush();

    printf("%d\n",res);

    return 0;
}
