#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,n,a[1111];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        int res = oo;
        for(int v=1; v<=1000; ++v){
            int t=0;
            for(int i=1; i<=n; ++i) t+=(a[i]-1)/v;
            res = min(res, t + v);
        }
        printf("Case #%d: %d\n",tt,res);
    }
}

