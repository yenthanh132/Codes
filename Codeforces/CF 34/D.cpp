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

const int maxn=500007;

int r1,r2,n,res[maxn];
vector<int> a[maxn];

void dfs(int u, int p){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        res[v]=u;
        dfs(v,u);
    }
}       

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&r1,&r2);
    int v;
    FOR(i,1,n) if(i!=r1){
        scanf("%d",&v);
        a[i].pb(v);
        a[v].pb(i);
    }
    dfs(r2,-1);
    FOR(i,1,n) if(i!=r2) printf("%d ",res[i]);
    //getch();
    return 0;
}
    
