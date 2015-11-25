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
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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

const int maxn = 100005;
vector<pii> dscanh;
vector<int> a[maxn];
int d[maxn],n,m;
bool found;

void dfs(int u){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(d[v]==oo){
            d[v]=d[u]+1;
            dfs(v);
        }
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T,u,v;
    scanf("%d",&T);
    REP(index,T){
        found=false;
        scanf("%d%d",&n,&m);
        
        FOR(i,1,n) a[i]=vector<int>(), d[i]=oo;
        dscanh=vector<pii>();
        
        REP(i,m){
            scanf("%d%d",&u,&v);
            a[u].pb(v); a[v].pb(u);
            dscanh.pb(pii(u,v));
        }
        FOR(i,1,n) if(d[i]==oo){
            d[i]=0;
            dfs(i);
        }
        REP(j,m){
            u=dscanh[j].fi; v=dscanh[j].se;
            if((d[u]+d[v])%2==0){
                found=true;
                break;
            }
        }
        if(found) puts("0"); else puts("1");
    }
    //getch();
    return 0;
}
