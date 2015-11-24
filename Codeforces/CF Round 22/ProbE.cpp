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

const int maxn = 100007;

int n,last,f[maxn],deg[maxn];
vector<pii> res;
bool free1[maxn];

void dfs(int u){
    free1[u]=0;
    last=u;
    if(free1[f[u]]) dfs(f[u]);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    reset(deg,0);
    scanf("%d",&n); FOR(i,1,n) scanf("%d",f+i), deg[f[i]]++;;
    reset(free1,1); 
    FOR(i,1,n) if(deg[i]==0){
        dfs(i);
        res.pb(pii(i,last));
    }
    FOR(i,1,n) if(free1[i]){
        dfs(i);
        res.pb(pii(i,last));
    }   
    if(sz(res)==1 && deg[res.front().fi]==1){
        printf("0\n");
        return 0;
    }
    printf("%d\n",sz(res));
    REP(i,sz(res)-1) printf("%d %d\n",res[i].se,res[i+1].fi);
    printf("%d %d\n",res.back().se,res.front().fi);
    //getch();
    return 0;
}
    
    
