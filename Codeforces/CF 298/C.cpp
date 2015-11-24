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

int d[maxn],n;
ll A,sum;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%I64d",&n,&A);
    sum=0;
    for(int i=1; i<=n; ++i){
        scanf("%d",&d[i]);
        sum+=d[i];
    }
    for(int i=1; i<=n; ++i){
        ll t=sum-d[i];
        ll left = A - t - 1;
        ll right = A - (n-1) + 1;
        left = max(left,0ll);
        right = min(right,1ll*d[i]+1);
        printf("%I64d ",d[i]-max(0ll,right-left-1));
    }
}

