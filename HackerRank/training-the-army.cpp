#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;
const int maxm=200007;

struct EDGE{
    int x,y,c,f;
}e[maxm];

int head[maxn],cntE,n,t,S,F,Next[maxm];
int trace[maxn],myq[maxn];

void push(int x, int y, int c){
    int i=cntE++;
    e[i].x=x; e[i].y=y; e[i].c=c; e[i].f=0;
    Next[i]=head[x]; head[x]=i;
    i=cntE++;
    e[i].x=y; e[i].y=x; e[i].c=0; e[i].f=0;
    Next[i]=head[y]; head[y]=i;
}

bool findpath(){
    reset(trace,-1);
    int first,last;
    myq[first=last=1]=S;
    while(first<=last){
        int u=myq[first++];
        for(int i=head[u]; i!=-1; i=Next[i])
            if(e[i].c > e[i].f && trace[e[i].y]==-1){
                trace[e[i].y]=i;
                myq[++last]=e[i].y;
            }
    }
    return trace[F]!=-1;
}

int max_flow(){
    while(findpath()){
        for(int i=head[F]; i!=-1; i=Next[i]){
            int u=e[i].y, delta=e[i^1].c-e[i^1].f, j;
            while(u!=S && delta>0){
                if(trace[u]==-1){
                    delta=0;
                    break;
                }
                j=trace[u];
                delta=min(delta,e[j].c-e[j].f);
                u=e[j].x;
            }
            if(delta==0) continue;
            u=e[i].y; e[i^1].f+=delta; e[i].f-=delta;
            while(u!=S){
                j=trace[u];
                e[j].f+=delta;
                e[j^1].f-=delta;
                u=e[j].x;
            }
        }
    }
    int res=0;
    for(int i=head[S]; i!=-1; i=Next[i])
        res+=e[i].f;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    cntE=0;
    reset(head,-1);
    scanf("%d%d",&n,&t);
    S=n+1; F=n+2;
    for(int i=1,v; i<=n; ++i){
        scanf("%d",&v);
        push(S,i,v); push(i,F,1);
    }
    for(int i=1,u,len,v; i<=t; ++i){
        u=i+n+2;
        scanf("%d",&len);
        for(int j=1; j<=len; ++j){
            scanf("%d",&v);
            push(v,u,1);
        }
        scanf("%d",&len);
        for(int j=1; j<=len; ++j){
            scanf("%d",&v);
            push(u,v,1);
        }
    }
    printf("%d\n", max_flow());
}

