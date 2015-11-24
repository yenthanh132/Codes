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

const int maxn=55;

int n,s[maxn][maxn],dp[maxn][maxn][maxn][maxn],trace[maxn][maxn][maxn][maxn];
char arr[maxn][maxn];

int fullfill(int x1, int y1, int x2, int y2){
    int sum=(x2-x1+1)*(y2-y1+1), sum2=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
    if(sum==sum2) return 1;
    else if(sum2==0) return 2;
    else return 0;
}

void traceback(int x1, int y1, int x2, int y2){
    if(dp[x1][y1][x2][y2]==0) return;
    else if(trace[x1][y1][x2][y2]==0 && dp[x1][y1][x2][y2]==1){
        printf("%d %d %d %d B\n",x1-1,y1-1,x2-1,y2-1);
        return;
    }
    int &val=trace[x1][y1][x2][y2];
    if(val>0){
        traceback(x1,y1,x1+val-1,y2);
        traceback(x1+val,y1,x2,y2);
    }else{
        val=-val;
        traceback(x1,y1,x2,y1+val-1);
        traceback(x1,y1+val,x2,y2);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",arr[i]+1);
    reset(s,0);
    FOR(i,1,n) FOR(j,1,n) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(arr[i][j]=='B');
    int val;
    FOR(x1,1,n) FOR(x2,x1,n) FOR(y1,1,n) FOR(y2,y1,n){
        val=fullfill(x1,y1,x2,y2);
        if(val==1) dp[x1][y1][x2][y2]=1; 
        else if(val==2) dp[x1][y1][x2][y2]=0;
        else dp[x1][y1][x2][y2]=oo;
    }
    int x2,y2;
    FOR(height,1,n) FOR(width,1,n) FOR(x1,1,n-height+1) FOR(y1,1,n-width+1){
        x2=x1+height-1; y2=y1+width-1;
        int &f=dp[x1][y1][x2][y2];
        if(f<=1) continue;
        FOR(k,1,height-1) if(f>dp[x1][y1][x1+k-1][y2]+dp[x1+k][y1][x2][y2]){
            f=dp[x1][y1][x1+k-1][y2]+dp[x1+k][y1][x2][y2];
            trace[x1][y1][x2][y2]=k;
        }
        FOR(k,1,width-1) if(f>dp[x1][y1][x2][y1+k-1]+dp[x1][y1+k][x2][y2]){
            f=dp[x1][y1][x2][y1+k-1]+dp[x1][y1+k][x2][y2];
            trace[x1][y1][x2][y2]=-k;
        }
    }
    printf("%d\n",dp[1][1][n][n]);
    traceback(1,1,n,n);
    
    //getch();
    return 0;
    
}
        
