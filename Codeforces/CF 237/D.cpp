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

const int maxn=1000007;
int dp[maxn][5],n;
char s[maxn];

char ch(int v){
    if(v<3) return v+'0';
    if(v==3) return '1';
    if(v==4) return '*';
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets(s+1);
    n=strlen(s+1);
    if(s[1]=='0') dp[1][0]=1;
    else if(s[1]=='1') dp[1][1]=1;
    else if(s[1]=='*') dp[1][4]=1;
    else dp[1][0] = dp[1][1] = dp[1][4]=1;
    FOR(i,1,n-1) REP(v,5) if(dp[i][v] && (s[i]=='?' || ch(v)==s[i])){
        int &val=dp[i][v];  
        if(v==0){
            dp[i+1][0]=(dp[i+1][0]+val)%oo;
            dp[i+1][1]=(dp[i+1][1]+val)%oo;
        }else if(v==1 || v==2){
            dp[i+1][4]=(dp[i+1][4]+val)%oo;            
        }else if(v==3){
            dp[i+1][0]=(dp[i+1][0]+val)%oo; 
            dp[i+1][1]=(dp[i+1][1]+val)%oo;              
        }else if(v==4){
            dp[i+1][2]=(dp[i+1][2]+val)%oo;
            dp[i+1][3]=(dp[i+1][3]+val)%oo;
            dp[i+1][4]=(dp[i+1][4]+val)%oo;              
        }
    }
    int res=0;
    if(s[n]=='?' || s[n]=='0') res=(res+dp[n][0])%oo;
    if(s[n]=='?' || s[n]=='1') res=(res+dp[n][3])%oo;
    if(s[n]=='?' || s[n]=='*') res=(res+dp[n][4])%oo;
    if(n==1 && s[n]!='?') if(s[n]=='0' || s[n]=='*') res=1; else res=0;
       printf("%d\n",res);
    return 0;
}
