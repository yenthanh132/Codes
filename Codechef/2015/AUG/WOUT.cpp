#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int d[1111111];
ll s[1111111];
int n,h;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&h);
        for(int i=1; i<=n; ++i) d[i]=0;
        int l,r;
        for(int i=0; i<n; ++i){
            scanf("%d%d",&l,&r);
            ++d[l+1];
            --d[r+2];
        }
        s[0]=0;
        for(int i=1,v=0; i<=n; ++i){
            v+=d[i];
            s[i]=s[i-1]+v;
        }
        ll sz=1ll*n*h;
        ll res=sz-s[h];
        for(int i=h+1; i<=n; ++i) res=min(res, sz - (s[i]-s[i-h]));
        printf("%lld\n",res);
    }
}

