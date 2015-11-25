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

int m,n,res,mX[64],mY[64],dis[64];
vector<int> a[64];
char s[64];
bool found1;

bool findpath(){
    queue<int> myqueue;
    FOR(i,1,m) if(mX[i]==0){
        myqueue.push(i);
        dis[i]=0;
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) myqueue.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    FOR(index,1,T){
        scanf("%d%d\n",&m,&n);
        found1=0;
        FOR(i,1,m){
            a[i].clear();
            gets(s);        
            REP(j,n) if(s[j]=='0') a[i].pb(j+1); else found1=1;
        }
        res=0;
        reset(mX,0); reset(mY,0);
        while(findpath()) FOR(u,1,m) if(mX[u]==0 && dfs(u)) res++;
        if(res==min(m,n)) res=found1*2; else res=m+n-res;
        printf("Case %d: %d\n",index,res);
    }
    getch();
    return 0;
}
