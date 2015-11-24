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

const int maxn=100007;

int n,c[maxn],m,list[maxn],cnt,minv;
bool free1[maxn],ok;
vector<int> a[maxn];

void dfs(int u){
    free1[u]=0;
    if(c[u]>=0) minv=min(minv,c[u]);
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    REP(i,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    FOR(i,1,n) scanf("%d",&c[i]);
    reset(free1,1);
    ok=1;
    cnt=0;
    FOR(i,1,n) if(free1[i]){
        minv=oo;
        dfs(i);
        if(minv==oo) ok=0;
        list[++cnt]=minv;
    }
    if(cnt==1) puts("0");
    else if(!ok) puts("-1");
    else{
        sort(list+1,list+cnt+1);
        ll res=1ll*list[1]*(cnt-1);
        FOR(i,2,cnt) res+=list[i];
        cout<<res<<endl;
    }
    
    //getch();
    return 0;
}
