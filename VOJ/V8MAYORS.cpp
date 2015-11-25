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

const int maxn=40007;

int xlist[maxn],ylist[maxn],deg[maxn],n,nx,ny,m,mystack[maxn],last,eulerlist[maxn];
struct point{int x,y;} a[maxn];
vector<int> lnk[maxn];
map<pii,int> state,id;
int ans[maxn];

int pos(int *arr, int n, int v){
    return lower_bound(arr+1,arr+n+1,v)-arr;
}

void dfs(int u){
    if(lnk[u].empty()) return;
    int v;
    while(!lnk[u].empty()){
        v = lnk[u].back();
        lnk[u].pop_back();
        if(state[pii(u,v)]) continue;
        int key;
        if(u<v) key=1; else key=2;
        state[pii(u,v)]=1;
        state[pii(v,u)]=1;
        ans[id[pii(u,v)]]=key-1;
        deg[u]--; deg[v]--;
        dfs(v);
        break;
    }
}

void euler(int s){
    last=1;
    mystack[1]=s;
    bool found;
    int u,v,cnt=0;
    while(last){
        found=0;
        u=mystack[last];
        while(!lnk[u].empty()){
            v=lnk[u].back();
            lnk[u].pop_back();
            if(state[pii(u,v)]) continue;
            state[pii(u,v)]=1;
            state[pii(v,u)]=1;
            found=1;
            mystack[++last]=v;
            deg[u]--; deg[v]--;
            break;
        }
        if(!found) eulerlist[++cnt]=mystack[last--];
    }
    FOR(i,2,cnt){
        u=eulerlist[i];
        v=eulerlist[i-1];
        ans[id[pii(u,v)]]=(u>v);
    }
}   

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&a[i].x,&a[i].y);
        xlist[i]=a[i].x;
        ylist[i]=a[i].y;
    }
    
    sort(xlist+1,xlist+n+1);
    nx=unique(xlist+1,xlist+n+1)-xlist-1;
    sort(ylist+1,ylist+n+1);
    ny=unique(ylist+1,ylist+n+1)-ylist-1;
    
    m=nx+ny;
    int posx, posy;
    FOR(i,1,n){
        posx=pos(xlist,nx,a[i].x);
        posy=pos(ylist,ny,a[i].y)+nx;
        deg[posx]++;
        deg[posy]++;
        lnk[posx].pb(posy);
        lnk[posy].pb(posx);
        id[pii(posx,posy)]=i;
        id[pii(posy,posx)]=i;
    }
        
    FOR(i,1,m) if(deg[i]&1) dfs(i);
    FOR(i,1,m) if(deg[i]) euler(i);
    
    FOR(i,1,n) printf("%d\n",ans[i]);
    
    //getch();
    return 0;
}
    
