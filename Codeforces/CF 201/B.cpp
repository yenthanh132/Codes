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
typedef pair<pii, int> iii;
const int maxn=106;

#include <conio.h>

char s1[maxn],s2[maxn],virus[maxn],ans[maxn];
int dp[maxn][maxn][maxn],prev[maxn];
iii trace[maxn][maxn][maxn];
int m,n,k;

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%s%s%s",s1+1,s2+1,virus+1);
    m=strlen(s1+1); n=strlen(s2+1); k=strlen(virus+1);
    dp[0][0][0]=0;
    
    prev[1]=0;
    int i=1, j=0;
    while(i<=k){
        while(j>0 && virus[j]!=virus[i]) j=prev[j];
        i++; j++;
        if(i<=k && virus[i]==virus[j]) prev[i]=prev[j]; else prev[i]=j;
    }
    
    FOR(i,1,m) FOR(j,1,n){
        FOR(z,1,k){
            if(dp[i-1][j][z]>dp[i][j-1][z]){
                dp[i][j][z]=dp[i-1][j][z];
                trace[i][j][z]=iii(pii(i-1,j),z);
            }else{
                dp[i][j][z]=dp[i][j-1][z];
                trace[i][j][z]=iii(pii(i,j-1),z);
            }
        }
        if(s1[i]==s2[j]){
            FOR(z,1,k){
                int zt=z;
                while(zt>0 && virus[zt]!=s1[i]) zt=prev[zt];
                zt++;
                if(zt<=k){
                    if(dp[i][j][zt]<dp[i-1][j-1][z]+1){
                        trace[i][j][zt]=iii(pii(i-1,j-1),z);
                        dp[i][j][zt]=dp[i-1][j-1][z]+1;
                    }
                }
            }
        }
    }
    
    int res=0,u=-1;
    FOR(z,1,k)
        if(res<dp[m][n][z]){
            res=dp[m][n][z];
            u=z;
        }
        
    if(res==0) puts("0"); 
    else{
        
        i=m; j=n; 
        int pos=res;
        while(pos){
            iii t=trace[i][j][u];
            int i2,j2,u2;
            i2=t.fi.fi; j2=t.fi.se; u2=t.se;
            if(dp[i2][j2][u2]+1==dp[i][j][u]) ans[pos--]=s1[i];
            i=i2; j=j2; u=u2;
        }
        ans[res+1]='\0';           
        puts(ans+1);
    }
    
    //getch();
    return 0;
}
