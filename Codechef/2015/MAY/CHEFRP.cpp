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

int T,a[maxn],n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum = 0, minv = oo;
        for(int i=0,v; i<n; ++i){
            scanf("%d",&v);
            minv=min(minv,v);
            sum+=v;
        }
        int res;
        if(minv<2) res=-1;
        else res = sum - minv + 2;
        printf("%d\n",res);
    }
}

