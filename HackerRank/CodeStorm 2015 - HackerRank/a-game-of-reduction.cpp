#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=1000000;
int g[maxv+1];
int p10[9];

int countDigit(int v){
    if(v==0) return 1;
    int res=0;
    while(v){
        ++res;
        v/=10;
    }
    return res;
}

int getNum(int n, int x){
    int top=n/p10[x];
    int mid=n%p10[x];
    int bot=mid%p10[x-2];
    mid/=p10[x-2];
    int res = top*p10[x-1]+bot+((mid%10 + mid/10)%10)*p10[x-2];
    return res;
}

int mark[111],idx;

void gen(){
    reset(mark,0);
    idx=0;
    for(int i=10; i<=maxv; ++i){
        int c=countDigit(i);
        ++idx;
        for(int x=c; x>=2; --x) mark[g[getNum(i,x)]]=idx;
        g[i]=0;
        while(mark[g[i]]==idx) ++g[i];
    }
}

int cnt[maxv+1][4];
int n,m;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll getVal(int c, int b){
    if(c==0) return (b==0);
    ll x=mypow(2,c-1);
    return x;
}

int main(){
//    freopen("input.txt","r",stdin);

    p10[0]=1;
    for(int i=1; i<=9; ++i) p10[i]=p10[i-1]*10;
    gen();

    for(int i=1; i<=maxv; ++i){
        for(int j=0; j<=3; ++j) cnt[i][j]=cnt[i-1][j];
        ++cnt[i][g[i]];
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int cur=0;
        int cc[4];
        for(int j=0; j<=3; ++j) cc[j]=cnt[n][j];
        for(int i=0; i<m; ++i){
            int v;
            scanf("%d",&v);
            cur^=g[v];
            --cc[g[v]];
        }
        ll res = mypow(2,cc[0]);
//        for(int i=0; i<=3; ++i) cout<<cc[i]<<' '; cout<<endl;


        ll res2 = 0;
        for(int b1=0; b1<=1; ++b1) for(int b2=0; b2<=1; ++b2) for(int b3=0; b3<=1; ++b3){
            ll v1,v2,v3;
            v1=getVal(cc[1],b1);
            v2=getVal(cc[2],b2);
            v3=getVal(cc[3],b3);
            int x1=b1*1;
            int x2=b2*2;
            int x3=b3*3;

            if((x1^x2^x3^cur)==0){
                res2 = (res2 + v1*v2%oo*v3)%oo;
            }
        }

        res = (res*res2)%oo;
        if(cur==0) res=(res-1+oo)%oo;
        printf("%lld\n",res);
    }
}

