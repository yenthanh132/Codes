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
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

ll dp[2][maxn],s[maxn];
int n,m,k,a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
    int flag=0; reset(dp,0);
    ll res = -oo;
    for(int i=1; i<=k; ++i){
        flag^=1;
        ll maxv=-oo;
        for(int j=1; j<=n; ++j){
            if(j<i*m)
                dp[flag][j]=-oo;
            else{
                maxv=max(maxv,dp[1^flag][j-m]);
                dp[flag][j]=s[j]-s[j-m] + maxv;
                if(i==k) res = max(res, dp[flag][j]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
