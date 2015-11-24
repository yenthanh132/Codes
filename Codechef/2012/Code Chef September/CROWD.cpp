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

struct matrix{ll arr[3][3]; int m,n;} base,mul,res;

ll N,ans;
int T;

matrix operator *(const matrix &a, const matrix &b){
    matrix c;
    c.m=a.m; c.n=b.n;
    REP(i,c.m) REP(j,c.n){
        c.arr[i][j]=0;
        REP(k,a.n) c.arr[i][j]=(c.arr[i][j]+a.arr[i][k]*b.arr[k][j])%oo;
    }
    return c;
}

matrix pw(const matrix &base, ll N){
    if(N==1) return base;
    matrix t=pw(base,N/2);
    t=t*t;
    if(N&1) return t*base; else return t;
}

int pw(const int &base, ll N){
    if(N==1) return base;
    ll t=pw(base,N/2); t=(t*t)%oo;
    if(N&1) return (t*base)%oo; else return t;
}

int main(){
    scanf("%d",&T);
    base.m=base.n=3;
    base.arr[0][0]=1; base.arr[0][1]=1; base.arr[0][2]=1;
    base.arr[1][0]=1; base.arr[1][1]=0; base.arr[1][2]=0;
    base.arr[2][0]=0; base.arr[2][1]=1; base.arr[2][2]=0;
    mul.m=3; mul.n=1;
    mul.arr[0][0]=1;
    mul.arr[1][0]=1;
    mul.arr[2][0]=0;
    
    REP(index,T){
        scanf("%lld",&N);
        if(N<=2) printf("%d\n",0);
        else{
            res=pw(base,N-1);
            res=res*mul;
            ans=0; REP(i,3) ans=(ans+res.arr[i][0])%oo;
            ans=(pw(2,N)+oo-ans)%oo;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
            
        
