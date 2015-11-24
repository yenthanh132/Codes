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
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

typedef vector< vector<ll> > Matrix;

Matrix create(int m, int n){
    return vector< vector<ll> > (m, vector<ll> (n,0) );
}

Matrix mul( Matrix a, Matrix b ){
    int m=sz(a), n=sz(b), p = sz(b[0]);
    Matrix c = create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j){
        for(int k=0; k<n; ++k)
            c[i][j]=(c[i][j] + a[i][k]*b[k][j])%oo;
    }
    return c;
}

Matrix mypow(Matrix base, ll n){
    if(n==1) return base;
    Matrix t=mypow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

int val(int x){
    if(x==2) return 1;
    if(x==3) return 2;
    if(x==5) return 4;
    if(x==7) return 8;
    return 0;
}

int main(){
//    freopen("input.txt","r",stdin);
    int t,a,b,c,d;
    ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d%d%d%d",&n,&a,&b,&c,&d);
        int v=0;
        if(a) v+=1;
        if(b) v+=2;
        if(c) v+=4;
        if(d) v+=8;
        Matrix base=create(17,17);
        for(int i=0; i<16; ++i){
            for(int x=0; x<10; ++x){
                base[val(x)^i][i]++;
                if((val(x)^i)==v && x!=0) base[16][i]++;
            }
        }
        Matrix res=create(17,1);
        res[0][0]=1;
        base[16][16]++;
        res=mul(mypow(base,n),res);
        if(v==0) ++res[16][0];
        cout<<res[16][0]<<endl;
    }
}

