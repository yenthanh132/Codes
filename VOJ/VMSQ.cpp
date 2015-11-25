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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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
#define maxn 51

int fx[maxn],fy[maxn], trace[maxn], tracef[maxn], d[maxn], cost[maxn][maxn], mX[maxn], mY[maxn];
int n, finish, best;
queue<int> myqueue;
vector< vector<int> > arr,initarr,bestarr;

int getC(int i, int j){ return cost[i][j]-fx[i]-fy[j];}

void init(){
    reset(mX,0); reset(mY,0);
    FOR(i,1,n){
        fx[i]=oo;
        FOR(j,1,n) fx[i]<?=cost[i][j];
    }
    FOR(j,1,n){
        fy[j]=oo;
        FOR(i,1,n) fy[j]<?=cost[i][j]-fx[i];
    }
}

void initBFS(int start){
    reset(trace,0);
    FOR(i,1,n){
        tracef[i]=start;
        d[i]=getC(start,i);
    }
    myqueue=queue<int>(); myqueue.push(start);
}

int findpath(){
    while(!myqueue.empty()){
        int u=myqueue.front(); myqueue.pop();
        FOR(v,1,n) if(trace[v]==0){
            int w=getC(u,v);
            if(w==0){
                trace[v]=u;
                if(mY[v]==0) return v; else myqueue.push(mY[v]);
            }else if(w<d[v]){
                d[v]=w;
                tracef[v]=u;
            }
        }
    }
    return -1;
}

void rotatepath(int start){
    int delta=oo;
    FOR(u,1,n) if(trace[u]==0) delta<?=d[u];
    fx[start]+=delta;
    FOR(u,1,n) if(trace[u]!=0){
        int v=mY[u];
        fx[v]+=delta; fy[u]-=delta;
    }else d[u]-=delta;
    FOR(v,1,n) if(trace[v]==0 && d[v]==0){
        trace[v]=tracef[v];
        if(mY[v]==0){
            finish=v; 
            return;
        }else myqueue.push(mY[v]);
    }
}
    
void enlarge(int f){
    int u, next;
    do{
        u=trace[f]; next=mX[u];
        mX[u]=f; mY[f]=u;
        f=next;
    }while(f!=0);
}

void domatching(){
    init();
    FOR(u,1,n){
        initBFS(u);
        do{
            finish=findpath();
            if(finish==-1) rotatepath(finish);
        }while(finish==-1);
        enlarge(finish);
    }
}   

//----------------------------------

bool cmpfunc(const vector<int> &a, const vector<int> &b){return (a[0]>b[0]);}

int myabs(int a){return (a>0?a:-a);}

void solve(){
    arr=initarr;
    bool free1[maxn],freecol[maxn][maxn];
    reset(freecol,true);
    REP(i,n) FOR(j,1,n) if(arr[i][j]!=-1){
        freecol[j][arr[i][j]]=false;
    }
    REP(i,n){
        reset(free1,true);
        FOR(u,1,n) FOR(v,1,n) cost[u][v]=oo;
        FOR(j,1,n) if(arr[i][j]!=-1) free1[arr[i][j]]=false;
        FOR(j,1,n) if(arr[i][j]==-1)
            FOR(num,1,n) if(free1[num] && freecol[j][num]){
                cost[j][num]=rand()%77777 + 1;
            }
        domatching();
        FOR(u,1,n){
            if(cost[u][mX[u]]!=oo) arr[i][u]=mX[u];
            freecol[u][arr[i][u]]=false;
        }
    }    
    
    int cost=0,v;
    vector<pii> number[maxn];
    REP(i,n) FOR(j,1,n){
        v=arr[i][j];
        if(v==-1) continue;
        REP(k,sz(number[v])) cost+=myabs(i-number[v][k].fi)+myabs(j-number[v][k].se);
        number[v].pb(pii(i,j));
    }
    if(best<cost){
        best=cost;
        bestarr=arr;
    }
}       
    
void output(){
    arr=bestarr;
    REP(i,n) arr[i][0]=arr[i][n+1];
    sort(arr.begin(),arr.end(),cmpfunc);
    REPD(i,n){
        FOR(j,1,n-1) printf("%d ",arr[i][j]);
        printf("%d\n",arr[i][n]);
    }
}
//-------------------------
       
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    REP(i,n){
        vector<int> v;
        v.resize(n+2); v[0]=0;
        FOR(j,1,n){
            scanf("%d",&v[j]);
            if(v[j]!=-1) v[0]++;
        }
        v[n+1]=i;
        initarr.pb(v);
    }
    sort(initarr.begin(),initarr.end(),cmpfunc);
    //----
    best=0;
    srand(time(NULL));
    while(float(clock())/CLOCKS_PER_SEC<=3.5) solve();
    output();
    //----
    
    //getch();
    
    return 0;
}
    
    
