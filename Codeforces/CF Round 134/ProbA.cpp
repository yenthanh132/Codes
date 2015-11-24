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

const int maxn = 107;

int n,c;
pii a[maxn];
bool free1[maxn];

void dfs(int u){
    free1[u]=0;
    FOR(v,1,n) if(a[u].fi==a[v].fi || a[u].se==a[v].se)
        if(free1[v]) dfs(v);
}

#include<conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i].fi>>a[i].se;
    reset(free1,1);
    c=0;
    FOR(i,1,n) if(free1[i]){
        c++;
        dfs(i);
    }
    cout<<c-1;
    //getch();
    return 0;
}
    
