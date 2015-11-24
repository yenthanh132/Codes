#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;
struct ITNode{
    ll a,b,c,d,sum;
}IT[maxn*4];

int n,m,q,total;

void lazyupdate(int i, int l, int r){
    ll len=r-l+1;
    ll len1=len+1;
    if(len%2==0) len/=2; else len1/=2;
    ll t=len*len1%oo;

    if(l<r){
        int mid=(l+r)/2;
        IT[i*2].a = (IT[i*2].a + IT[i].a)%oo;
        IT[i*2].b = (IT[i*2].b + IT[i].b)%oo;
        IT[i*2].c = (IT[i*2].c + IT[i].c)%oo;
        IT[i*2].d = (IT[i*2].d + IT[i].d + IT[i].c*(r-mid))%oo;

        IT[i*2+1].a = (IT[i*2+1].a + IT[i].a)%oo;
        IT[i*2+1].b = (IT[i*2+1].b + IT[i].b + IT[i].a*(mid-l+1))%oo;
        IT[i*2+1].c = (IT[i*2+1].c + IT[i].c)%oo;
        IT[i*2+1].d = (IT[i*2+1].d + IT[i].d)%oo;
    }

    if(IT[i].a>0 || IT[i].b>0){
        IT[i].sum = (IT[i].sum + IT[i].a*t + IT[i].b*(r-l+1))%oo;
    }
    if(IT[i].c>0 || IT[i].d>0){
        IT[i].sum = (IT[i].sum + IT[i].c*t + IT[i].d*(r-l+1))%oo;
    }

    IT[i].a = 0;
    IT[i].b = 0;
    IT[i].c = 0;
    IT[i].d = 0;

}

void updateLR(int i, int l, int r, int s, int f, ll d){
    lazyupdate(i,l,r);
    if(r<s || f<l) return;
    if(s<=l && r<=f){
        ll t=l-s;
        IT[i].a = d;
        IT[i].b = d*t%oo;
        lazyupdate(i,l,r);
        return;
    }
    int mid = (l+r)/2;
    updateLR(i*2,l,mid,s,f,d); updateLR(i*2+1,mid+1,r,s,f,d);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}

void updateRL(int i, int l, int r, int s, int f, ll d){
    lazyupdate(i,l,r);
    if(r<s || f<l) return;
    if(s<=l && r<=f){
        ll t=f-r;
        IT[i].c = d;
        IT[i].d = d*t%oo;
        lazyupdate(i,l,r);
        return;
    }
    int mid = (l+r)/2;
    updateRL(i*2,l,mid,s,f,d); updateRL(i*2+1,mid+1,r,s,f,d);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}

void update(int i, int l, int r, int s, int f, ll d){
    lazyupdate(i,l,r);
    if(r<s || f<l) return;
    if(s<=l && r<=f){
        IT[i].b = d;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,d); update(i*2+1,mid+1,r,s,f,d);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}

ll sumT;

void getSum(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(r<s || f<l) return;
    if(s<=l && r<=f){
        sumT = (sumT + IT[i].sum)%oo;
        return;
    }
    int mid=(l+r)/2;
    getSum(i*2,l,mid,s,f); getSum(i*2+1,mid+1,r,s,f);
    IT[i].sum = (IT[i*2].sum + IT[i*2+1].sum)%oo;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    char key[5];
    total = n+m-1;
    for(int i=0; i<q; ++i){
        scanf("%s",key);
        if(key[1]=='c'){
            int col,d;
            scanf("%d%d",&col,&d);
            int l=col;
            int r=l+n-1;
            updateRL(1,1,total,l,r,d);
        }else if(key[1]=='r'){
            int row,d;
            scanf("%d%d",&row,&d);
            int l=n-row+1, r=l+m-1;
            updateLR(1,1,total,l,r,d);
        }else if(key[1]=='s'){
            int x1,y1,x2,y2,d;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&d);
            int l1,r1,l2,r2,len;
            len = min(x2-x1,y2-y1);
            l1=y1+(n-x2);
            r1=l1+len-1;
            if(l1<=r1) updateLR(1,1,total,l1,r1,d);

            r2=y2+(n-x1);
            l2=r2-len+1;
            if(l2<=r2) updateRL(1,1,total,l2,r2,d);

            ll dd=1ll*d*(len+1)%oo;
            update(1,1,total,r1+1,l2-1,dd);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            sumT=0;
            getSum(1,1,total,l,r);
            printf("%lld\n",sumT);
        }

    }
}

