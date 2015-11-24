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

ll BIT[4][maxn][maxn];

int n,m;

int type(int x, int y){
    int res=0;
    if(x&1) res|=1;
    if(y&1) res|=2;
    return res;
}

void update(int x, int y, ll v){
    int t=type(x,y);
    for(int i=x; i<=n; i+=i&(-i))
        for(int j=y; j<=n; j+=j&(-j))
            BIT[t][i][j]^=v;            
}

ll get(int x, int y){
    int t=type(x,y);
    ll v=0;
    for(int i=x; i; i-=i&(-i))
        for(int j=y; j; j-=j&(-j))
            v^=BIT[t][i][j];
    return v;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int k,x1,y1,x2,y2;
    ll v;
    REP(tt,m){
        scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
        if(k==1){
            ll ans=get(x2,y2)^get(x1-1,y2)^get(x2,y1-1)^get(x1-1,y1-1);            
            printf("%I64d\n",ans);
        }else{
            scanf("%I64d",&v);
            update(x1,y1,v);
            update(x1,y2+1,v);
            update(x2+1,y1,v);
            update(x2+1,y2+1,v);
        }
    }    
    ///getch();
    return 0;
}
