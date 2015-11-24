#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[100007];
int n,k;

int main(){
//    freopen("input.txt","r",stdin);
    dp[0]=1;
    cin>>n>>k;
    ll total=0;
    for(int i=1; i<=n; ++i){
        int v; cin>>v;
        total+=v;
        for(int x=k-v-1; x>=0; --x)  dp[x+v]=(dp[x+v]+dp[x])%oo;
    }
    ll p2=1;
    for(int i=1; i<=n; ++i) p2=p2*2%oo;
    ll sum=0;
    for(int x=0; x<k; ++x){
        sum=(sum+dp[x])%oo;
        if(total-x>=k)
            sum=(sum+dp[x])%oo;
    }
    cout<<(p2-sum+oo)%oo<<endl;
}

