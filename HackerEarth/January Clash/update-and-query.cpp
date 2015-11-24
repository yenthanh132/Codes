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

int IT[2][maxn*4];
int a[maxn],n,m;

void init(int i, int l, int r){
    if(l==r){
        IT[0][i] = IT[1][i] = a[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    IT[0][i] = min(IT[0][i*2], IT[0][i*2+1]);
    IT[1][i] = max(IT[1][i*2], IT[1][i*2+1]);
}

void update(int i, int l, int r, int p){
    if(p<l || p>r) return;
    if(l==r){
        IT[0][i] = IT[1][i] = a[l];
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p); update(i*2+1,mid+1,r,p);
    IT[0][i] = min(IT[0][i*2], IT[0][i*2+1]);
    IT[1][i] = max(IT[1][i*2], IT[1][i*2+1]);
}

int minV,maxV;

void get(int i, int l, int r, int s, int f){
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        minV=min(minV,IT[0][i]);
        maxV=max(maxV,IT[1][i]);
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
}

void queryU(int X, int V){
    a[X]=V;
    update(1,1,n,X);
}

void queryQ(int X, int C){
    if(C<0){
        puts("-1 -1");
        return;
    }
    int Vmin = a[X]-C, Vmax = a[X]+C;
    int l=X+1, r=n, mid, res=X;
    while(l<=r){
        mid=(l+r)/2;
        minV=oo; maxV=-oo;
        get(1,1,n,X,mid);
        if(Vmin<=minV && maxV<=Vmax){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    minV=oo; maxV=-oo;
    get(1,1,n,X,res);
    int res2 = max(maxV - a[X], a[X] - minV);
    printf("%d %d\n",res-X+1,res2);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    init(1,1,n);
    char s[10];
    int x,y;
    for(int i=0; i<m; ++i){
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='U') queryU(x,y);
        else queryQ(x,y);
    }
}

