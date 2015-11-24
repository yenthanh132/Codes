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
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector< vector<ll> > Matrix;

Matrix gen(int m, int n){
    return Matrix(m, vector<ll>(n,0));
}

Matrix operator * (Matrix a, Matrix b){
    int m = sz(a), n = sz(b), p = sz(b[0]);
    Matrix c = gen(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j])%oo;
    return c;
}

Matrix mypow(Matrix &base, ll n){
    if(n==1) return base;
    Matrix t = mypow(base,n/2);
    t=t*t;
    if(n&1) return t*base;
    return t;
}

ll cal(ll n){
    Matrix base = gen(3,1);
    base[0][0]=base[2][0]=1;
    Matrix mul = gen(3,3);
    mul[0][2]=mul[1][0]=mul[2][1]=mul[2][2]=1;
    mul = mypow(mul,n-1);
    base = mul * base;
    ll res = 0;
    for(int i=0; i<3; ++i) res = (res + base[i][0])%oo;
    return res;
}

int main(){
    int T;
    ll n;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%lld",&n);
        printf("%lld\n",cal(n));
    }
}
