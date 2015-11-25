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

const int maxn = 301;

int T,n,k,res,v[maxn],dis[maxn],matchX[maxn],matchY[maxn];
vector<int> a[maxn];
queue<int> myqueue;

bool findpath(){
    myqueue=queue<int>();
    FOR(i,1,n)
        if(matchX[i]==0){
            dis[i]=0;
            myqueue.push(i);
        }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    vector<int>::iterator it;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        for(it=a[u].begin(); it!=a[u].end(); it++){
            v=*it;
            if(dis[matchY[v]]==oo){
                dis[matchY[v]]=dis[u]+1;
                if(matchY[v]!=0) myqueue.push(matchY[v]);
            }
        }
    }
    return(dis[0]!=oo);
}

bool dfs(int u){
    if(u==0) return true;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[matchY[v]]==dis[u]+1 && dfs(matchY[v])){
            matchX[u]=v;
            matchY[v]=u;
            return true;
        }
    }
    dis[u]=oo;
    return false;
}

int domatching(){
    reset(matchX,0); reset(matchY,0);
    int res=0;
    while(findpath()) FOR(i,1,n) if(matchX[i]==0 && dfs(i)) res++;
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%d",v+i), a[i]=vector<int>();
        FOR(i,1,n-1) FOR(j,i+1,n) if(abs(v[i]-v[j])>=k) a[i].pb(j);
        res=n-domatching();
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
        
