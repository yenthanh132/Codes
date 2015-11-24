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

int n,dp[107][2],dp2[107][2];
string s;

//#include <conio.h>
int main(){
    freopen("rle-size.in","r",stdin);
    freopen("rle-size.out","w",stdout);
    cin>>n;
    cin>>s; 
    if(s[0]=='+' || s[0]=='?') dp[1][1]=dp2[1][1]=1; else dp[1][1]=oo, dp2[1][1]=-oo;
    if(s[0]=='-' || s[0]=='?') dp[1][0]=dp2[1][0]=1; else dp[1][0]=oo, dp2[1][0]=-oo;
    FOR(i,2,n){
        if(s[i-1]=='+' || s[i-1]=='?') dp[i][1]=min(dp[i-1][0]+1,dp[i-1][1]);
        else dp[i][1]=oo;
        if(s[i-1]=='-' || s[i-1]=='?') dp[i][0]=min(dp[i-1][0],dp[i-1][1]+1);
        else dp[i][0]=oo;
        
        if(s[i-1]=='+' || s[i-1]=='?') dp2[i][1]=max(dp2[i-1][0]+1,dp2[i-1][1]);
        else dp2[i][1]=-oo;
        if(s[i-1]=='-' || s[i-1]=='?') dp2[i][0]=max(dp2[i-1][0],dp2[i-1][1]+1);
        else dp2[i][0]=-oo;
    }
    cout<<min(dp[n][0],dp[n][1])<<' '<<max(dp2[n][0],dp2[n][1]);
//    getch();
    return 0;
}
