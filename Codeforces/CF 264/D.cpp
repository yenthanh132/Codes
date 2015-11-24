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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;


int a[6][maxn],pos[6][maxn],dp[maxn];
int n,k;

bool check(int v1, int v2){
    for(int i=2; i<=k; ++i) if(pos[i][v1]>pos[i][v2]) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=k; ++i)
        for(int j=1; j<=n; ++j){
            scanf("%d",&a[i][j]);
            pos[i][a[i][j]]=j;
        }
    int res = 1;
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        dp[i]=1;
        for(int j=i-1; j>0; --j){
            int v1=a[1][j], v2=a[1][i];
            if(check(v1,v2)) dp[i]=max(dp[i],dp[j]+1);
        }
        res = max(res,dp[i]);
    }
    cout<<res<<endl;

    return 0;
}
