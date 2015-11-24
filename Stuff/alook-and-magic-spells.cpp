#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

typedef vector< vector<ll> > Matrix;

Matrix identity;

Matrix create(int m, int n){
    return vector< vector<ll> > (m, vector<ll> (n,0) );
}

Matrix operator * (Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c=create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k)
            c[i][j] = (c[i][j] + a[i][k]*b[k][j])%oo;
    return c;
}

Matrix matPow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t=matPow(base,n/2);
    t=t*t;
    if(n&1) return t*base;
    return t;
}


ll calc(int n){
    if(n==0) return 1;
    if(n==1) return 3;
    Matrix res = create(3,1);
    res[0][0]=1;
    res[1][0]=2;
    res[2][0]=3;
    if(n>=2){
        Matrix base = create(3,3);
        base[0][0]=0; base[0][1]=1; base[0][2]=0;
        base[1][0]=4; base[1][1]=2; base[1][2]=0;
        base[2][0]=4; base[2][1]=2; base[2][2]=1;
        res = matPow(base,n-1)*res;
    }
//    for(int x=0; x<3; ++x) cout<<res[x][0]<<endl; cout<<endl;
    return res[2][0];
}

int main(){
//    freopen("input.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    for(int i=0; i<T; ++i){
        scanf("%d",&n);
        ll res = calc(n) %oo;
        if(n>=2) res = (res + calc(n-2)*4)%oo;
        res = (res - 1 + oo)%oo;
        printf("%lld\n",res);
    }
}

