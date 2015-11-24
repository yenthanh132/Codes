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

const int maxn=257;

int a[maxn][maxn],n,m;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
    REP(k,n) REP(i,n) REP(j,n) if(a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
    scanf("%d",&m);
    int s,g,d;
    REP(i,m){
        scanf("%d%d%d",&s,&g,&d);
        printf("%d %d\n",a[s][g]+a[g][d], a[s][g]+a[g][d]-a[s][d]);
    }
    //getch();
    return 0;
}
