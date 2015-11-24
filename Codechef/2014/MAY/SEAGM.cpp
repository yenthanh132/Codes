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

int gcd(int a, int b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);   
}

int n,a[107],dp[107][107];
double dp2[107][107];
bool mark[107][107];

bool f(int i, int v){    
    if(v==1) return 1;
    if(i>n) return 0;
    if(dp[i][v]!=-1) return dp[i][v];
    int &res=dp[i][v];
    res=0;
    int c=0;
    FOR(j,1,n) if(v>0 && a[j]%v==0) ++c;
    else if(gcd(v,a[j])>1 && f(i+1,gcd(v,a[j]))==0) res=1;
    if(i<=c && f(i+1,v)==0) res=1;
    return res;
}

double g(int i, int v){
    if(v==1) return i&1;
    if(i>n) return n&1;
    if(mark[i][v]) return dp2[i][v];
    mark[i][v]=1;
    double &res=dp2[i][v];
    res=0;
    int c=0;
    FOR(j,1,n) if(v>0 && a[j]%v==0) ++c;
    else res+=g(i+1,gcd(v,a[j]))/(n-i+1);
    if(i<=c) res+=g(i+1,v)/(n-i+1)*(c-i+1);
    return res;
}   

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);   
    REP(tt,test){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        
        reset(mark,0);
        reset(dp,-1);
        int res1=f(1,0);
        double res2=g(1,0);
        printf("%d %0.4lf\n",res1,res2);
    }
}

