#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll C[4444][4444], dp[2222][2222];
int T,m,n;

int main(){
//    freopen("input.txt","r",stdin);

    C[0][0]=1;
    for(int i=1; i<=4000; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;
    }

    cin>>T;
    while(T--){
        cin>>n>>m;
        dp[0][0]=1;
        ll res=0;
        for(int i=1; i<=n; ++i){
            ll sum=0;
            for(int j=0; j<=m; ++j){
                sum=(sum+dp[i-1][j])%oo;
                dp[i][j]=sum*C[j+m-1][j]%oo;
                if(i==n) res=(res+dp[i][j])%oo;
            }
        }

        cout<<res<<endl;
    }
}

