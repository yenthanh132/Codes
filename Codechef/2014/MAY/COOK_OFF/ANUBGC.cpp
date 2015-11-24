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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[20],m;
ll n,f[20][2][2];

ll gcd(ll a,ll b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);   
}

struct frac{
    ll num,den;
    frac(){
        num=0; den=1;   
    }
    frac(ll a, ll b){
        num=a, den=b;   
    }
    void reduce(){
        ll t=gcd(num,den);
        num/=t; den/=t;   
    }
    frac operator +(frac x){
        frac res;
        res.den = den/gcd(den,x.den)*x.den;
        res.num = num*(res.den/den) + x.num*(res.den/x.den);
        res.reduce();
        return res;
    }
    
};

ll get(int i, int smaller, int has, int v){
    if(i==0) return 1;
    if(f[i][smaller][has]!=-1) return f[i][smaller][has];
    ll &res=f[i][smaller][has];
    res=0;
    int top = 9;
    if(!smaller) top=a[i];
    int bot = 0;
    if(i==1 && !has) bot=1;
    FOR(x,bot,top) 
        if( x!=v || (x==0 && !has) ) 
            res+=get(i-1,smaller | (x<a[i]), has | (x>0), v);
    return res;
}

void solve(ll n){
    ll N=n;
    m=0;
    while(n){
        a[++m]=n%10;
        n/=10;   
    }
    frac res;
    REP(v,10){
        reset(f,-1);
        ll ans = get(m,0,0,v);
        frac tmp(N-ans,N);
        res=res+tmp;
    }
    res.den*=10;
    res.reduce();
    cout<<res.num<<"/"<<res.den<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    REP(tt,t){
        cin>>n;
        solve(n);
    }   
}
