#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;

struct mat{
    ll a[3][3];
    int r,c;
} pw[maxn];

mat operator*(mat a, mat b){
    mat c;
    c.r=a.r; c.c=b.c;
    for(int i=0; i<c.r; ++i) for(int j=0; j<c.c; ++j){
        c.a[i][j]=0;
        for(int k=0; k<a.c; ++k) c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j])%oo;
    }
    return c;
}

struct ITNode{
    ll u,v,sum;
} IT[maxn*4];

void lazyupdate(int i, int l, int r){
    if(IT[i].u==0 && IT[i].v==0) return;
    if(l==r){
        IT[i].sum=(IT[i].sum+IT[i].u)%oo;
        IT[i].u=IT[i].v=0;
        return;
    }
    int len=r-l+1;
    mat mul;
    mul.r=3; mul.c=1;
    mul.a[0][0]=IT[i].u;
    mul.a[1][0]=IT[i].v;
    mul.a[2][0]=IT[i].u+IT[i].v;

    mat res = pw[len-2]*mul;
    IT[i].sum = (IT[i].sum + res.a[2][0])%oo;

    IT[i*2].u = (IT[i*2].u + IT[i].u)%oo;
    IT[i*2].v = (IT[i*2].v + IT[i].v)%oo;

    int mid=(l+r)/2;
    res = pw[mid-l+1] * mul;
    IT[i*2+1].u = (IT[i*2+1].u + res.a[0][0])%oo;
    IT[i*2+1].v = (IT[i*2+1].v + res.a[1][0])%oo;

    IT[i].u=IT[i].v=0;
}

void add(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        mat mul;
        mul.r=3; mul.c=1;
        mul.a[0][0]=1;
        mul.a[1][0]=1;
        mul.a[2][0]=2;

        mat res = pw[l-s] * mul;
        IT[i].u = res.a[0][0];
        IT[i].v = res.a[1][0];
        lazyupdate(i,l,r);
        return;
    }

    int mid=(l+r)/2;
    add(i*2,l,mid,s,f); add(i*2+1,mid+1,r,s,f);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}

ll resIT;
void get(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        resIT = (resIT + IT[i].sum)%oo;
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}


int n,m,k,l,r;
ll s[maxn];

int main(){
    //freopen("input.txt","r",stdin);

    pw[0].r=3; pw[0].c=3;
    pw[0].a[0][0] = 1; pw[0].a[0][1] = 0; pw[0].a[0][2] = 0;
    pw[0].a[1][0] = 0; pw[0].a[1][1] = 1; pw[0].a[1][2] = 0;
    pw[0].a[2][0] = 0; pw[0].a[2][1] = 0; pw[0].a[2][2] = 1;

    pw[1].r=3; pw[1].c=3;
    pw[1].a[0][0] = 0; pw[1].a[0][1] = 1; pw[1].a[0][2] = 0;
    pw[1].a[1][0] = 1; pw[1].a[1][1] = 1; pw[1].a[1][2] = 0;
    pw[1].a[2][0] = 1; pw[1].a[2][1] = 1; pw[1].a[2][2] = 1;
    for(int i=2; i<=300000; ++i) pw[i]=pw[i-1]*pw[1];


    s[0]=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        scanf("%I64d",&s[i]);
        s[i]=(s[i-1]+s[i])%oo;
    }
    for(int i=0; i<m; ++i){+
        scanf("%d%d%d",&k,&l,&r);
        if(k==1) add(1,1,n,l,r);
        else{
            resIT=(s[r]-s[l-1]+oo)%oo;
            get(1,1,n,l,r);
            printf("%I64d\n",resIT);
        }
    }

    return 0;
}
