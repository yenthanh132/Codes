#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int x[maxn],y[maxn],n;
ll res;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
    sort(x+1,x+n+1); sort(y+1,y+n+1);
    res=0;
    ll sum1=0,sum2=0;
    for(int i=1; i<=n; ++i){
        res += 1ll*x[i]*(i-1) - sum1;
        res += 1ll*y[i]*(i-1) - sum2;
        res%=oo;
        sum1 += x[i];
        sum1%=oo;
        sum2 += y[i];
        sum2%=oo;
    }
    cout<<res<<endl;

}

