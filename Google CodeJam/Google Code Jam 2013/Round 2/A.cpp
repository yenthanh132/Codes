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
const int BASE = 10000;
const int NUMLEN = 4;

bignum int2bignum(ll v){
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

bignum operator-(bignum a, bignum b){
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

bignum operator*(bignum a, bignum b){
    bignum c=int2bignum(0),d;
    REPD(i,sz(a)){
        d=b*a[i];
        c=c*BASE;
        c=c+d;
    }
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

//---------------------------------------------

const int maxn=2007;

struct edge{
    int x,y,p;
}a[maxn];

int n,m,T;
ll res,sum;

bool cmp(const edge &a, const edge &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

multiset<pii> mys;

bignum cal(ll len){
    ll v=len, v2=len-1;
    if(v&1){
        v2/=2;
    }else v/=2;
    return int2bignum(v)*int2bignum(v2);
}

int main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d%d",&n,&m);
        int l,r,p;
        bignum res=int2bignum(0),sum=int2bignum(0);
        FOR(i,1,m){
            scanf("%d%d%d",&l,&r,&p);
            a[i].x=l; a[i].y=0; a[i].p=p;
            a[i+m].x=r; a[i+m].y=1; a[i+m].p=p;
            sum=sum+cal(r-l)*int2bignum(p);
        }
        sort(a+1,a+m*2+1,cmp);
        mys.clear();
        pii node;
        FOR(i,1,m*2)
            if(a[i].y==0){
                mys.insert(pii(-a[i].x,a[i].p));
            }else{
                while(a[i].p>0){
                    node=*mys.begin();
                    mys.erase(mys.begin());
                    int v=min(node.se, a[i].p);
                    res=res+cal(a[i].x + node.fi)*int2bignum(v);
                    node.se -= v;
                    a[i].p -= v;
                    if(node.se > 0) mys.insert(node);
                }
            }
        bignum ans=res-sum;
        printf("Case #%d: %s\n",tt,bignum2str(ans).c_str());
    }

    return 0;
}
