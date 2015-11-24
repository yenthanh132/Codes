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

int n,p[maxn],d[maxn];
bool a[maxn][maxn];

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
    FOR(i,1,n) scanf("%d",&d[i]);
    reset(a,0);
    FOR(i,1,n){
        a[i][i]=1;
        if(i-d[i]>=1) a[i][i-d[i]]=1,a[i-d[i]][i]=1;
        if(i+d[i]<=n) a[i][i+d[i]]=1,a[i+d[i]][i]=1;
    }
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) a[i][j]|=a[i][k] && a[k][j];
    bool ok=1;
    FOR(i,1,n) if(!a[p[i]][i]) ok=0;
    if(ok) puts("YES"); else puts("NO");
    return 0;
}
