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

struct matrix{int a[3][3],m,n;} base,mul,res;


matrix operator *(const matrix &a, const matrix &b){
    matrix c;
    c.m=a.m; c.n=b.n;
    REP(i,c.m) REP(j,c.n){
        c.a[i][j]=0;
        REP(k,a.n) c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%oo;
    }
    return c;
}

matrix pw(const matrix &base, int n){
    if(n==1) return base;
    matrix t=pw(base,n/2);
    t=t*t;
    if(n&1) return t*base; else return t;
}

int pw(const int &a, int n){
    if(n==1) return a;
    int t=pw(a,n/2);
    t=(1ll*t*t)%oo;
    if(n&1) return (1ll*t*a)%oo; else return t;
}

int cal(int n){
    int ans=0;
    if(n%2==0){
        ans=pw(2,n/2);
        n--;
    }
    if(n==1) return (ans+2)%oo;
    res=pw(base,n/2);
    res=res*mul;
    return (ans+1ll*res.a[2][0]*2)%oo;
}
    

int main(){
    base.m=base.n=3;
    base.a[0][0]=1; base.a[0][1]=1; base.a[0][2]=0;
    base.a[1][0]=1; base.a[1][1]=1; base.a[1][2]=0;
    base.a[2][0]=1; base.a[2][1]=1; base.a[2][2]=1;
    
    mul.m=3; mul.n=1;
    mul.a[0][0]=1; mul.a[1][0]=1; mul.a[2][0]=1;
    
    int t,n,a,b;
    cin>>t;
    REP(i,t){
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}
