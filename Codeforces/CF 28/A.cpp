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

const int maxn=1007;

pii td[maxn];
int n,m,p[80007],ans[maxn];
vector<int> a[80007];
bool ok;

int abs(int v){
    if(v<0) v=-v;
    return v;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&td[i].fi,&td[i].se);
    int v;
    FOR(i,1,m){
        scanf("%d",&v);
        if(v>80000) continue;
        a[v].pb(i);
    }
    td[0]=td[n]; td[n+1]=td[1];
    reset(ans,0);
    ok=1;
    for(int i=1; i<n; i+=2){
        v=abs(td[i].fi-td[i-1].fi)+abs(td[i].fi-td[i+1].fi)+abs(td[i].se-td[i-1].se)+abs(td[i].se-td[i+1].se);
        if(v<=80000 && p[v]<sz(a[v]))
            ans[i]=a[v][p[v]++];
        else{
            ok=0;
            break;
        }
    }
    if(!ok){
        ok=1;
        reset(ans,0); reset(p,0);
        for(int i=2; i<=n; i+=2){
            v=abs(td[i].fi-td[i-1].fi)+abs(td[i].fi-td[i+1].fi)+abs(td[i].se-td[i-1].se)+abs(td[i].se-td[i+1].se);
            if(v<=80000 && p[v]<sz(a[v]))
                ans[i]=a[v][p[v]++];
            else{
                ok=0;
                break;
            }
        }
    }
    if(ok){
        puts("YES");
        FOR(i,1,n) if(ans[i]) printf("%d ",ans[i]); else printf("-1 ");
    }else puts("NO");
    return 0;
}
