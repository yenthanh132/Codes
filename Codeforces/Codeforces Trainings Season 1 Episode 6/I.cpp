#include <conio.h>
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

char s[1000007],b[1000007];
int n,r1,r2,a[1000007],dp[1000007][2],m;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    int i=1,j;
    m=0;
    while(i<=n){
        j=i;
        while(j<n && s[j+1]==s[i]) j++;
        a[++m]=j-i+1;
        b[m]=s[i];
        i=j+1;
    }
    
    REP(j,2) if(b[1]==j+'A') dp[1][j]=0; else dp[1][j]=1;
    FOR(i,2,n){
        REP(j,2) 
            if(b[i]==j+'A'){
                dp[i][j]=min(dp[i-1][j],dp[i-1][1^j]+1);
            }else{
                dp[i][j]=min(dp[i-1][j]+(a[i]==1?1:2),dp[i-1][1^j]+1) ;  
            }
    }
    
    cout<<min(dp[m][0],dp[m][1]+1)<<endl;
    //getch();
    return 0;
}
