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

const int maxn=207;

int n1,n2,m,n,a1[maxn],a2[maxn],b[maxn];
bool free1[maxn];
char buf[10];


//maximum matching

int k,fx[maxn],fy[maxn],trace[maxn],tracef[maxn],cost[maxn][maxn],mX[maxn],mY[maxn],d[maxn];
queue<int> myq;

void init(){
    k=max(n1,m);
    FOR(i,1,k) FOR(j,1,k) cost[i][j]=oo;
    FOR(i,1,n1) FOR(j,1,m) if(a1[i]<b[j]) cost[i][j]=a1[i]-b[j];
    reset(mX,0); reset(mY,0);
    FOR(i,1,k){
        fx[i]=oo;
        FOR(j,1,k) fx[i]=min(fx[i],cost[i][j]);
    }
    FOR(j,1,k){
        fy[j]=oo;
        FOR(i,1,k) fy[j]=min(fy[j],cost[i][j]-fx[i]);
    }
}

int getC(int i, int j){
    return cost[i][j]-fx[i]-fy[j];
}

void initBFS(int start){
    reset(trace,0);
    FOR(i,1,k){
        d[i]=getC(start,i);
        tracef[i]=start;
    }
    myq=queue<int>();
    myq.push(start);
}

int findpath(){
    int u,v,w;
    while(!myq.empty()){
        u=myq.front(); myq.pop();
        FOR(v,1,k) if(trace[v]==0){
            w=getC(u,v);
            if(w==0){
                trace[v]=u;
                if(mY[v]==0) return v;
                myq.push(mY[v]);   
            }else if(w<d[v]){
                d[v]=w;
                tracef[v]=u;
            }
        }
    }   
    return 0;
}

int rotate_path(int start){
    int delta=oo;   
    FOR(v,1,k) if(trace[v]==0) delta=min(delta,d[v]);
    fx[start]+=delta;
    FOR(v,1,k) if(trace[v]>0){
        int u=mY[v];
        fx[u]+=delta;
        fy[v]-=delta;
    }else d[v]-=delta;
    FOR(v,1,k) if(trace[v]==0 && d[v]==0){
        trace[v]=tracef[v];
        if(mY[v]==0) return v;
        myq.push(mY[v]);
    }
    return 0;
}

void enlarge(int f){
    int u,next;
    do{
        u=trace[f];
        next=mX[u];
        mX[u]=f;
        mY[f]=u;
        f=next;   
    }while(f!=0);
}
    
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    n1=n2=0;
    int v;
    REP(i,n){
        scanf("%s%d",buf,&v);
        if(buf[0]=='A'){
            a1[++n1]=v;   
        }else a2[++n2]=v;
    }
    FOR(j,1,m) scanf("%d",&b[j]);
    reset(free1,1);
    int res=-oo,val;
    // Del all of opp 's card
    if(m>n){
        val=0;
        FOR(i,1,n2){
            int u=-1;
            FOR(j,1,m) if(free1[j] && b[j]>=a2[i] && (u==-1 || b[j]<b[u])) u=j;
            if(u==-1) goto out;
            free1[u]=0;
        }
        FOR(i,1,n1){
            int u=-1;
            FOR(j,1,m) if(free1[j] && b[j]>=a1[i] && (u==-1 || b[j]<b[u])) u=j;
            if(u==-1) goto out;
            free1[u]=0;
            val+=b[u]-a1[i];
        }
        FOR(j,1,m) if(free1[j]) val+=b[j];
        res=max(res,val);
    }
    
out:
    
    //Maximum matching
    init();
    FOR(u,1,k){
        initBFS(u);
        int finish=0;
        do{
            finish=findpath();
            if(finish==0) finish=rotate_path(u);
        }while(finish==0);
        enlarge(finish);
    }
    val=0;
    FOR(u,1,k) if(cost[u][mX[u]]!=oo) val-=cost[u][mX[u]];
    res=max(res,val);
    
    cout<<val<<endl;
    
    getch();
    return 0;
}
