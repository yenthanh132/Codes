#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int a[maxn],b[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    int T,n,k;
    ll res;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d%d",&n,&k);
        res=0;
        for(int i=0; i<n; ++i) scanf("%d",&a[i]);
        for(int i=0; i<n; ++i) scanf("%d",&b[i]);
        for(int i=0; i<n; ++i){
            res = max( res, 1ll*(k/a[i])*b[i]);
        }
        printf("%lld\n",res);
    }
}
