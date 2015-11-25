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

const int maxn=200077;
const int maxm=maxn*4;

struct edge{int x,y,c,f;} e[maxm];
int m,next[maxm],head[maxn],current[maxn],excess[maxn],counth[maxn*2],h[maxn];
queue<int> myqueue;

int n,N,s,s0,t,S,T,degin[maxn],degout[maxn];

void pushe(int u, int v, int c){
    e[++m].x=u; e[m].y=v; e[m].c=c; e[m].f=0;
    next[m]=head[u]; head[u]=m;
    e[++m].x=v; e[m].y=u; e[m].c=e[m].f=0;
    next[m]=head[v]; head[v]=m;
}

#define _(u) (u&1?u+1:u-1)

void init(){
    reset(excess,0); reset(counth,0);
    FOR(i,1,m) e[i].f=0;
    FOR(i,1,n) current[i]=head[i];
    int i=head[S];
    while(i!=0){
        e[i].f=e[i].c; 
        excess[e[i].y]+=e[i].c;
        excess[e[i].x]-=e[i].c;
        e[_(i)].f=-e[i].c;
        i=next[i];
    }
    counth[1]=n-2; counth[n]=1; counth[0]=1;
    FOR(i,1,n) h[i]=1; h[S]=n; h[T]=0;
    myqueue=queue<int>();
    FOR(y,1,n) if(y!=S && y!=T && excess[y]>0) myqueue.push(y);
}

void pushflow(int i){
    int delta=min(excess[e[i].x],e[i].c-e[i].f);
    e[i].f+=delta;
    excess[e[i].y]+=delta;
    excess[e[i].x]-=delta;
    e[_(i)].f-=delta;
}

void seth(int u, int newh){
    counth[h[u]]--;
    h[u]=newh;
    counth[newh]++;
}

void performgap(int gap){
    if(0<gap && gap<n && counth[gap]==0)
        FOR(u,1,n)
            if(u!=S && gap<h[u] && h[u]<=n){
                seth(u,n+1);
                current[u]=head[u];
            }
}                

void lift(int u){
    int minh=n*2,i=head[u],gap;
    while(i!=0){
        if(e[i].f<e[i].c && minh>h[e[i].y]) minh=h[e[i].y];
        i=next[i];
    }
    gap=h[u];
    seth(u,minh+1);
    performgap(gap);
}

void FIFOPreflowPush(){
    int u;
    bool needqueue;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        int &cur=current[u];
        while(cur!=0){
            if(h[e[cur].x]>h[e[cur].y] && e[cur].c>e[cur].f){
                needqueue=(e[cur].y!=S && e[cur].y!=T && excess[e[cur].y]==0);
                pushflow(cur);
                if(needqueue) myqueue.push(e[cur].y);
                if(excess[u]==0) break;
            }
            cur=next[cur];
        }
        if(excess[u]!=0){
            current[u]=head[u];
            lift(u);
            myqueue.push(u);
        }
    }
}

bool check(int v){
    e[1].c=v;
    init();
    FIFOPreflowPush();
    return (excess[T]==N-1);
}

//#include <conio.h>
int main(){
    //freopen("Iinput.txt","r",stdin);
    int Test,u,v,res;
    scanf("%d",&Test);
    FOR(index,1,Test){
        scanf("%d",&N); n=N;
        m=0; reset(head,0); reset(degin,0); reset(degout,0);
        s=n+1; s0=n+2; t=n+3; S=n+4; T=n+5; n+=5;
        pushe(s,s0,0); pushe(t,s,oo);
        REP(i,N-1){
            scanf("%d%d",&v,&u);
            v++; u++;
            degin[v]++; degout[u]++;
            pushe(u,v,oo); pushe(S,v,1); pushe(u,T,1);
        }
        FOR(i,1,n-5){
            if(degin[i]==0) pushe(s0,i,oo);
            if(degout[i]==0) pushe(i,t,oo);
        }
        res=N;
        int l=1, r=N-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        printf("Case %d: %d\n",index,res);
    }
    //printf("%0.12lf",1.0*clock()/CLOCKS_PER_SEC);
    //getch();
    return 0;
}
