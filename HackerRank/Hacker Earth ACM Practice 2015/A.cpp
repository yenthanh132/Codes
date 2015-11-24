#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,q,minv,maxv;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        minv=oo; maxv=-oo;
        for(int i=0; i<n; ++i){
            int v;
            scanf("%d",&v);
            minv=min(minv,v);
            maxv=max(maxv,v);
        }
        printf("%lld\n",1ll*(maxv-minv)*q);
    }
}

