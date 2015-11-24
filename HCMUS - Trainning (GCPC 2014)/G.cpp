#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=307;
const int maxm=200007;

struct Edge{
    int x,y,c,f;
    Edge(){}
    Edge(int _x, int _y, int _c, int _f){
        x=_x; y=_y; c=_c; f=_f;
    }
}e[maxm];
int S,F,N,M,m,n,p,T;
int head[maxn], jmp[maxm];

void addEdge(int u, int v, int c){
    jmp[M] = head[u];
    e[M] = Edge(u,v,c,0);
    head[u] = M++;
    jmp[M] = head[v];
    e[M] = Edge(v,u,0,0);
    head[v] = M++;
}

int myq[maxn],first,last,trace[maxn];

bool findpath(){
    myq[first=last=1]=S;
    for(int u=1; u<=N; ++u) trace[u]=-1; trace[S]=0;
    while(first<=last){
        int u=myq[first++];
        for(int i=head[u]; i!=-1; i=jmp[i]) if(e[i].c>e[i].f){
            int v=e[i].y;
            if(trace[v]==-1){
                trace[v]=i;
                myq[++last]=v;
                if(v==F){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void incflow(){
    int v,i,delta=oo;
    v=F;
    while(v!=S){
        i=trace[v];
        delta=min(delta,e[i].c-e[i].f);
        v=e[i].x;
    }
    v=F;
    while(v!=S){
        i=trace[v];
        e[i].f+=delta; e[i^1].f-=delta;
        v=e[i].x;
    }
}

int maxflow(){
    int res = 0;
    while(findpath()) incflow();
    for(int i=head[S]; i!=-1; i=jmp[i]) res += e[i].f;
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d%d%d",&m,&n,&p);
        S=m+n+1; N=F=m+n+2;
        reset(head,-1);
        M=0;
        for(int i=1; i<=m; ++i) addEdge(S,i,1);
        for(int i=1; i<=n; ++i) addEdge(i+m,F,1);
        double x,y;
        for(int i=0; i<p; ++i){
            scanf("%lf%lf",&x,&y);
            int ix=(int)x, iy=(int)y;
            if(ix<m) ++ix; if(iy<n) ++iy;
            addEdge(ix,iy+m,oo);
        }
        cout<<maxflow()<<endl;
    }
}

