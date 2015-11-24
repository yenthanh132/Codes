#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1073741824

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector< vector<ll> > Matrix;

int a1,a2,b1,b2,c1,c2,d1,d2,n,k;

Matrix createMatrix(int m, int n){
    return vector< vector<ll> >(m, vector<ll>(n, 0));
}

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c=createMatrix(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j){
        for(int k=0; k<n; ++k)
            c[i][j] = (c[i][j] +a[i][k]*b[k][j])%oo;
    }
    return c;
}

Matrix matPow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t = matPow(base, n/2);
    t = mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

int getA(int n){
    if(n==1) return a1;
    if(n==2) return a2;
    Matrix mat = createMatrix(3,3);
    mat[0][1] = 1;
    mat[1][2] = 1;
    mat[2][0] = b1; mat[2][1] = b2;
    Matrix mul = matPow(mat, n-2);
    return (mul[2][0]*a1 + mul[2][1]*a2)%oo;
}

int getB(int n){
    if(n==1) return c1;
    if(n==2) return c2;
    Matrix mat = createMatrix(3,3);
    mat[0][1] = 1;
    mat[1][2] = 1;
    mat[2][0] = d1; mat[2][1] = d2;
    Matrix mul = matPow(mat, n-2);
    return (mul[2][0]*c1 + mul[2][1]*c2)%oo;
}

int getV(int i, int j){
    ++i; ++j;
    return getA(i) | getB(j);
}

ll cal(int x, int y){
    ll sum=0;
    for(int i=0; i<k; ++i) for(int j=0; j<k; ++j) sum+=getV(x+i,y+j);
    return sum;
}

//Random function
double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>k;
    cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
//    for(int i=1; i<=n; ++i){
//        for(int j=1; j<=n; ++j) cout<<getV(i-1,j-1)<<' '; cout<<endl;
//    }
    if(k>100){
        puts("0 0");
        return 0;
    }
    srand(time(NULL));
    ll best=cal(0,0);
    int rx=0, ry=0;
    for(int r=0; r<1000/k/k; ++r){
        int x=randi(n-k+1), y=randi(n-k+1);
        ll val=cal(x,y);
        if(val>best){
            best=val;
            rx=x; ry=y;
        }
    }
    cout<<rx<<' '<<ry<<endl;
}


