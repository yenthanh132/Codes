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

struct ITNode{
    int t;
    int a[3];
}IT[maxn*4];

int n,s[maxn],m,a[maxn];
char str[maxn];

void init(int i, int l, int r){
    IT[i].t=IT[i].a[0]=IT[i].a[1]=IT[i].a[2]=0;
    if(l==r){
        IT[i].a[s[l]]++;
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    for(int j=0; j<3; ++j)
        IT[i].a[j]=(IT[i*2].a[j]+IT[i*2+1].a[j]);
}

void rotate(int a[3]){
    int t=a[2];
    a[2]=a[1]; a[1]=a[0]; a[0]=t;
}

void lazyupdate(int i, int l, int r){
    IT[i].t%=3;
    if(IT[i].t==0) return;
    if(l<r){
        IT[i*2].t+=IT[i].t;
        IT[i*2+1].t+=IT[i].t;
    }
    for(int r=0; r<IT[i].t; ++r) rotate(IT[i].a);
    IT[i].t=0;
}

void update(int i, int l, int r, int s, int f, int x){
    lazyupdate(i,l,r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        IT[i].t+=x;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,x); update(i*2+1,mid+1,r,s,f,x);
    for(int j=0; j<3; ++j)
        IT[i].a[j]=(IT[i*2].a[j]+IT[i*2+1].a[j]);
}

int ret[3];
void get(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        for(int j=0; j<3; ++j) ret[j]+=IT[i].a[j];
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    for(int j=0; j<3; ++j)
        IT[i].a[j]=(IT[i*2].a[j]+IT[i*2+1].a[j]);
}

void sss(){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j) ret[j]=0;
        get(1,1,n,i,i);
        int x=0;
        while(!ret[x]) ++x;
        cout<<x<<' ';
    }
    cout<<endl;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    s[0]=0;
    for(int i=1; i<=n; ++i){
        a[i]=str[i]-'0';
        s[i]=(s[i-1]+a[i])%3;
    }
    init(1,1,n);
    int k,x,y;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&k,&x,&y);
        if(k==1){
            int dis = (y - a[x] + 12)%3;
            if(dis) update(1,1,n,x,n,dis);
            a[x]=y;
        }else{
            for(int j=0; j<3; ++j) ret[j]=0;
            ll res = 0;
            if(x>1) get(1,1,n,x-1,y);
            else{
                get(1,1,n,x,y);
                ++ret[0];
            }
            for(int j=0; j<3; ++j) res += 1ll*ret[j]*(ret[j]-1)/2;
            printf("%lld\n",res);
        }
    }
}

