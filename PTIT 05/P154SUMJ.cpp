#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn = 100007;

struct node{
    int t;
    ll sum[6];
} IT[maxn*4];

ll sum[6][maxn];
int arr[maxn],n,q;
ll com[10][10];

void lazyupdate(int i, int l, int r){
    if(IT[i].t==-1) return;
    int v=IT[i].t, len=r-l+1;

    for(int j=0; j<=5; ++j){
        IT[i].sum[j] = sum[j][len]*v%oo;
    }
    if(l<r) IT[i*2].t = IT[i*2+1].t = v;
    IT[i].t = -1;
}

ll val[6];

void update(int i, int l, int r){
    int mid = (l+r)/2;
    int v1 = mid+1-l;

    ll mul=1;
    for(int x=0; x<=5; ++x){
        val[x]=mul%oo;
        IT[i].sum[x]=IT[i*2].sum[x];
        for(int y=0; y<=x; ++y)
            IT[i].sum[x] = (IT[i].sum[x] + IT[i*2+1].sum[y]*val[x-y]%oo *com[x][y])%oo;

        mul=mul*v1%oo;
    }
}

void init(int i, int l, int r){
    IT[i].t = -1;
    if(l==r){
        for(int j=0; j<=5; ++j)
            IT[i].sum[j] = arr[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    update(i,l,r);
}

void query1(int i, int l, int r, int s, int f, int v){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i].t = v;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    query1(i*2,l,mid,s,f,v);
    query1(i*2+1,mid+1,r,s,f,v);
    update(i,l,r);
}

ll ans;

void query2(int i, int l, int r, int s, int f, int k){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        int v1=l-s;
        ll mul=1;
        for(int x=0; x<=k; ++x){
            val[x] = mul%oo;
            mul = mul*v1%oo;
        }
        for(int y=0; y<=k; ++y) ans = (ans + IT[i].sum[y]*val[k-y]%oo *com[k][y]%oo)%oo;
        return;
    }
    int mid=(l+r)/2;
    query2(i*2,l,mid,s,f,k);
    query2(i*2+1,mid+1,r,s,f,k);
    update(i,l,r);
}

int main(){
//    freopen("input.txt","r",stdin);

    com[0][0]=1;
    for(int i=1; i<=5; ++i){
        com[i][0]=1;
        for(int j=1; j<=i; ++j) com[i][j]=(com[i-1][j]+com[i-1][j-1])%oo;
    }

    for(int i=1; i<=100000; ++i){
        ll mul=1;
        for(int j=0; j<=5; ++j){
            sum[j][i]=(sum[j][i-1]+mul)%oo;
            mul=mul*i%oo;
        }
    }

    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&arr[i]);
    init(1,1,n);

    int key,l,r,v;
    for(int i=0; i<q; ++i){
        scanf("%d%d%d%d",&key,&l,&r,&v);
        if(key==0) query1(1,1,n,l,r,v);
        else{
            ans=0;
            query2(1,1,n,l,r,v);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
