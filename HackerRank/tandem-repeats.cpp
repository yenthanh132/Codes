#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const ll base=73471;

const int maxn=100007;
ll pw[maxn],val[maxn];
char s[maxn];
int n,m;

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    val[0]=0;
    pw[0]=1;
    for(int i=1; i<=n; ++i){
        pw[i]=pw[i-1]*base%oo;
        val[i]=(val[i-1]*base + s[i]-'a')%oo;
    }

    for(int i=1; i<=m; ++i){
        int l,r;
        scanf("%d%d",&l,&r);
        int len=r-l+1;
        ll v1 = (val[r]-val[l-1]*pw[len]%oo+oo)%oo;
        int left=2, right = (n-l+1)/len, mid, res=1;
        while(left<=right){
            mid=(left+right)/2;
            ll v2 = (val[l+mid*len-1]-val[l-1]*pw[mid*len]%oo+oo)%oo;
            if(v1 * (mypow(pw[len],mid) - 1 + oo ) % oo == v2 * (pw[len] - 1 + oo) % oo){
                res = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        printf("%d\n",res);
    }
}

