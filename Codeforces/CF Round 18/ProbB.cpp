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

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b>a) return gcd(b,a,y,x);
    else if(b==0){
        x=1; y=0;
        return a;
    }else{
        ll x2,y2;
        ll v=gcd(b,a%b,x2,y2);
        x=y2; y=x2-(a/b)*y2;
        return v;
    }
}

ll nghichdao(ll a, ll m){
    ll x,y;
    gcd(a,m,x,y); 
    return x;
}

ll find(ll a, ll b, ll mod){
    ll v,x,y;
    v=gcd(a,mod,x,y);
    if(b%v!=0) return -1;   
    b/=v; a/=v; mod/=v;
    v=(b*nghichdao(a,mod))%mod;
    while(v<0) v+=mod;
    return v;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    ll n,d,m,l,k;
    ll res,t;
    cin>>n>>d>>m>>l;
    t=ll(m)*n-m+l; res=(t/d)*d; while(res<=t) res+=d;
    FOR(i,l+1,m-1){
        ll v=find(d,i,m); 
        if(v!=-1 && v*d<res) res=v*d;
    }
    cout<<res;
    //getch();
    return 0;
}
