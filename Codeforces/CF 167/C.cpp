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

const int maxn=300007;

int n,m,ans[maxn],deg[maxn];
vector<int> a[maxn];
queue<int> myq;
bool inqueue[maxn];
     
bool check(){
    int c;
    FOR(i,1,n){     
        c=0;
        REP(j,sz(a[i]))
            if(ans[a[i][j]]==ans[i]) c++;
        if(c>1) return 0;
    }
    return 1;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int u,v;
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    FOR(i,1,n) if(deg[i]>1){
        myq.push(i);
        inqueue[i]=1;
    }
    while(!myq.empty()){
        u=myq.front(); myq.pop();
        inqueue[u]=0;
        if(deg[u]<=1) continue;
        ans[u]=1^ans[u];
        REP(i,sz(a[u])){
            v=a[u][i];
            if(ans[u]==ans[v]) deg[v]++, deg[u]++; else deg[v]--, deg[u]--;
            if(deg[v]>1 && !inqueue[v]){
                myq.push(v);
                inqueue[v]=1;
            }
        }
    }
    
        FOR(i,1,n) printf("%d",ans[i]);
        puts("");
    return 0;
}
