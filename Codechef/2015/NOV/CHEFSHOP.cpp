#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,a[22],n,dp[1<<15];
bool mark[1<<15];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1,a+n+1,greater<int>());

        reset(mark,0);
        int m;
        cin>>m;
        for(int i=0; i<m; ++i){
            int c,v;
            cin>>c;
            int state=0;
            for(int j=0; j<c; ++j){
                cin>>v; --v;
                state |= 1<<v;
            }
            mark[state]=1;
        }

        reset(dp,-1);
        dp[0]=0;
        int res=0;
        for(int bit=0; bit<(1<<n); ++bit) if(dp[bit]!=-1){
            res=max(res,dp[bit]);
            int e = ((1<<n)-1) ^ bit;
            int v=e;
            while(v>0){
                if(mark[v]){
                    int bit2 = bit | v;
                    int cnt = __builtin_popcount(bit2);
                    dp[bit2] = max(dp[bit2], dp[bit] + a[cnt]);
                }
                v=(v-1)&e;
            }
        }
        res *= -1;
        for(int i=1; i<=n; ++i) res += a[i];
        cout<<res<<endl;
    }
}

