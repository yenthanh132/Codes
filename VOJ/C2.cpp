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

int compare(const bignum &a,const bignum &b){
    if(sz(a)<sz(b)) return -1;
    if(sz(a)>sz(b)) return 1;
    REPD(i,sz(a)) if(a[i]<b[i]) return -1; else if(a[i]>b[i]) return 1;
    return 0;
}

bignum operator+(bignum &a, bignum &b){
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
            
//------------------------------------

bool cmp(const bignum &a, const bignum &b){
    return compare(a,b)==-1;
}

const int maxn=50000;

bignum list[maxn];
int n,len,d[10];

void update(string s){
    string t=s;
    int v=0;
    REPD(i,len) t+=s[i];
    REP(i,sz(t)) if(t[i]=='1') v++; else if(t[i]=='2') v+=4;
    if(v<10) list[++n]=str2bignum(t);
    t=s;
    v=0;
    REPD(i,len-1) t+=s[i];
    REP(i,sz(t)) if(t[i]=='1') v++; else if(t[i]=='2') v+=4;
    if(v<10) list[++n]=str2bignum(t);
}

void duyet(int i){
    string res="";
    REP(z,len) res+='0';
    FOR(j,1,i-1) res[d[j]-1]='1';
    update(res);
    FOR(j,1,i-1){
        if(j>1) res[d[j-1]-1]='1';
        res[d[j]-1]='2';
        update(res);
    }
    
    if(i>5) return;
    FOR(v,d[i-1]+1,len){
        d[i]=v;
        duyet(i+1);
    }
}

void init(){
    n=1;
    list[1]=int2bignum(3);
    FOR(i,1,25){
        len=i;
        d[1]=1;
        duyet(2);    
    }
}

int T;
bignum a,b,v;
string s1,s2;

#include <conio.h>
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    init();
    sort(list+1,list+n+1,cmp);
    cin>>T;
    int l,r,mid,p1,p2,res;
    FOR(tt,1,T){
        cin>>s1>>s2;
        a=str2bignum(s1);
        b=str2bignum(s2);
        l=1; r=n; p1=n+1;
        while(l<=r){
            mid=(l+r)>>1;
            v=list[mid]*list[mid];
            if(compare(a,v)>=0){
                p1=mid;
                r=mid-1;
            }
        }
        l=1; r=n; p2=0;
        while(l<=r){
            mid=(l+r)>>1;
            v=list[mid]*list[mid];
            if(compare(v,b)<=0){
                p2=mid;
                l=mid+1;
            }
        }
        if(p1<=p2) res=p2-p1+1; else res=0;
        printf("Case #%d: %d\n",tt,res);
    }
    //getch();
    return 0;
    
}
