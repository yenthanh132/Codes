#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;
const int maxv=1000000;

bool isprime[maxn];
int cnt,n,a[maxn],bit[maxn],T,q;
char buf[10];

void update(int i, int v){
    for(;i<=n; i+=i&(-i)) bit[i]+=v;
}

int get(int i){
    int r=0;
    for(;i; i-=i&(-i)) r+=bit[i];
    return r;
}

bool check(int v){
    if(v<=maxv) return isprime[v];
    if(v==2 || v==3) return 1;
    if(v<2 || v%2==0 || v%3==0) return 0;
    int k=0;
    int sn=int(sqrt(v));
    do{
        k+=6;
        if(v%(k-1)==0 || v%(k+1)==0) return 0;
    }while(k-1<=sn);
    return k-1>sn;
}

int main(){
//    freopen("input.txt","r",stdin);
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) bit[i]=0;
        for(int i=1; i<=n; ++i){
            scanf("%d",&a[i]);
            if(check(a[i])) update(i,1);
        }
        scanf("%d",&q);
        int x,y;
        for(int i=0; i<q; ++i){
            scanf("%s%d%d",buf,&x,&y);
            if(buf[0]=='C'){
                if(check(a[x])) update(x,-1);
                if(check(y)) update(x,1);
                a[x]=y;
            }else{
                printf("%d\n",get(y)-get(x-1));
            }
        }
    }
}

