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

const int maxn=22;
const int maxv=222;

int a[maxn],c[maxn],n,k,T;
int a2[maxn],n2;
ll dp[maxn][maxn][maxv],gt[maxn];
double res,res2;

int cal(int i){
    return max(a[i]-k,0);
}

double cal(int i, int j){
    n2=0;
    int sum=0;
    FOR(x,1,n) if(x!=i && x!=j) a2[++n2]=a[x], sum+=a[x];
    reset(dp,0);
    dp[0][0][0]=1;
    FOR(i,1,n2) FOR(j,0,i) FOR(v,0,sum){
        dp[i][j][v]=dp[i-1][j][v];
        if(j>0 && v>=a2[i]) dp[i][j][v]+=dp[i-1][j-1][v-a2[i]];
    }
    int mink=max(k+1-a[i]-a[j],0);
    int maxk=k-1;
    double res=0;
    FOR(ik,mink,maxk){
        int v=0;
        FOR(x,1,a[i]) if(a[i]+ik < x+k && x+k <= a[i]+ik+a[j]) ++v;
        double tmp=0;
        FOR(j,0,n2) tmp+=2.0*dp[n2][j][ik]*gt[j]*gt[n2-j]*(n2-j+1);
        res+=v*tmp;
    }
    return res;
}

int main(){
    gt[0]=1;
    FOR(i,1,20) gt[i]=gt[i-1]*i;
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%d%d",&a[i],&c[i]);

        res=res2=0;
        FOR(i,1,n) res+=cal(i);

        FOR(i,1,n-1) FOR(j,i+1,n) if(c[i]==c[j]) res2+=cal(i,j);
        FOR(i,1,n) res2/=i;
        res+=res2;

        printf("%0.9lf\n",res);
    }
}

