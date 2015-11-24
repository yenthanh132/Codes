#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 10007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

struct ITNode{
    int dp[20];
}IT[333333];
int n,q,a[maxn],b[maxn],C;

void updateNode(int i){
    ITNode &n1 = IT[i*2];
    ITNode &n2 = IT[i*2+1];
    for(int x=0; x<C; ++x) IT[i].dp[x]=0;
    for(int x=0; x<C; ++x) for(int y=0; x+y<C; ++y){
        IT[i].dp[x+y] += n1.dp[x]*n2.dp[y];
        IT[i].dp[x+y] %= oo;
    }
}

void init(int i, int l, int r){
    if(l==r){
        IT[i].dp[0]=b[l];
        IT[i].dp[1]=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    updateNode(i);
}

int mypow(int base, int n){
    if(n==0) return 1;
    int t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

void update(int i, int l, int r, int p, int x, int y){
    if(p<l || r<p) return;
    if(l==r){
        a[l] = x;
        b[l] = y;
        IT[i].dp[0] = y;
        IT[i].dp[1] = x;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p,x,y); update(i*2+1,mid+1,r,p,x,y);
    updateNode(i);
}

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&C);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), a[i]%=oo;
    for(int i=1; i<=n; ++i) scanf("%d",&b[i]), b[i]%=oo;

    int total=1;
    for(int i=1; i<=n; ++i){
        total = total * (a[i]+b[i])%oo;
    }
    init(1,1,n);

    int q;
    scanf("%d",&q);
    for(int i=1; i<=q; ++i){
        int p,x,y;
        scanf("%d%d%d",&p,&x,&y);
        x%=oo; y%=oo;

        total = total * mypow(a[p] + b[p], oo-2)%oo;
        update(1,1,n,p,x,y);
        total = total * (x+y)%oo;
        int res = total;
        for(int j=0; j<C; ++j) res = (res - IT[1].dp[j] + oo)%oo;
        printf("%d\n",res);
    }
}

