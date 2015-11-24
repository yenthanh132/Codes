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

int T,n,f[17][maxn],q,logg2[maxn];

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int get(int l, int r){
    if(l>r) return 0;
    int len=r-l+1;
    int lg2=logg2[len];
    return gcd(f[lg2][l],f[lg2][r-(1<<lg2)+1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    for(int i=1,k=0; i<=100000; ++i){
        while((1<<(k+1)) <= i) ++k;
        logg2[i]=k;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; ++i) scanf("%d",&f[0][i]);
        for(int k=1; (1<<k) <= n; ++k)
            for(int i=1; i<=n-(1<<k)+1; ++i)
                f[k][i] = gcd(f[k-1][i], f[k-1][i+(1<<k-1)]);
        for(int i=0,l,r; i<q; ++i){
            scanf("%d%d",&l,&r);
            printf("%d\n",gcd(get(1,l-1),get(r+1,n)));
        }
    }
}

