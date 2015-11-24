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

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int a[maxn],n,q;
int f[maxn][20],lg2[maxn];
map<int,ll> cnt;

int get_gcd(int x, int y){
    int len=y-x+1;
    int d=lg2[len];
    int v1=f[x][d], v2=f[y-(1<<d)+1][d];
    return gcd(v1,v2);
}



int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), f[i][0]=a[i];
    for(int j=1; j<20; ++j){
        for(int i=1; i<=n-(1<<j)+1; ++i)
            f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
    for(int l=1,p=0; l<=n; ++l){
        while(1<<(p+1) <= l) ++p;
        lg2[l]=p;
    }

    for(int i=1; i<=n; ++i){
        int lbound=i, curGCD = a[i];
        while(lbound<=n){
            int l=lbound+1, r=n, mid, pos=n+1;
            while(l<=r){
                mid=(l+r)/2;
                if(get_gcd(i,mid)!=curGCD){
                    pos=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            if(pos==n+1){
                cnt[curGCD] += pos-lbound;
                lbound = pos;
                break;
            }else{
                cnt[curGCD] += pos-lbound;
                curGCD = get_gcd(i,pos);
                lbound = pos;
            }
        }
    }

    scanf("%d",&q);
    int x;
    for(int i=0; i<q; ++i){
        scanf("%d",&x);
        printf("%I64d\n",cnt[x]);
    }

    return 0;
}

