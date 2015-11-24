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

const int maxn=500007;

int n,v[maxn],p[maxn];
ll sv[maxn], dp[maxn],bit[maxn*2];

ll get(int i){
    ll res = -oo;
    for(;i<=1000000; i+=i&(-i)) res = max(res,bit[i]);
    return res;
}

void update(int i, ll v){
    for(;i;i-=i&(-i)) bit[i]=max(bit[i],v);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    sv[0]=0;
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&v[i],&p[i]);
        sv[i] = sv[i-1] + v[i];
    }

    if(n==1){
        cout<<v[1]<<endl;
        return 0;
    }

    for(int i=1; i<=1000000; ++i) bit[i]=-oo;

    dp[1] = 0;
    update(1+p[1],dp[1] - sv[1]);
    for(int i=2; i<n; ++i){
        dp[i] = sv[i-1] + get(i);
        update(i+p[i],dp[i] - sv[i]);
    }
    ll res = 0;
    for(int i=1; i<n; ++i) if(n-i <= p[i]) res = max(res, dp[i] + sv[n] - sv[i]);
    cout<<res<<endl;

    //i <= p[j] + j
    //dp[i] = max(dp[j] + sv[i-1] - sv[j])

    return 0;
}
