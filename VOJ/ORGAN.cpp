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

//Bignum-----------------
typedef vector<long long> bignum;
const int BASE = 1000000000;
const int NUMLEN = 9;

bignum int2bignum(int v){
    bignum c(1,v);
    return c;
}

bignum str2bignum(string s){
    bignum c;
    while(s.length()>NUMLEN){
        c.pb(atoi(s.substr(s.length()-NUMLEN,NUMLEN).c_str()));
        s.erase(s.length()-NUMLEN,NUMLEN);
    }
    c.pb(atoi(s.c_str()));
    return c;
}

string bignum2str(bignum a){
    string s="",st;
    REP(i,sz(a)){
        stringstream ss;
        ss<<a[i]; st=ss.str();
        if(i<sz(a)-1) while(st.length()<NUMLEN) st="0"+st;
        s=st+s;
    }
    return s;
}

int compare(bignum &a, bignum b){
    if(sz(a)<sz(b)) return -1;
    if(sz(a)>sz(b)) return 1;
    REPD(i,sz(a)) if(a[i]<b[i]) return -1; else if(a[i]>b[i]) return 1;
    return 0;
}

bignum operator+(bignum a, bignum b){
    bignum c;
    ll t=0;
    while(sz(a)<sz(b)) a.pb(0);
    while(sz(a)>sz(b)) b.pb(0);
    REP(i,max(sz(a),sz(b))){
        t+=a[i]+b[i];
        c.pb(t%BASE);
        t/=BASE;
    }
    if(t>0) c.pb(t);
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

bignum operator*(bignum &a, int b){
    bignum c;
    ll t=0;
    REP(i,sz(a)){
        t+=a[i]*b;
        c.pb(t%BASE);
        t=t/BASE;
    }
    if(t>0) c.pb(t);
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

//----------------------------------------

const int maxn=207;
bignum dp[maxn][maxn],val[maxn];
int n,s,w,a[maxn];
ll m,bmin,bmax;

int init(){
    FOR(i,1,n) FOR(j,0,w) dp[i][j]=int2bignum(0);
    dp[1][0]=int2bignum(1);
    FOR(i,2,n) FOR(j,0,min(i-1,w))
        dp[i][j]=dp[i-1][j]*(j+1) + dp[i-1][j-1]*(i-j);
    FOR(i,1,n){
        val[i]=int2bignum(0);
        FOR(j,0,min(i-1,w)) val[i]=val[i]+dp[i][j];
    }
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d%d%lld%lld%lld",&n,&s,&w,&m,&bmin,&bmax);
        init();
        a[0]=0;
        FOR(i,1,n) scanf("%d",&a[i]), a[i]+=a[i-1];
        FOR(i,0,n) FOR(j,0,s) dp[i][j]=int2bignum(0);
        
        FOR(i,1,n) FOR(j,1,min(i,s))
            FOR(z,j-1,i-1)
                if((a[i]-a[z])*m>=bmin && (a[i]-a[z])*m<=bmax
                    && compare(dp[i][j],dp[z][j-1]+val[i-z])==-1)
                        dp[i][j]=dp[z][j-1]+val[i-z];
                    
        puts(bignum2str(dp[n][s]).c_str());
    }
    getch();
    return 0;
}
