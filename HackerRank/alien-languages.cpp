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
#define oo 100000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int n,m;
ll f[maxn], dp[maxn][20], cnt[30];

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&n,&m);
        reset(dp,0);
        for(int i=1; i<=n; ++i) if(i*2>n) dp[i][1]=1;
        for(int len=2; len<20; ++len){
            int sum=0, last=n;
            for(int i=n/2; i>=1; --i){
                while(i*2<=last) sum=(sum+dp[last--][len-1])%oo;
                dp[i][len]=sum;
            }
        }
        for(int len=1; len<20; ++len){
            cnt[len]=0;
            for(int i=1; i<=n; ++i) cnt[len]=(cnt[len] + dp[i][len])%oo;
        }

        reset(f,0);
        f[0]=1;
        for(int i=0; i<=m; ++i){
            for(int len=1; len<20 && i+len<=m; ++len) f[i+len]=(f[i+len] + f[i]*cnt[len])%oo;
        }
        printf("%lld\n",f[m]);
    }

    return 0;
}
