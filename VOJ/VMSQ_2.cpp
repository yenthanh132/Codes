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

int dis[maxn],mX[maxn],mY[maxn];
int n, finish, best;
int link1[maxn][maxn], countlink[maxn];
queue<int> myqueue;
vector< vector<int> > arr,initarr,bestarr;

bool findpath(){
    myqueue=queue<int>();
    FOR(u,1,n) if(mX[u]==0){
        dis[u]=0;
        myqueue.push(u);
    }else dis[u]=oo;
    dis[0]=oo;
    while(!myqueue.empty()){
        int u=myqueue.front(); myqueue.pop();
        FOR(j,1,countlink[u]){
            int v=link1[u][j]; 
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]!=0) myqueue.push(mY[v]);
            }
        }
    }
    return(dis[0]!=oo);
}

bool dfs(int u){
    if(u==0) return true;
    FOR(j,1,countlink[u]){
        int v=link1[u][j];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return true;
        }
    }
    dis[u]=oo;
    return false;
}

void domatching(){
    reset(mX,0); reset(mY,0);
    while(findpath())
        FOR(i,1,n) if(mX[i]==0) dfs(i);
}   

//----------------------------------

bool cmpfunc(const vector<int> &a, const vector<int> &b){return (a[0]>b[0]);}

void solve(){
    arr=initarr;
    int count=0,u,v;
    bool free1[maxn],freecol[maxn][maxn];
    reset(freecol,true);
    REP(i,n) FOR(j,1,n) if(arr[i][j]!=-1) freecol[j][arr[i][j]]=false;
    REP(i,n){
        reset(free1,true); 
        reset(countlink,0);
        FOR(j,1,n) if(arr[i][j]!=-1) free1[arr[i][j]]=false;
        FOR(j,1,n) if(arr[i][j]==-1)
            FOR(num,1,n) if(free1[num] && freecol[j][num])
                link1[j][++countlink[j]]=num;
        FOR(j,1,n) if(countlink[j]>1)
            REP(index,countlink[j]){
                u=rand()%countlink[j]; v=rand()%countlink[j];
                swap(link1[j][u],link1[j][v]);
            }
        domatching();
        FOR(u,1,n){
            if(mX[u]){
                arr[i][u]=mX[u];
                count++;
            }
            if(arr[i][u]!=-1) freecol[u][arr[i][u]]=false;
        }
    }    
    
    if(best<count){
        best=count;
        bestarr=arr;
    }
}       
    
void output(){
    if (best>0)arr=bestarr; else arr=initarr;
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

    best=0;
    srand(time(NULL));
    while(float(clock())/CLOCKS_PER_SEC<=3) 
        solve();
    output();
    
    //getch();
    
    return 0;
}
    
    
