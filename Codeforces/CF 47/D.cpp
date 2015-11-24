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

int x[maxn],y[maxn];
double p[maxn],dp[maxn][maxn];
int n,e,k,xr,yr;

int sqr(int a){return a*a;}

bool test(double r){
    if(r==0){
        int c=0;
        FOR(i,1,n) if(xr==x[i] && yr==y[i]) c++;
        return c>=k;
    }
    FOR(i,1,n){
        int d2=sqr(xr-x[i])+sqr(yr-y[i]);
        if(d2<=r*r) p[i]=1;
        else p[i]=exp(1-d2/(r*r));
    }
    
    FOR(i,0,n) FOR(j,0,k) dp[i][0]=0;
    dp[0][0]=1;
    FOR(i,1,n) FOR(j,0,k){
        dp[i][j]=dp[i-1][j]*(1-p[i]);
        if(j>0) dp[i][j]+=dp[i-1][j-1]*p[i];
    }
    double pro=0;
    FOR(j,0,k-1) pro+=dp[n][j];
    return pro*1000<=e;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&e);
    scanf("%d%d",&xr,&yr);
    FOR(i,1,n) scanf("%d%d",&x[i],&y[i]);
    
    double l,r,mid,res;
    if(test(0)) res=0;
    else{
        l=0; r=oo;
        while(fabs(l-r)>1e-12){
            mid=(l+r)/2;
            if(test(mid)) r=mid;
            else l=mid;
        }
        res=(l+r)/2;
    }
    printf("%0.12lf\n",res);
    //getch();
    return 0;
}
