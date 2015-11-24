#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[111][111],m,n;
int rx[111],ry[111];

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>m>>n;
    int M=0;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) cin>>a[i][j], M=max(a[i][j],M);
    rx[1]=0;
    for(int j=1; j<=n; ++j) ry[j]=a[1][j];
    for(int i=2; i<=m; ++i) rx[i]=a[i][1]-ry[1];
    ll K=0;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) K=gcd(K,abs(1ll*a[i][j]-rx[i]-ry[j]));

    if(K==0 || K>M){
        cout<<"YES"<<endl;
        if(K==0) K=M+1;
        cout<<K<<endl;
        for(int i=1; i<=m; ++i) cout<<(rx[i]%K+K)%K<<' '; cout<<endl;
        for(int j=1; j<=n; ++j) cout<<(ry[j]%K+K)%K<<' '; cout<<endl;
    }else
        cout<<"NO"<<endl;
}

