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

const ll BASE=1000000000000000ll;
const int DIGIT=15;
const int LENGTH=670;

struct bignum{
    int n;
    ll a[LENGTH];
};

bignum tobignum(ll v){
    bignum ans; ans.n=0;
    while(v){
        ans.a[++ans.n]=v%BASE;
        v/=BASE;
    }
    return ans;
}

bignum operator*(bignum a, ll v){
    bignum ans; ans.n=a.n;
    ll t=0;
    FOR(i,1,a.n){
        ans.a[i]=v*a.a[i]+t;
        t=ans.a[i]/BASE;
        ans.a[i]%=BASE;
    }
    while(t) ans.a[++ans.n]=t%BASE, t/=BASE;
    return ans;
}

bignum operator+(bignum a, bignum b){
    bignum ans;
    ll t=0;
    FOR(i,1,max(a.n,b.n)){
        if(i>b.n) b.a[i]=0; 
        if(i>a.n) a.a[i]=0;
        ans.a[i]=a.a[i]+b.a[i]+t;
        t=ans.a[i]/BASE;
        ans.a[i]%=BASE;
    }
    ans.n=max(a.n,b.n);
    while(t) ans.a[++ans.n]=t%BASE, t/=BASE;
    return ans;
}

string tostr(ll i){
    stringstream ss;
    ss<<i;
    return ss.str();
}

string tostr(bignum a){
    string s="",st;
    s=tostr(a.a[a.n]);
    FORD(i,a.n-1,1){
        st=tostr(a.a[i]);
        while(sz(st)<DIGIT) st='0'+st;
        s=s+st;
    }
    return s;
}
    
bignum f[10001][2];
//#include <conio.h>
int main(){
    
    int n,k;
    cin>>n>>k; 
    if(n==1) printf("%d\n",k);
    else{
        f[1][0]=tobignum(0);
        f[1][1]=tobignum(k-1);
        FOR(i,2,n){
            f[i][0]=f[i-1][1];
            f[i][1]=(f[i-1][0] + f[i-1][1])*(k-1);
        }
        printf("%s\n",tostr(f[n][0]+f[n][1]).c_str());
    }
    //getch();
    return 0;
    
}
    
    
