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

vector<int> a[maxn];
int n,m,cost[maxn],num[maxn],low[maxn],mys[maxn],last,cnt;
bool free1[maxn];
ll res1,res2;

void dfs(int u){
    num[u]=++cnt;
    low[u]=num[u];
    int v;
    mys[++last]=u;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!free1[v]) continue;
        if(num[v]==0){
            dfs(v);
            low[u]=min(low[u],low[v]);   
        }else 
            low[u]=min(low[u],num[v]);
    }   
    if(num[u]==low[u]){
        int c=0,minv=oo;
        do{
            v=mys[last--];
            free1[v]=0;
            if(cost[v]<minv){
                minv=cost[v];
                c=1;
            }else if(cost[v]==minv) ++c;            
        }while(v!=u);   
        res1+=minv; res2=(res2*c)%oo;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&cost[i]);
    scanf("%d",&m);
    int u,v;
    REP(i,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
    }
   
    last=0; cnt=0;
    reset(num,0); reset(free1,1);
    
    res1=0; res2=1;
    FOR(u,1,n) if(num[u]==0) dfs(u);
    
    cout<<res1<<' '<<res2<<endl;
    
    return 0;
}
