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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;++a)
#define FORD(a,b,c) for (int a=b;a>=c;--a)
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

bool dp[200][30][10];
int ans[7][7],a[7][7],r[7],c[7],numr[7],numc[7];
bool found;

bool cmp(const pii &a, const pii &b){
    return r[a.fi]+c[a.se]>r[b.fi]+c[b.se];
}

void dfs(int v){
    if(found) return;
    if(v==0){
        FOR(x,1,5) FOR(y,1,5) ans[x][y]=a[x][y];
        found=1;
        return;
    }
    bool ok;
    vector<pii> list;
    FOR(x,1,5) FOR(y,1,5) if(!a[x][y] && r[x]>=v && c[y]>=v) list.pb(pii(x,y));
    sort(list.begin(),list.end(),cmp);
    int x,y;
    REP(i,sz(list)){
        x=list[i].fi; y=list[i].se;
        a[x][y]=v; r[x]-=v; c[y]-=v; numr[x]--; numc[y]--;
        ok=1;
        FOR(z,1,5) if(!dp[r[z]][v-1][numr[z]] || !dp[c[z]][v-1][numc[z]]){ok=0; break;}
        if(ok) dfs(v-1);
        a[x][y]=0; r[x]+=v; c[y]+=v; numr[x]++; numc[y]++;
    }
}

//#include <conio.h>
int main(){
    reset(dp,0);
    FOR(j,0,25) dp[0][j][0]=1;
    FOR(i,1,125) FOR(j,1,25) FOR(v,1,5){
        dp[i][j][v]|=dp[i][j-1][v];
        if(i>=j) dp[i][j][v]|=dp[i-j][j-1][v-1];
    }
    //freopen("test.txt","r",stdin);
    FOR(i,1,5) cin>>r[i];
    FOR(i,1,5) cin>>c[i];
    found=0;
    FOR(i,1,5) numr[i]=numc[i]=5;
    dfs(25);
    FOR(i,1,5){
        FOR(j,1,5) printf("%d ",ans[i][j]);
        puts("");
    }
    //getch();
    return 0;
}
