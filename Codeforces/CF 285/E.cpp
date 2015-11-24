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

int n,a[maxn],c[maxn],cnt,cntNeg;
int f[maxn];

void init(){
    for(int i=1; i<=n; ++i) c[i]=0;
    cnt=0;
    cntNeg=0;
}

void add(int v){
    ++c[v];
    if(c[v]&1) ++cnt;
    else --cnt;
    if(c[v]==0) --cntNeg;
}

void del(int v){
    --c[v];
    if(c[v]&1) ++cnt;
    else --cnt;
    if(c[v]==-1) ++cntNeg;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    int l,r;
    reset(f,0);
    if(n&1) f[(n+1)/2]=1;
    l=n/2; r=l+1;
    while(l>=1){
        if(a[l]!=a[r]) break;
        f[l]=f[r]=1;
        --l; ++r;
    }

    l=1; r=n;
    while(l<=n){
        if(a[l]!=a[r]) break;
        ++l; --r;
    }
    --l; ++r;
    if(l==n){
        printf("%I64d\n",1ll*n*(n+1)/2);
        return 0;
    }



    ll res=0;
    init();
    for(int i=l+1; i<=n; ++i){
        if(i<=n/2){
            add(a[i]);
            del(a[n-i+1]);
        }else if(i==n-i+1){
            add(a[i]);
        }else if(i<=n-l){
            add(a[i]);
            add(a[i]);
        }else{
            add(a[i]);
            del(a[n-i+1]);
        }
        if(cnt<=1 && cntNeg==0 && (i+1>n/2 || f[i+1])){
            res+=1ll*(l+1)*(n-i+1);
            break;
        }
    }

    init();
    reverse(a+1,a+n+1);
    for(int i=l+1; i<=n; ++i){
        if(i<=n/2){
            add(a[i]);
            del(a[n-i+1]);
        }else if(i==n-i+1){
            add(a[i]);
        }else if(i<=n-l){
            add(a[i]);
            add(a[i]);
        }else{
            add(a[i]);
            del(a[n-i+1]);
        }
        if(cnt<=1 && cntNeg==0 && (i+1>n/2 || f[i+1])){
            res+=1ll*(l+1)*max(0,r-i-1);
            break;
        }
    }

    printf("%I64d\n",res);
}
