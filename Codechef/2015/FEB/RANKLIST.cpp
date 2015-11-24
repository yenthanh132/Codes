#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T;
ll n,s;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&s);
        ll l=1, r=n, mid;
        int res=1;
        while(l<=r){
            mid=(l+r)/2;
            ll val = mid*(mid-1)/2 + n;
            if(val<=s){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        printf("%d\n",n-res);
    }
}

