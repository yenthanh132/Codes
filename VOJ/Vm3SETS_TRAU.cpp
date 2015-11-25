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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100005;

int n;
pii a[3][maxn];
double res;

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    return abs((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2));
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    REP(h,3) FOR(i,1,n) scanf("%d%d",&a[h][i].fi,&a[h][i].se);
    res=0;
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) res=max(res,area(a[0][i].fi,a[0][i].se,a[1][j].fi,a[1][j].se,a[2][k].fi,a[2][k].se));
    printf("%0.1f",res/2);
    getch();
    return 0;
}
