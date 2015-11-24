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

const int maxn=1111;
const int maxk=57;

int n,k,t;
int f[maxk][maxn],c[maxn][maxn];
ll dp[maxk][maxn],frac[maxn];

void init(){
    reset(f,0);
    f[0][0]=1;
    FOR(i,1,50) FOR(j,1,1000) 
        if(j>=i){
            f[i][j]=f[i][j-i]+f[i-1][j-i];
            if(f[i][j]>oo) f[i][j]-=oo;
        }else 
            f[i][j]=0;
    
    reset(c,0);
    c[0][0]=1;
    FOR(i,1,1050){
        c[i][0]=1;
        FOR(j,1,i){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
            if(c[i][j]>oo) c[i][j]-=oo;
        }
    }
    
    frac[0]=1;
    FOR(i,1,1000) frac[i]=(frac[i-1]*i)%oo;
    
    FOR(i,1,50) FOR(j,1,1000){
        dp[i][j] = 0;
        FOR(k,1,j) dp[i][j] = (dp[i][j] + 1ll*f[i][k] * c[j-k+i][j-k])%oo;   
        dp[i][j] = (dp[i][j] * frac[i])%oo;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    init();
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d%d",&n,&k);
        if(k>50) puts("0");
        else{
            printf("%I64d\n",dp[k][n]); 
        }   
    }
    return 0;
}   
