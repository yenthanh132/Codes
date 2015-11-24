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
const int base=73471;
const int base2=2;

struct node{
    ll val,val2;
    int T;
    node(){
        val=0;
        T=-1;
    }
} IT[maxn*4];

ll pw[maxn],pw2[maxn];
ll full[10][maxn],full2[10][maxn];

int n,m,k;
char s[maxn];

void init(int i, int l, int r){
    IT[i].T=-1;
    if(l==r){
        IT[i].val = s[l]-'0';
        IT[i].val2 = s[l]-'0';
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    int lenRight=r-mid;
    IT[i].val = (IT[i*2].val * pw[lenRight] + IT[i*2+1].val)%oo;
    IT[i].val2 = IT[i*2].val2 * pw2[lenRight] + IT[i*2+1].val2;
}

void lazyUpdate(int i, int l, int r){
    if(IT[i].T==-1) return;
    IT[i].val = full[IT[i].T][r-l+1];
    IT[i].val2 = full2[IT[i].T][r-l+1];
    if(l<r) IT[i*2].T = IT[i*2+1].T = IT[i].T;
    IT[i].T = -1;
}

void update(int i, int l, int r, int s, int f, int c){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i].T = c;
        lazyUpdate(i,l,r);
        return;
    }

    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,c); update(i*2+1,mid+1,r,s,f,c);
    int lenRight=r-mid;
    IT[i].val = (IT[i*2].val * pw[lenRight] + IT[i*2+1].val)%oo;
    IT[i].val2 = IT[i*2].val2 * pw2[lenRight] + IT[i*2+1].val2;
}

ll resIT=0;
ll resIT2=0;

void get(int i, int l, int r, int s, int f){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        resIT = (resIT + IT[i].val * pw[f-r])%oo;
        resIT2 = resIT2 + IT[i].val2 * pw2[f-r];
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    int lenRight=r-mid;
    IT[i].val = (IT[i*2].val * pw[lenRight] + IT[i*2+1].val)%oo;
    IT[i].val2 = IT[i*2].val2 * pw2[lenRight] + IT[i*2+1].val2;
}

pair<ll,ll> get(int l, int r){
    resIT=0;
    resIT2=0;
    get(1,1,n,l,r);
    return pair<ll,ll>(resIT,resIT2);
}


bool equal_s(int l1, int r1, int l2, int r2){
    return get(l1,r1)==get(l2,r2);
}

bool check(int l, int r, int k){

    int len=r-l+1;
    if(k==len) return 1;
    int x=k;
    while(x*2<len) x*=2;
    while(x>=k){
        int i1=l, j1=l+x-1;
        int i2=l+x, j2=l+x+x-1;
        if(j2>r){
            j1-=j2-r;
            j2=r;
        }
        if(!equal_s(i1,j1,i2,j2)) return 0;
        x>>=1;
    }

    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);

    pw[0]=1; pw2[0]=1;
    for(int i=1; i<=100000; ++i) pw[i]=pw[i-1]*base%oo, pw2[i]=pw2[i-1]*base2;
    for(int c=0; c<10; ++c){
        full[c][0]=0;
        for(int i=1; i<=100000; ++i) full[c][i]=(full[c][i-1]*base+c)%oo, full2[c][i]=full2[c][i-1]*base2+c;
    }

    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",s+1);
    init(1,1,n);

    for(int i=1; i<=m+k; ++i){
        int t,l,r,k;
        scanf("%d%d%d%d",&t,&l,&r,&k);
        if(t==1){
            update(1,1,n,l,r,k);
        }else{
            if(check(l,r,k)) puts("YES");
            else puts("NO");
        }
    }

}

