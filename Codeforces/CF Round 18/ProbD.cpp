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

int compare(bignum &a, bignum &b){
    if(sz(a)<sz(b)) return -1;
    if(sz(a)>sz(b)) return 1;
    REPD(i,sz(a)) if(a[i]<b[i]) return -1; else if(a[i]>b[i]) return 1;
    return 0;
}

bignum operator+(bignum &a, bignum b){
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

bignum operator-(bignum &a, bignum &b){
    bignum c;
    ll t=0;
    while(sz(a)<sz(b)) a.pb(0);
    while(sz(a)>sz(b)) b.pb(0);
    REP(i,max(sz(a),sz(b))){
        t+=a[i]-b[i];
        if(t>=0) c.pb(t), t=0; else c.pb(t+BASE),t=-1;
    }
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

bignum operator*(bignum a, int b){
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

bignum operator*(bignum &a, bignum &b){
    bignum c=int2bignum(0),d;
    REPD(i,sz(a)){
        d=b*a[i];
        c=c*BASE;
        c=c+d;
    }
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}
//---------------------------------------

bignum pow(int n){
    if(n==0) return int2bignum(1);
    if(n==1) return int2bignum(2);
    bignum t=pow(n/2);
    if(n&1) return (t*t)*2; else return t*t;
}

const int maxn  = 5007;

int n, a[maxn], win[maxn];
bignum f[maxn];
map<int,int> pos;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    string st;
    int v;
    FOR(i,1,n){
        cin>>st>>v;
        a[i]=v;
        win[i]=(st[0]=='w');
    }
    f[0]=int2bignum(0);
    bignum t;
    FOR(i,1,n){
        f[i]=f[i-1];
        if(win[i]) pos[a[i]]=i;
        else if(pos[a[i]]!=0){
            v=pos[a[i]];
            t=f[v]+pow(a[v]);
            if(compare(t,f[i])==1) f[i]=t;
        }
    }
    puts(bignum2str(f[n]).c_str());
    //getch();
    return 0;
}
            
            
        
