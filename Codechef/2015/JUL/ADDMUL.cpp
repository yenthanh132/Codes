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

struct ITNode{
    ll A,B,val;
}IT[maxn*4];

int n,q,a[maxn];

void lazyupdate(int i, int l, int r){
    if(IT[i].A==1 && IT[i].B==0) return;
    IT[i].val = (IT[i].val*IT[i].A + IT[i].B*(r-l+1))%oo;
    if(l<r){
        IT[i*2].A = (IT[i*2].A * IT[i].A)%oo;
        IT[i*2].B = (IT[i*2].B * IT[i].A + IT[i].B)%oo;

        IT[i*2+1].A = (IT[i*2+1].A * IT[i].A)%oo;
        IT[i*2+1].B = (IT[i*2+1].B * IT[i].A + IT[i].B)%oo;
    }

    IT[i].A = 1;
    IT[i].B = 0;
}

void init(int i, int l, int r){
    IT[i].A = 1; IT[i].B = 0;
    if(l==r){
        IT[i].val = a[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    IT[i].val = (IT[i*2].val + IT[i*2+1].val)%oo;
}

void add(int i, int l, int r, int s, int f, int v){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;

    if(s<=l && r<=f){
        IT[i].B = v;
        lazyupdate(i,l,r);
        return;
    }

    int mid=(l+r)/2;
    add(i*2,l,mid,s,f,v); add(i*2+1,mid+1,r,s,f,v);
    IT[i].val = (IT[i*2].val + IT[i*2+1].val)%oo;
}

void mul(int i, int l, int r, int s, int f, int v){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;

    if(s<=l && r<=f){
        IT[i].A = v;
        lazyupdate(i,l,r);
        return;
    }

    int mid=(l+r)/2;
    mul(i*2,l,mid,s,f,v); mul(i*2+1,mid+1,r,s,f,v);
    IT[i].val = (IT[i*2].val + IT[i*2+1].val)%oo;
}

ll staticSum;
void sum(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;

    if(s<=l && r<=f){
        staticSum = (staticSum + IT[i].val)%oo;
        return;
    }

    int mid=(l+r)/2;
    sum(i*2,l,mid,s,f); sum(i*2+1,mid+1,r,s,f);
    IT[i].val = (IT[i*2].val + IT[i*2+1].val)%oo;
}

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    init(1,1,n);
    int key,l,r,v;
    for(int i=0; i<q; ++i){

        scanf("%d%d%d",&key,&l,&r);
        if(key<=3) scanf("%d",&v);
        if(key==1) add(1,1,n,l,r,v);
        else if(key==2) mul(1,1,n,l,r,v);
        else if(key==3){
            mul(1,1,n,l,r,0);
            add(1,1,n,l,r,v);
        }else{
            staticSum = 0;
            sum(1,1,n,l,r);
            printf("%lld\n",staticSum);
        }
    }

    return 0;
}

