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

#include <conio.h>

const int maxn=107;

int m,n,k,dp[maxn][maxn][15], trace[maxn][maxn][15], a[maxn][maxn];
char buf[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k); k++;
    FOR(i,1,m){
        scanf("%s",buf+1);
        FOR(j,1,n) a[i][j]=buf[j]-'0';
    }
    FOR(i,1,m) FOR(j,1,n) FOR(z,0,k-1) dp[i][j][z]=-1;
    FOR(j,1,n) dp[m][j][a[m][j]%k]=a[m][j];
    FORD(i,m-1,1) FOR(j,1,n) FOR(z,0,k-1){
        int &v=a[i][j];
        int zt=(z-v%k+k)%k;
        if(j>1 && dp[i+1][j-1][zt]!=-1 && dp[i][j][z]<v + dp[i+1][j-1][zt]){
            dp[i][j][z]=v + dp[i+1][j-1][zt];
            trace[i][j][z]=-1;
        }
        if(j<n && dp[i+1][j+1][zt]!=-1 && dp[i][j][z]<v + dp[i+1][j+1][zt]){
            dp[i][j][z]=v + dp[i+1][j+1][zt];
            trace[i][j][z]=1;
        }
    }
    int res=-1,p;
    FOR(i,1,n) if(res<dp[1][i][0]){
        res=dp[1][i][0];
        p=i;
    }
    if(res==-1) puts("-1");
    else{
        printf("%d\n",res);
        int zt=0,z;
        FOR(i,1,m-1){
            if(trace[i][p][zt]==-1)
                buf[m-1-i]='R';
            else 
                buf[m-1-i]='L';
            z=(zt-a[i][p]%k+k)%k;
            p+=trace[i][p][zt];
            zt=z;
        }
        buf[m-1]='\0';
        printf("%d\n",p);
        printf("%s\n",buf);
    }
    //getch();
    return 0;
}
