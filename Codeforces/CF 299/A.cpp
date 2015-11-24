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

ll A,B;
int n;

bool check(ll l, ll r, ll m, ll t){
    ll len = r-l+1;
    ll sum = A*len + B*( r*(r-1)/2 - (l-2)*(l-1)/2 );
    return sum <= m*t && (A + (r-1)*B) <= t;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%I64d%I64d%d",&A,&B,&n);
    int l,r,m,t;
    for(int i=0; i<n; ++i){
        scanf("%d%d%d",&l,&t,&m);
        int res=-1;
        r=oo;
        int l0=l;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(l0,mid,m,t)){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        printf("%d\n",res);
    }
}

