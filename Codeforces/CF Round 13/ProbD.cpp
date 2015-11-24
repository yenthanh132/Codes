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


struct point{ double x,y; bool red;};
const int maxn=501;
point a[maxn],b[maxn];
int n,m,res,dp[maxn][maxn];

double val(point &a, point &b, point &p){
    return((b.y-a.y)*(p.x-a.x)+(a.x-b.x)*(p.y-a.y));
}
         
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%lf%lf",&a[i].x,&a[i].y);
    FOR(i,1,m) scanf("%lf%lf",&b[i].x,&b[i].y);
    FOR(i,1,n) FOR(j,1,n) if(a[i].x<a[j].x){
        dp[i][j]=0;
        FOR(k,1,m) if(min(a[i].x,a[j].x)<b[k].x && b[k].x<=max(a[i].x,a[j].x) && val(a[i],a[j],b[k])>0) dp[i][j]++;
        dp[j][i]=-dp[i][j];
    }
    res=0;
    FOR(i,1,n-2) FOR(j,i+1,n-1) FOR(k,j+1,n) if(dp[i][j]+dp[j][k]+dp[k][i]==0) res++;
    printf("%d\n",res);
    //getch();
    return 0;
}

