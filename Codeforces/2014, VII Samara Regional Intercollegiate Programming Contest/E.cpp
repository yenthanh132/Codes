#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    if(a==-1 || b==-1) return -1;
    ll d = gcd(a,b);
    a/=d;
    if((a*b)/b!=a) return -1;
    return a*b;
}

const int maxn=100007;

int t[maxn],n,m;
ll a[maxn],b[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&t[i]);
    a[0]=1;
    a[1]=t[1];
    for(int i=2; i<=n; ++i) a[i]=lcm(a[i-1],t[i]);
    b[n+1]=1;
    b[n]=t[n];
    for(int i=n-1; i>=1; --i) b[i]=lcm(b[i+1],t[i]);

    for(int i=1; i<=n; ++i){
        ll mm = lcm(a[i-1],b[i+1]);
        if(mm==-1 || mm%t[i]==0){
            puts("Never");
            continue;
        }
        ll v = (mm - m%mm)%mm;
        while((v + m)%t[i]==0) v+=mm;
        if(v>1e9)
            puts("Never");
        else{
            printf("%I64d\n",v);
        }
    }

}

