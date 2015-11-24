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

int n,k;
int a[maxn],b[maxn], BIT[maxn];

ll fac[maxn];
ll fac2[maxn];

void update(int i, int v){
    for( ; i<=n; i+=i&(-i)) BIT[i]+=v;
}

int get(int i){
    int r=0;
    for( ; i; i-=i&(-i)) r+=BIT[i];
    return r;
}

ll getIndex(int *a){
    for(int i=1; i<=n; ++i) BIT[i]=0;
    ll res=0;
    for(int i=1; i<=n; ++i){
        int c=(a[i]-1) - get(a[i]-1);
        res = (res + fac[n-i]*c)%oo;
        update(a[i],1);
    }
    return res;
}

ll getIndex2(int *a, int &type){
    for(int i=1; i<=n; ++i) BIT[i]=0;
    ll res=0;
    int needSwap=0;
    for(int i=1; i<=n-2; ++i){
        int c=(a[i]-1) - get(a[i]-1);
        res = (res + fac2[n-i]*c);
        if(c&1) needSwap ^= 1;
        update(a[i],1);
    }
    type = (needSwap == (a[n-1]>a[n]));
    return res;
}

int main(){

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    fac[0]=1;
    for(int i=1; i<=100000; ++i) fac[i]=fac[i-1]*i%oo;
    fac2[0]=1;
    for(int i=1; i<=100000; ++i){
        fac2[i]=fac2[i-1];
        if(i>2) fac2[i]=fac2[i]*i%oo;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
        if(k==n){
            int i=1, j=1;
            while(b[j]!=a[i]) ++j;
            bool ok=1;
            for(int r=0; r<n; ++r){
                if(a[i]!=b[j]){
                    ok=0;
                    break;
                }
                ++i; ++j;
                if(i>n) i=1;
                if(j>n) j=1;
            }

            if(ok) printf("%d\n",b[1]);
            else puts("-1");

        }else{
            if(k&1){
                int type1,type2;
                ll idx1 = getIndex2(a,type1);
                ll idx2 = getIndex2(b,type2);
                idx2 = (idx2 + 1)%oo;
                if(type1==type2) printf("%lld\n",idx2);
                else puts("-1");
            }else{
                ll idx2 = getIndex(b);
                idx2 = (idx2 + 1)%oo;
                printf("%lld\n",idx2);
            }

        }
    }
}
