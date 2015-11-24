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

const int maxn=10007;

vector<int> a[maxn];
int mx[maxn],my[maxn],dis[maxn],m,n,myq[maxn],last,first;

bool findpath(){
    last=0;
    FOR(i,1,m) if(mx[i]==0){
        dis[i]=0;
        myq[++last]=i;
    }else dis[i]=oo;
    dis[0]=oo;
    first=1;
    int u,v;
    while(first<=last){
        u=myq[first++];
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[my[v]]==oo){
                dis[my[v]]=dis[u]+1;
                myq[++last]=my[v];
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
        if(dis[my[v]]==dis[u]+1 && dfs(my[v])){
            mx[u]=v;
            my[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int u,v;
    REP(tt,T){
        scanf("%d%d",&m,&n);
        reset(mx,0); reset(my,0);
        FOR(i,1,m){
            a[i].clear();
            scanf("%d%d",&u,&v);
            u++; v++;
            a[i].pb(u); a[i].pb(v);   
        }
        
        int c=0;
        while(findpath()) 
            FOR(u,1,m) if(mx[u]==0 && dfs(u)) c++;
        if(c==m) puts("successful hashing");
        else puts("rehash necessary");   
    }
        
    //getch();
    return 0;
}
