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
int n,init[maxn],goal[maxn],list[maxn],res;

void dfs(int u, int p, int x, int y){
    int val=init[u]^x;
    int v;
    if(val!=goal[u]){
        list[++res]=u;
        REP(i,sz(a[u])){
            v=a[u][i];
            if(v==p) continue;
            dfs(v,u,y,x^1);   
        }
    }else{
        REP(i,sz(a[u])){
            v=a[u][i];
            if(v==p) continue;
            dfs(v,u,y,x);   
        }   
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int u,v;
    scanf("%d",&n);
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);   
    }
    FOR(i,1,n) scanf("%d",&init[i]);
    FOR(i,1,n) scanf("%d",&goal[i]);
    dfs(1,-1,0,0);
    printf("%d\n",res);
    FOR(i,1,res) printf("%d\n",list[i]);
    
    return 0;
}
