#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 207

int n,finish,matchx[maxn],matchy[maxn],fx[maxn],fy[maxn],trace[maxn],tracef[maxn],d[maxn],a[maxn][maxn];
queue<int> myqueue;

void input(){
    scanf("%d",&n);
    int u,v,c;
    for(u=1;u<=n;u++) for(v=1;v<=n;v++) a[u][v]=oo;
    while (scanf("%d%d%d",&u,&v,&c)!=EOF) a[u][v]=c;
}

void init(){
    reset(matchx,0); reset(matchy,0);
    int i,j;
    
    for(i=1;i<=n;i++){
        fx[i]=oo;
        for(j=1;j<=n;j++) fx[i]=min(fx[i],a[i][j]);
    }
    for(j=1;j<=n;j++){
        fy[j]=oo;
        for(i=1;i<=n;i++) fy[j]=min(fy[j],a[i][j]-fx[i]);
    }
}

int getcost(int i,int j){return(a[i][j]-fx[i]-fy[j]);}

void initbfs(int start){
    reset(trace,0);
    int j;
    for(j=1;j<=n;j++){
        tracef[j]=start;
        d[j]=getcost(start,j);
    }
    myqueue=queue<int>(); myqueue.push(start);
}

int findpath(){
    while (!myqueue.empty()){
        int u=myqueue.front(); myqueue.pop();
        for(int v=1;v<=n;v++) if (trace[v]==0){
            int w=getcost(u,v);
            if (w==0){
                trace[v]=u;
                if (matchy[v]==0) return v; else myqueue.push(matchy[v]);
            }else if(w<d[v]){
                d[v]=w;
                tracef[v]=u;
            }
        }
    }
    return -1;
}

void rotatepath(int start){
    int delta=oo,i,j;
    for(i=1;i<=n;i++) if (trace[i]==0) delta=min(delta,d[i]);
    fx[start]+=delta;
    for(i=1;i<=n;i++) if (trace[i]!=0){
        j=matchy[i];
        fx[j]+=delta;
        fy[i]-=delta;
    }else d[i]-=delta;
    for(i=1;i<=n;i++) if (trace[i]==0 && d[i]==0){
        trace[i]=tracef[i];
        if (matchy[i]==0){
            finish=i;
            return;
        }else myqueue.push(matchy[i]);
    }
}

void enlarge(int v){
    int u, next;
    do{
        u=trace[v]; next=matchx[u];
        matchx[u]=v; matchy[v]=u;
        v=next;
    }while (v!=0);
}

void DoMatching(){
    init();
    for(int i=1;i<=n;i++){
        initbfs(i);
        do{
            finish=findpath();
            if (finish==-1) rotatepath(i);
        }while (finish==-1);
        enlarge(finish);
    }
}

#include <conio.h>

int main(){
    freopen("test.txt","r",stdin);
    input();
    DoMatching();
    int res=0;
    for(int i=1;i<=n;i++) if (matchx[i]!=0) res+=a[i][matchx[i]];
    printf("%d\n",res);
    for(int i=1;i<=n;i++) if (matchx[i]!=0) printf("%d %d\n",i,matchx[i]);
    getch();
    return 0;
}
