#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=1111111;

bool isPrime[maxv+1];
int nextPrime[maxv+1],prevPrime[maxv+1];
ll dp[555][555];
int a[555],n;

ll cost(int v1, int v2){

    int x=nextPrime[v2];
    int y=prevPrime[x-1];
    if(y>=v1) return (y-v1) + (x-v2);
    else{
        y=nextPrime[v1];
        x=nextPrime[y+1];
        return (y-v1)+(x-v2);
    }
    return oo;
}

ll get(int l, int r){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll &res = dp[l][r];
    res = oo;

    for(int i=l+1; i<r; i+=2) res=min(res, get(l,i) + get(i+1,r));

    res = min(res, cost(a[l],a[r]) + get(l+1,r-1) + 1);

    return res;
}

int main(){
//    freopen("input.txt","r",stdin);

    isPrime[2]=1;
    for(int i=3; i<=maxv; i+=2) isPrime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isPrime[i])
        for(int j=i*i; j<=maxv; j+=i*2) isPrime[j]=0;
    int last=maxv+1;
    for(int i=maxv; i>=1; --i){
        if(isPrime[i]) last=i;
        nextPrime[i] = last;
    }
    int first=0;
    for(int i=1; i<=maxv; ++i){
        if(isPrime[i]) first=i;
        prevPrime[i] = first;
    }

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    reset(dp,-1);
    cout<<get(1,n)<<endl;

}

