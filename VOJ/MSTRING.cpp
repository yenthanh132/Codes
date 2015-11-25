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

int dp[maxn][maxn],m,n,pos[maxn][26];
char s1[maxn],s2[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s1); gets(s2);
    m=strlen(s1); n=strlen(s2);
    REP(i,26) pos[n][i]=n;
    REPD(i,n) REP(j,26) if(s2[i]==j+'a') pos[i][j]=i; else pos[i][j]=pos[i+1][j];
    REP(i,m+2) REP(j,n+2) dp[i][j]=oo;
    REP(i,m){
        dp[i][n]=1;
        dp[i][n+1]=0;
    }
    REPD(i,m) REPD(j,n) dp[i][j]=min(dp[i+1][j],dp[i+1][pos[j][s1[i]-'a']+1]+1);
    printf("%d\n",dp[0][0]);
    //getch();
    return 0;
}
