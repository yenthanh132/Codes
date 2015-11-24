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

int n,m,k,d[maxn],res[maxn],trace[maxn],cnt;
vector<int> a[maxn];
bool free1[maxn],found;

void dfs(int u){
    if(found) return;
    free1[u]=0;
    int v,t;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]){
            d[v]=d[u]+1;
            trace[v]=u;
            dfs(v);
        }else if(d[u]-d[v]>=k){
            t=u;
            found=1;
            res[cnt=1]=t;
            do{
                t=trace[t];
                res[++cnt]=t;
            }while(v!=t);
            return;
        }
    }
}
        
            
#include <conio.h>            

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    found=0;
    reset(free1,1);
    FOR(i,1,n) if(free1[i]){
        d[i]=0;
        dfs(i);
        if(found) break;
    }
    printf("%d\n",cnt);
    FOR(i,1,cnt) printf("%d ",res[i]);
    puts("");
    //getch();
    return 0;
}
