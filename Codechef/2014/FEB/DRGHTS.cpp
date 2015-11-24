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

const int maxn=50007;

int n,m,c[maxn],cnt,cnt2,myq[maxn],first,last,deg[maxn];
bool free1[maxn];
ll r1,r2;
vector<int> a[maxn];

void DFS(int u){
    free1[u]=0;
    ++cnt2;
    deg[u]=sz(a[u]);
    if(c[u]==1) ++cnt;
    else if(deg[u]==1) myq[++last]=u;
    
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) DFS(v);
    }   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&c[i]);
    int u,v;
    REP(i,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);           
    } 
    r1=r2=0;
    reset(free1,1);
    FOR(i,1,n) if(free1[i]){
        first=1; last=0;
        cnt=cnt2=0;
        DFS(i);
        r1+=1ll*cnt*(cnt-1)/2;  
        if(cnt<=1) continue;
        r2+=cnt2; 
        while(first<=last){
            int u=myq[first++];
            --deg[u];
            --r2;
            REP(i,sz(a[u])){
                int v=a[u][i];
                if(c[v]==0){
                    --deg[v];
                    if(deg[v]==1) myq[++last]=v;   
                }
            }
        }
    }
    
    cout<<r1<<' '<<r2<<endl;
    
    return 0;
}
