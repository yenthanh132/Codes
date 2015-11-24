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

const int maxn=107;

int T,a[maxn][maxn],m,n;
int maxleft[maxn][maxn],maxright[maxn][maxn],maxtop[maxn][maxn],maxbot[maxn][maxn];

bool ok(){
    reset(maxleft,0); reset(maxright,0);
    reset(maxtop,0); reset(maxbot,0);
    FOR(i,1,m) FOR(j,1,n){
        maxleft[i][j]=max(a[i][j],maxleft[i][j-1]);
        maxtop[i][j]=max(a[i][j],maxtop[i-1][j]);
    }
    FORD(i,m,1) FORD(j,n,1){
        maxright[i][j]=max(a[i][j],maxright[i][j+1]);
        maxbot[i][j]=max(a[i][j],maxbot[i+1][j]);
    }
    FOR(i,1,m) FOR(j,1,n)
        if(!((maxleft[i][j]<=a[i][j] && maxright[i][j]<=a[i][j]) 
        || (maxtop[i][j]<=a[i][j] && maxbot[i][j]<=a[i][j])))
            return 0;
    return 1;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d%d",&m,&n);
        FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
        if(ok()) printf("Case #%d: YES\n",tt); else printf("Case #%d: NO\n",tt);
    }
    return 0;
}
