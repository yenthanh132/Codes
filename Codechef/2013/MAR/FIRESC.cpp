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

int n,m,c,num;
ll res;
bool free1[maxn];
vector<int> a[maxn];

void dfs(int u){
    free1[u]=0;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v);
    }
    num++;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,u,v;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&n,&m);
        FOR(i,1,n) a[i].clear();
        FOR(i,1,m){
            scanf("%d%d",&u,&v);
            a[u].pb(v);
            a[v].pb(u);
        }
        FOR(i,1,n) free1[i]=1;
        c=0;
        res=1;
        FOR(i,1,n) if(free1[i]){
            num=0;
            dfs(i);
            res=(res*num)%oo;
            c++;
        }
        printf("%d %d\n",c,res);
    }
    return 0;
}
            
