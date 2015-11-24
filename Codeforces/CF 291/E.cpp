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

int c[maxn],n,x;

typedef vector< vector<ll> > Matrix;

Matrix create(int m, int n){
    return vector< vector<ll> > (m, vector<ll> (n,0));
}

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c = create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%oo;
    return c;
}

Matrix mypow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t=mypow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&x);
    for(int i=1,v; i<=n; ++i) scanf("%d",&v), ++c[v];
    Matrix f=create(101,1);
    f[0][0]=1; f[100][0]=1;
    if(x>0){
        Matrix base=create(101,101);
        for(int j=0; j<100; ++j) base[0][j]=c[j+1];
        base[0][100]=1;
        for(int i=1; i<100; ++i) base[i][i-1]=1;
        base[100][100]=1;
        base=mypow(base,x);
        f=mul(base,f);
    }
    cout<<f[0][0]<<endl;
}

