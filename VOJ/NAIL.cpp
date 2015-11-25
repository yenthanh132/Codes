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

const int maxn = 1007;

ll f[maxn*2][maxn];
int n;

#include <conio.h>
int main(){
    scanf("%d",&n);
    f[1][0]=1; f[2][0]=0; f[2][1]=1; f[3][0]=0; f[3][1]=2;
    FOR(i,4,n*2) FOR(j,0,i/2)
        if(i&1) f[i][j]=(f[i-1][j]*(i-1-j)+f[i-1][j+1]*(j+1))%oo;
        else f[i][j]=((j>0?f[i-1][j-1]*2:0)+f[i-1][j]*(i-3-j)+f[i-1][j+1]*(j+1))%oo;
    FOR(i,0,n) printf("%d ",f[n*2][i]);
    getch();
    return 0;
}
                
