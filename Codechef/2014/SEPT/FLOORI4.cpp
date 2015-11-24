#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll mypow(ll base, ll n, ll &M){
    if(n==0) return 1;
    ll t=mypow(base,n/2,M);
    t=t*t%M;
    if(n&1) return t*base%M;
    return t;
}

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

void refine(ll &a, ll &b){
    if(b==1) return;
    ll d=gcd(a,b);
    if(d>1) a/=d, b/=d;
}


//Matrix calculation for n > 10^6
typedef vector< vector<ll> > Matrix;

Matrix identityMatrix, baseMatrix;

Matrix create(int m, int n){
    return vector< vector<ll> >(m, vector<ll>(n, 0));
}

Matrix mul(Matrix a, Matrix b, ll &M){
    int x = sz(a), y = sz(b), z = sz(b[0]);
    Matrix c = create(x,z);
    for(int i=0; i<x; ++i) for(int j=0; j<z; ++j)
        for(int k=0; k<y; ++k)
            c[i][j] = (c[i][j] + a[i][k] * b[k][j])%M;
    return c;
}

Matrix mypow(ll n, ll &M){
    if(n==0) return identityMatrix;
    Matrix t = mypow(n/2,M);
    t=mul(t,t,M);
    if(n&1) return mul(t,baseMatrix,M);
    return t;
}

void initMatrix(){
    identityMatrix = create(6,6);
    for(int i=0; i<6; ++i) identityMatrix[i][i]=1;

    baseMatrix = create(6,6);
    baseMatrix[0][0]=1;
    for(int i=1; i<=4; ++i){
        baseMatrix[i][0]=1;
        for(int j=1; j<=i; ++j) baseMatrix[i][j]=baseMatrix[i-1][j-1]+baseMatrix[i-1][j];
    }
    for(int j=0; j<=4; ++j) baseMatrix[5][j]=baseMatrix[4][j];
    baseMatrix[5][5]=1;
}

//=====================================
ll f(ll n, ll M){ //sum( i^4 , i<=n) mod M
    ll res;
    if(n<=1000000000){
        ll A = n, B = n+1, C=2*n+1, D = 3*n*n+3*n-1;
        ll den=30;
        refine(A,den); refine(B,den); refine(C,den); refine(D,den);
        A%=M; B%=M; C%=M; D%=M;
        res = A * B * C%M * D%M;
    }else{
        Matrix y = create(6,1);
        for(int i=0; i<=5; ++i) y[i][0]=1;
        if(n>1){
            Matrix x = mypow(n-1,M);
            y = mul(x,y,M);
        }
        res = y[5][0];
    }
    return res;
}

ll cal(ll l, ll r, ll M){
    return (f(r,M)-f(l-1,M)+M)%M;
}

int T;
ll N,M;

int main(){
    //freopen("input.txt","r",stdin);
    initMatrix();

    scanf("%d",&T);

    for(int tt=0; tt<T; ++tt){
        scanf("%lld%lld",&N,&M);
        ll i;
        ll res = 0;
        for(i=1; i*i<=N; ++i){
            res = ( res + mypow(i,4,M) * (N/i) )%M;
        }
        ll prev_sum = f(i-1,M), cur_sum;
        for(ll rbound; i<=N; i=rbound+1){
            ll v=N/i;
            rbound = N/v;
            cur_sum = f(rbound,M);
            res = (res + (cur_sum - prev_sum + M)*v)%M;
            prev_sum = cur_sum;
        }
        printf("%lld\n",res);
    }
}
