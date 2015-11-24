#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll mpow(int base, int n){
    if(n==0) return 1;
    ll t=mpow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

typedef vector< vector<ll> > Matrix;

Matrix createMatrix(int m, int n){
    return vector< vector<ll> > (m, vector<ll> (n, 0));
}

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c=createMatrix(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j){
        for(int k=0; k<n; ++k)
            c[i][j]+=a[i][k]*b[k][j];
        c[i][j]%=oo;
    }
    return c;
}

Matrix mpow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t=mpow(base, n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

ll getWays(int n){
    if(n<=1) return 1;
    if(n==2) return 6;
    Matrix m1 = createMatrix(3,1);
    m1[0][0]=1; //id
    m1[1][0]=2; //sum
    m1[2][0]=1; //value one
    Matrix m2 = createMatrix(3,3);
    m2[0][0] = 1; m2[0][1] = 0; m2[0][2] = 1;
    m2[1][0] = 1; m2[1][1] = 3; m2[1][2] = 1;
    m2[2][0] = 0; m2[2][1] = 0; m2[2][2] = 1;

    m2 = mpow(m2, n-2);
    m1 = mul(m2,m1);
    ll res = (m1[0][0]+m1[1][0]*2+m1[2][0])%oo;
    return res;
}

ll getWays2(int n){
    if(n<=1) return 1;
    ll res = (mpow(3,n-2)*13-1+oo)%oo * mpow(2,oo-2)%oo;
    return res;
}

map<ll,int> save;
ll solve(int n){
    if(save.count(n)) return save[n];
    ll r1=mpow(2,n-1);
    ll r2=getWays2(n);
    ll res=(r2-r1+oo)%oo;
    save[n]=res;
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",solve(n));
    }
}

