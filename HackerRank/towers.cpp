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

Matrix create(int m, int n){
    return vector< vector<ll> > (m, vector<ll>(n, 0) );
}

Matrix operator * ( Matrix &a, Matrix &b){
    int x = sz(a), y = sz(a[0]), z = sz(b[0]);
    Matrix c = create(x,z);
    for(int i=0; i<x; ++i) for(int j=0; j<z; ++j)
        for(int k=0; k<y; ++k)
            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) %oo;
    return c;
}

Matrix mypow(Matrix &base, ll n){
    if(n==0){
        Matrix identity = create(sz(base), sz(base[0]));
        for(int i=0; i<sz(identity); ++i) identity[i][i]=1;
        return identity;
    }
    Matrix t = mypow(base,n/2);
    t=t*t;
    if(n&1) return t*base;
    return t;
}

int main(){
    //freopen("input.txt","r",stdin);

    ll n;
    cin>>n;

    Matrix X = create(15,15);
    for(int i=0; i<14; ++i) X[i][i+1]=1;

    int m,v;
    cin>>m;
    for(int i=0; i<m; ++i){
        cin>>v;
        X[14][15-v] = 1;
    }

    Matrix res = create(15,1);
    res[14][0] = 1;
    X = mypow(X, n);

    res = X * res;
    cout<<res[14][0] * 2 % oo<<endl;

    return 0;
}
