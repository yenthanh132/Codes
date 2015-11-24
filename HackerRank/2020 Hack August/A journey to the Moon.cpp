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

int n,m,cnt;
ll res;
bool free1[maxn];
vector<int> a[maxn];

void dfs(int u){
    int v;
    free1[u]=0; cnt++;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    REP(i,m){
        scanf("%d%d",&u,&v); u++; v++;
        a[u].pb(v);
        a[v].pb(u);
    }
    reset(free1,1);
    res=0; 
    int sum=0;
    FOR(i,1,n) if(free1[i]){
        cnt=0;
        dfs(i);
        res+=1ll*cnt*sum;   
        sum+=cnt;
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
