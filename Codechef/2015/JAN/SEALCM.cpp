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

Matrix create(int m, int n){
    return vector< vector<ll> > (m, vector<ll> (n, 0) );
}

Matrix mul( Matrix a, Matrix b ){
    int m = sz(a), n = sz(b), p = sz(b[0]);
    Matrix c = create(m, p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k)
            c[i][j] = ( c[i][j] + a[i][k]*b[k][j] ) %oo;
    return c;
}

Matrix mypow( Matrix base, int n){
    if(n==1) return base;
    Matrix t = mypow(base, n/2);
    t = mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

int T,L,R,M,N;
int len, box;
vector<int> p;

ll cal( int v ){
    p.clear();
    for(int i=2; i*i<=v; ++i) if(v%i==0){
        int x = 1;
        while(v%i==0){
            x*=i;
            v/=i;
        }
        p.pb(x);
    }
    if(v>1) p.pb(v);
    len=sz(p); box = 1<<len;
    Matrix base = create(box, 1);
    base[0][0]=1;
    Matrix xMat = create(box, box);
    for(int x = 1; x <= M; ++x){
        int bit = 0;
        for(int i=0; i<len; ++i) if(x%p[i]==0) bit |= 1<<i;
        for(int mask = 0; mask < box; ++mask)
            xMat[mask|bit][mask]++;
    }
    Matrix ret = mul(mypow(xMat, N), base);
    return ret[box-1][0];
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    for(int tt=0; tt<T; ++tt){
        cin>>N>>M>>L>>R;
        ll res =  0;
        for(int x = L; x<=R; ++x) res = (res + cal(x))%oo;
        cout<<res<<endl;
    }
}

