
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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


const int maxn=10007;
int a[maxn],n,T,q;
ll s[maxn],x,spow[101][101];

//========================================
//log check
inline ll mul(ll a, ll b){
    if((a*b)/b==a) return a*b;
    return -1;
}

ll mypow(ll base, int n){
    if(n==1) return base;
    if(base<=100 && n<=100) return spow[base][n];
    ll t=mypow(base,n/2);
    if(t==-1 || (t*t)/t!=t) return -1;
    t=t*t;
    if(n&1) return mul(t,base);
    return t;
}

ll root(int i, ll x){
    if(i==1) return x;
    double t=pow(x,1.0/i);
    ll r=ll(floor(t));
    ll k=mypow(r+1,i);
    if(k!=-1 && k<=x) ++r;
    return r;
}

//====================================================

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    //init;
    FOR(i,1,100){
        spow[i][0]=1;
        FOR(j,1,100)
            if(spow[i][j-1]!=-1) spow[i][j]=mul(spow[i][j-1],i);
            else spow[i][j]=-1;
    }

    read(T);
    REP(tt,T){
        read(n); read(q);
        FOR(i,1,n) read(a[i]);
        s[n]=a[n]%oo;
        FORD(i,n-1,1) s[i]=(s[i+1]+a[i])%oo;

        REP(i,q){
            read(x);
            if(i) printf(" ");
            ll res=0;
            ll v=x;
            FOR(j,1,n){
                v=root(j,x);
                if(v>1){
                    res=(res+(v%oo)*a[j])%oo;
                }else{
                    res=(res+s[j])%oo;
                    break;
                }
            }
            res=(res+oo)%oo;
            printf("%lld",res);
        }
        puts("");
    }
    return 0;
}

