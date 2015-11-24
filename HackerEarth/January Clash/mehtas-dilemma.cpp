#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

typedef vector< vector<ll> > Matrix;

Matrix create(int m, int n){
    return vector< vector<ll> >(m, vector<ll>(n, 0));
}

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c=create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k)
            c[i][j] = (c[i][j] + a[i][k]*b[k][j])%oo;
    return c;
}

Matrix mypow(Matrix base, ll n){
    if(n==1) return base;
    Matrix t=mypow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

const int val[10]={0,0,1,2,0,4,3,8,1,0};

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    ll N;
    cin>>T;
    while(T--){
        cin>>N;
        ll res1 = ( 9*(mypow(10,N)-1)%oo *mypow(10-1,oo-2)%oo - (mypow(9,N+1)-1)*mypow(9-1,oo-2)%oo + oo*2 + 1 ) %oo;
        ll res2;

        Matrix x = create(17,17);
        for(int mask=0; mask < (1<<4); ++mask){
            for(int num=1; num<10; ++num)
                x[val[num] ^ mask][mask]++;
        }
        x[16][0]=1; x[16][16]=1;
        Matrix rx = create(16,1);
        rx[0][0]=1;
        rx = mul(mypow(x,N),rx);
        res2 = rx[0][0] + rx[16][0];

        cout<<(res1+res2)%oo<<endl;
    }
}

