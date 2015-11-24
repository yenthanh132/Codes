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
#define oo 10000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn =2007;

pii a[maxn];
int n;
ll f[maxn][maxn*2],sumc;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    sumc=0;
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se), sumc+=a[i].se;
    
    FOR(j,0,4000) f[0][j]=-oo; f[0][2000]=0;
    FOR(i,1,n)
        FOR(j,0,4000){
            f[i][j]=-oo;
            if(j<4000) f[i][j]=max(f[i][j],f[i-1][j+1]+a[i].se);
            if(j>=a[i].fi) f[i][j]=max(f[i][j],f[i-1][j-a[i].fi]);
        }
    
    ll res=0;
    FOR(j,2000,4000) res=max(res,f[n][j]);
    printf("%I64d\n",sumc-res);
    //getch();
    return 0;
}
            
