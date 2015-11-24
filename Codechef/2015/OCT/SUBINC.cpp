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

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        ll res=0;
        for(int i=1; i<=n; ){
            int j=i;
            while(j+1<=n && a[j+1]>=a[j]) ++j;
            ll len=j-i+1;
            res += len*(len+1)/2;
            i=j+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}




