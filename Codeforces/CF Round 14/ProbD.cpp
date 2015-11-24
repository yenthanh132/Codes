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

const int maxn = 201;

vector<int> a[maxn],id[maxn];
bool free1[maxn],free2[maxn];
int n,lockid,d[maxn];

int bfs(int u){
    int v,ans=0;
    queue<int> myqueue;
    free1[u]=0; d[u]=0;
    myqueue.push(u);
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])) if(id[u][i]!=lockid){
            v=a[u][i];
            if(free1[v]){
                free1[v]=0;
                d[v]=d[u]+1;
                myqueue.push(v);
            }
        }
    }
    u=-1;
    FOR(v,1,n) if(!free1[v] && free2[v] && (u==-1 || d[v]>d[u])) u=v;
    free2[u]=0; d[u]=0;
    myqueue.push(u);
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])) if(id[u][i]!=lockid){
            v=a[u][i];
            if(free2[v]){
                free2[v]=0;
                d[v]=d[u]+1;
                myqueue.push(v);
                ans=max(ans,d[v]);
            }
        }
    }
    return ans;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
        id[u].pb(i); id[v].pb(i);
    }   
    int res=0;  
    for(lockid=0; lockid<n-1; lockid++){
        reset(free1,true); reset(free2,true);
        int t=1;
        FOR(j,1,n) if(free1[j]) t=t*bfs(j);
        res=max(res,t);
    }
    printf("%d\n",res);
    //getch();
    return 0;
}
