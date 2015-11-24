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

int a[maxn][maxn];
ll sum[maxn*2][maxn*2];

int m,n,k,resx,resy;
ll best;

ll getvalue(int x, int y, int d){
    y-=d;
    int x2,y2,x3,y3;
    x2=x+y-1;
    y2=y-x+m;
    x3=min(m+n-1,x2+d*2);
    y3=min(m+n-1,y2+d*2);
    return sum[x3][y3]-sum[x2-1][y3]-sum[x3][y2-1]+sum[x2-1][y2-1];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,m) FOR(j,1,n) sum[i+j-1][j-i+m]=a[i][j];
    FOR(i,1,m+n-1) FOR(j,1,m+n-1) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    best=-oo;
    

    FOR(i,k,m-k+1) FOR(j,k,n-k+1){
        ll v=0;
        FOR(z,0,k-1) v+=getvalue(i,j,z);
        if(best<v){
            best=v;
            resx=i;
            resy=j;
        }
    }
    printf("%d %d\n",resx,resy);
    //getch();
    return 0;
}
