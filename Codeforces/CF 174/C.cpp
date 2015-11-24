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

const int maxn=307;
const int maxt=100007;

int dp[maxn][maxt],n,a[maxn],w[maxn],cnt,q,val[maxn];
int link[maxn],deg[maxn];
bool cir,mark[maxn];
ll t;

void dfs(int u){
    if(cir) return;
    mark[u]=1;
    val[u]=a[u];
    if(link[u]){
        int v=link[u];
        dfs(v);
        val[u]=val[v]+a[u];
    }
    w[++cnt]=val[u];
}
    
#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%I64d",&n,&q,&t);
    cir=0;
    FOR(i,1,n) scanf("%d",&a[i]);
    int x,y;
    FOR(i,1,q){
        scanf("%d%d",&x,&y);
        deg[x]++;
        link[y]=x;
    }
    cnt=0;
    FOR(i,1,n) if(deg[i]==0){
        int cnt0=cnt;
        dfs(i);
        if(cir) break;
        FOR(j,cnt0+1,cnt-1) t-=w[j];
    }
    FOR(i,1,n) if(!mark[i]){
        cir=1;
        break;
    }
    if(cir || t<0) puts("0");
    else{
        dp[0][0]=1;
        FOR(i,1,cnt) FOR(j,0,t){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=(dp[i][j-w[i]] + dp[i][j])%oo;
        }
        printf("%d\n",dp[cnt][t]);
    }
    //getch();
    return 0;
}
