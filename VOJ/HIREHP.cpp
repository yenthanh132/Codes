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
#define oo 100000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=500007;

vector<pii> a[maxn];
int n;
ll BIT[maxn];

void update(int pos, ll v){
    pos++;
    for(int i=pos; i; i-=i&(-i)) BIT[i]=min(BIT[i],v);
}

ll getmin(int pos){
    ll res=oo;
    pos++;
    for(int i=pos; i<=n+1; i+=i&(-i)) res=min(res,BIT[i]);
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n+1) BIT[i]=oo;
    update(0,0);
    int u,v;
    FOR(i,1,n){
        scanf("%d%d",&u,&v);
        a[u].pb(pii(i,v));
    }
    FOR(i,1,n) if(!a[i].empty())
        REP(j,sz(a[i]))
            update(i,getmin(a[i][j].fi-1)+a[i][j].se);
    printf("%lld\n",BIT[n+1]);
    //getch();
    return 0;
}
