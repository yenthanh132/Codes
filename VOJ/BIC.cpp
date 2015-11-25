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

#define maxn 10001
#define BASE 1000000000

int n,m,num[maxn],low[maxn],count1,countcom,com[maxn],d[maxn],a[maxn],val[maxn];
bool free1[maxn],val2[maxn], mark[maxn],bignum[maxn];
vector<int> g1[maxn],g2[maxn];
vector<pii> dscanh;
stack<int> mystack;

void dfs(int u){
    num[u]=low[u]=++count1; 
    mystack.push(u);
    int v;
    REP(i,sz(g1[u])){
        v=g1[u][i];
        if(free1[v])
            if(num[v]==0){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }else low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        d[++countcom]=0;
        do{
            v=mystack.top(); mystack.pop();
            free1[v]=false;
            com[v]=countcom;
            d[countcom]++;
        }while(v!=u);
    }
}

void tarjain(){
    count1=countcom=0;
    reset(free1,true);
    reset(num,0);
    FOR(i,1,n) if(num[i]==0) dfs(i);
    REP(i,sz(dscanh)){
        int x=dscanh[i].fi, y=dscanh[i].se;
        if(com[x]!=com[y]) g2[com[x]].pb(com[y]);
    }
    FOR(i,1,n) if(mark[i]) d[com[i]]++;
}

void dfs2(int u){
    free1[u]=false;
    int v;
    REP(i,sz(g2[u])){
        v=g2[u][i];
        if(free1[v]) dfs2(v);
    }
    a[count1--]=u;
}

void toposort(){
    reset(free1,true);
    count1=countcom;
    FOR(i,1,countcom) if(free1[i]) dfs2(i);
}

void solve(){
    if(com[1]==com[2]){
        printf("inf\n");
        return;
    }
    int u,v;
    val[com[1]]=1;
    val2[com[1]]=(d[com[1]]>1);
    FOR(i,1,countcom){
        u=a[i];
        REP(j,sz(g2[u])){
            v=g2[u][j];
            if(val[v]+val[u]>=BASE || bignum[u]) bignum[v]=true;
            val[v]=(val[u]+val[v])%BASE;
            if(val[u] && (val2[u] || (d[v]>1))) val2[v]=1;
        }
    }
    if(val2[com[2]]) printf("inf\n"); else{
        stringstream ss;
        ss<<val[com[2]];
        string s=ss.str();
        if(bignum[com[2]]) while(s.length()<9) s='0'+s;
        printf("%s\n",s.c_str());
    }
}            

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int x,y;
    scanf("%d%d",&n,&m);
    reset(mark,false);
    REP(i,m){
        scanf("%d%d",&x,&y);
        g1[x].pb(y);
        dscanh.pb(pii(x,y));
        if(x==y) mark[x]=true;
    }
    tarjain();
    toposort();
    solve();
    //getch();
    return 0;
}
