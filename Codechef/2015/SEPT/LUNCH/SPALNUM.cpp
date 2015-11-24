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

ll sum[maxn];

bool check(int v){
    if(v<10) return 1;
    vector<int> a;
    while(v){
        a.pb(v%10);
        v/=10;
    }
    for(int i=0; i<sz(a)/2; ++i) if(a[i]!=a[sz(a)-i-1]) return 0;
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    sum[0]=0;
    for(int i=1; i<=100000; ++i){
        sum[i]=sum[i-1];
        if(check(i)) sum[i]+=i;
    }

    int T,l,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&r);
        printf("%lld\n",sum[r]-sum[l-1]);
    }
}

