#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int n,q;
map<int,int> cost[maxn];
int C[maxn][maxn],fx[maxn],fy[maxn],matchX[maxn],matchY[maxn],trace[maxn],d[maxn],tracef[maxn];
int myq[maxn],first,last;

void init(){
    for(int u=1; u<=n; ++u) for(int v=1; v<=n; ++v) C[u][v]=oo;
    reset(matchX,0); reset(matchY,0);
    reset(fx,0); reset(fy,0);
}

int getCost(int u, int v){ return C[u][v] - fx[u] - fy[v]; }

void initBFS(int start){
    reset(trace,0);
    for(int v=1; v<=n; ++v){
        tracef[v]=start;
        d[v]=getCost(start,v);
    }
    first=last=1;
    myq[1]=start;
}

int findpath(){
    while(first<=last){
        int u=myq[first++];
        for(int v=1; v<=n; ++v) if(trace[v]==0){
            int w=getCost(u,v);
            if(w==0){
                trace[v]=u;
                if(matchY[v]==0) return v;
                myq[++last]=matchY[v];
            }else if(d[v]>w){
                d[v]=w;
                tracef[v]=u;
            }
        }
    }
    return -1;
}

void enlarge(int v){
    int u,next;
    while(v){
        u=trace[v];
        next=matchX[u];
        matchX[u]=v;
        matchY[v]=u;
        v=next;
    }
}

int rotate_path(int start){
    int delta=oo;
    for(int v=1; v<=n; ++v) if(trace[v]==0) delta=min(delta,d[v]);
    fx[start]+=delta;
    for(int v=1; v<=n; ++v) if(trace[v]){
        int u=matchY[v];
        fx[u]+=delta;
        fy[v]-=delta;
    }else
        d[v]-=delta;
    for(int v=1; v<=n; ++v) if(trace[v]==0 && d[v]==0){
        trace[v]=tracef[v];
        if(matchY[v]==0) return v;
        myq[++last]=matchY[v];
    }
    return -1;
}

int find_min_matching(){
    for(int u=1; u<=n; ++u){
        initBFS(u);
        int finish;
        do{
            finish=findpath();
            if(finish==-1) finish=rotate_path(u);
        }while(finish==-1);
        enlarge(finish);
    }
    int res=0;
    for(int u=1; u<=n; ++u){
        int v=matchX[u];
        if(C[u][v]==oo) return -1;
        res+=C[u][v];
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        int k,u,c;
        scanf("%d",&k);
        for(int j=0; j<k; ++j){
            scanf("%d%d",&u,&c);
            cost[i][u]=c;
        }
    }
    scanf("%d",&q);
    for(int tt=0; tt<q; ++tt){
        init();
        int v;
        for(int j=1; j<=n; ++j){
            scanf("%d",&v);
            for(int i=1; i<=n; ++i)
                if(cost[i].count(v))
                    C[i][j]=cost[i][v];
        }
        printf("%d\n",find_min_matching());
    }

}

