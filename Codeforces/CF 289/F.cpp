#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=507;

int a[maxn],n;
ll f[maxn][maxn],f2[maxn][maxn];

ll dp(int i, int j);
ll dp2(int i, int j);
//=====================

ll dp2(int i, int j){
    if(f2[i][j]!=-1) return f2[i][j];
    ll &res=f2[i][j];
    if(i==j) return (res=1);
    res=dp(i,j);
    for(int x=i+1; x<=j; ++x)
        if(a[i]<a[x])
            res = (res + dp(i,x-1)*dp2(x,j))%oo;
    return res;
}

ll dp(int i, int j){
    if(f[i][j]!=-1) return f[i][j];
    ll &res=f[i][j]; res=0;
    if(i==j) return (res=1);
    return (res=dp2(i+1,j));
}

int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    reset(f,-1); reset(f2,-1);
    cout<<dp(1,n)<<endl;
}
