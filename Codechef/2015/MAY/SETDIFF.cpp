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

int a[maxn],n,T;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll res = 0, sp2 = 0, p2 = 1, sum = 0;
        for(int i=2; i<=n; ++i){
            sp2 = (sp2 + p2)%oo;
            p2 = p2*2%oo;
            sum = (sum*2 + a[i-1])%oo;
            res = (res + sp2*a[i] - sum + oo)%oo;
        }
        printf("%lld\n",res);
    }
}

