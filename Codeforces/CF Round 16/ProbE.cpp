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

const int maxn=18;

double f[1<<maxn],a[maxn][maxn];
int n;

double count(int v){
    int c=0;
    while(v){
        c+=v%2;
        v>>=1;
    }
    return c*(c-1)/2;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j];
    f[(1<<n)-1]=1;
    double c;
    REPD(i,1<<n)
        FOR(j,0,n-2) if((i>>j)&1)
            FOR(k,j+1,n-1) if((i>>k)&1){
                c=count(i);
                f[i-(1<<j)]+=f[i]*a[k][j]/c;
                f[i-(1<<k)]+=f[i]*a[j][k]/c;
            }
    REP(i,n) cout<<f[1<<i]<<' ';
    //getch();
    return 0;
}
