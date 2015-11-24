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

int n;
struct target{int x,y,t; double p;} a[maxn];
double dp[maxn];

bool cmp(const target &a, const target &b){
    return a.t<b.t;
}

double sqr(double r){ return r*r;}

double equal(double a, double b){
    return fabs(a-b)<1e-9;
}

double cango(const target &a, const target &b){
    double dis=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    return equal(dis,fabs(a.t-b.t)) || dis<fabs(a.t-b.t);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].p);
    sort(a+1,a+n+1,cmp);
    double res=0;
    FOR(i,1,n){
        dp[i]=a[i].p;
        FORD(j,i-1,1) if(cango(a[j],a[i]))
            dp[i]=max(dp[i],dp[j] + a[i].p);
            
        res=max(res,dp[i]);
    }
    printf("%.12lf\n",res);
    //getch();
    return 0;
}
