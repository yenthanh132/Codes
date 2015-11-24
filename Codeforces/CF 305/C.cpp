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
const int maxv=500000;

int isprime[maxv+7];
int plist[maxn],cnt;

int n,a[maxn],mark[maxn],total,q,val[maxv+7];
vector<int> frac[maxv+7];

int get(int v){
    int c=sz(frac[v]);
    int res=0;
    for(int mask=1; mask<(1<<c); ++mask){
        int sum=1,cbit=0;
        for(int i=0; i<c; ++i) if(mask>>i&1){
            sum*=frac[v][i];
            ++cbit;
        }
        if(cbit&1) res+=val[sum];
        else res-=val[sum];
    }
    return res;
}

void update(int v, int sign){
    int c=sz(frac[v]);
    for(int mask=0; mask<(1<<c); ++mask){
        int sum=1;
        for(int i=0; i<c; ++i) if(mask>>i&1)
            sum*=frac[v][i];
        val[sum] += sign;
    }
}

int main(){
//    freopen("input.txt","r",stdin);

    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i] = 1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j] = 0;

    plist[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) plist[++cnt]=i;

    for(int v=1; v<=maxv; ++v){
        int t=v;
        for(int i=1; plist[i]*plist[i]<=t; ++i) if(t%plist[i]==0){
            int f=plist[i];
            frac[v].pb(f);
            while(t%f==0) t/=f;
        }
        if(t>1) frac[v].pb(t);


    }
    cnt = 0;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    ll res = 0;
    total = 0;
    for(int i=0; i<q; ++i){
        int x; scanf("%d",&x);

        if(!mark[x]){

            res += total - get(a[x]);
            ++total;
            mark[x] = 1;
            update(a[x], 1);
        }else{
            update(a[x],-1);
            --total;
            res -= total - get(a[x]);
            mark[x] = 0;
        }

        printf("%I64d\n",res);
    }
}

