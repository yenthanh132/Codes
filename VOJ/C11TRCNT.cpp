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

pii a[201];
int n,res,val[201];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    res=0;
    FOR(i,1,n-2) FOR(j,i+1,n-1) FOR(z,j+1,n)
        if(1ll*(a[i].fi-a[j].fi)*(a[i].se-a[z].se)!=1ll*(a[i].se-a[j].se)*(a[i].fi-a[z].fi)){
            res++;
            val[i]++;
            val[j]++;
            val[z]++;
        }
    int u=1;
    FOR(i,2,n) if(val[i]<val[u]) u=i;
    printf("%d %d\n",res,u);
    //getch();
    return 0;
}
