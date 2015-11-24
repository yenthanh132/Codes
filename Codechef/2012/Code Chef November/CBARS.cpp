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

struct matrix{
    int m,n,arr[64][64];
};

matrix operator *(matrix &a, matrix &b){
    matrix c;
    c.m=a.m; c.n=b.n;
    REP(i,c.m) REP(j,c.n){
        c.arr[i][j]=0;
        REP(k,a.n) c.arr[i][j]=(c.arr[i][j]+1ll*a.arr[i][k]*b.arr[k][j])%oo;
    }
    return c;
}

ll w,l;
matrix base,mul;

bool check(int v1,int v2){
    int v[6]; reset(v,0);
    REP(j,w) v[j]=((v1>>j)&1) + ((v2>>j)&1);
    REP(j,w-1) if((v[j]==2 && v[j+1]==2) || (v[j]==0 && v[j+1]==0)) return 0;
    return 1;
}

matrix mpow(ll n){
    if(n==1) return base;
    matrix t=mpow(n/2);
    t=t*t;
    if(n&1) return t*base; else return t;
}

//#include <conio.h>
int main(){
    cin>>w>>l;
    if(l==1){
        cout<<(1<<w)<<endl;
        return 0;
    }
    base.m=base.n=(1<<w);
    REP(i,base.m) REP(j,base.n) base.arr[i][j]=check(i,j);
    mul.m=1<<w; mul.n=1;
    REP(i,mul.m) mul.arr[i][0]=1;
    
    matrix res=mpow(l-1);
    res=res*mul;
    
    ll ans=0;
    REP(j,res.m) ans=(ans+res.arr[j][0])%oo;
    cout<<ans<<endl;
    //getch();
    return 0;
}
        
    
