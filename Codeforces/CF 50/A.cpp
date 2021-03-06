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

int dp[400],n,k;
bool holiday[400];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int c,v;
    scanf("%d",&c);
    reset(holiday,0);
    FOR(i,1,c){
        scanf("%d",&v);
        holiday[v]=1;
    }
    dp[0]=0;
    FOR(i,1,n+1){
        dp[i]=dp[i-1]+1;
        FORD(j,i-1,i-k){
            dp[i]=min(dp[i],dp[j]+1);
            if(j==0 || holiday[j]) break;
        }    
    }
    cout<<dp[n+1]-1<<endl;
    //getch();
    return 0;
}
