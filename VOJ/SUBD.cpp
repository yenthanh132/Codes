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
void readNumber(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}



//Bignum-----------------
typedef vector<long long> bignum;
const ll BASE = 100000000ll;
const int NUMLEN = 8;

bignum int2bignum(ll v){
    bignum c;
    while(v){
        c.pb(v%BASE);
        v/=BASE;
    }
    if(c.empty()) c.pb(0);
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

bignum operator+(bignum a, ll v){
    REP(i,sz(a)){
        a[i]=a[i]+v;
        v=a[i]/BASE;
        a[i]%=BASE;
        if(v==0) break;
    }
    while(v){
        a.pb(v%BASE);
        v/=BASE;
    }
    return a;
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
    while(t){
        c.pb(t%BASE);
        t/=BASE;
    }
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

bignum operator*(bignum &a, ll b){
    bignum c;
    ll t=0;
    REP(i,sz(a)){
        t+=a[i]*b;
        c.pb(t%BASE);
        t=t/BASE;
    }
    while(t){
        c.pb(t%BASE);
        t/=BASE;
    }
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

//-----------------------------------------            

const int maxn=300007;
const double eps=1e-12;

struct node{ll t,a,i;} list[maxn],total_list[maxn];
vector<int> stt[maxn];
int n,m[maxn];
bignum res,tsum;


bool cmp(const node &x, const node &y){
    return (x.t*y.a<y.t*x.a || (x.t*y.a==y.t*x.a && x.i<y.i));
}

bool cmp2(const node &x, const node &y){
    double v1=1.0*x.t/x.a, v2=1.0*y.t/y.a;
    return (v1+eps<v2 || (fabs(v1-v2)<eps && x.i<y.i));
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    readNumber(n);
    res=int2bignum(0);
    FOR(i,1,n){
        readNumber(m[i]);
        total_list[i].t=total_list[i].a=0;
        FOR(j,1,m[i]){
            list[j].i=j;
            readNumber(list[j].t);
            total_list[i].t+=list[j].t;
        }
        FOR(j,1,m[i]){
            readNumber(list[j].a);
            total_list[i].a+=list[j].a;
        }
        sort(list+1,list+m[i]+1,cmp);
        ll tsum2=0;
        
        FOR(j,1,m[i]){
            tsum2=tsum2+list[j].t;
            res=res+tsum2*list[j].a;
            stt[i].pb(list[j].i);
        }
        total_list[i].i=i;
    }
    sort(total_list+1,total_list+n+1,cmp2);
    tsum=int2bignum(0);
    FOR(i,1,n){
        res=res+tsum*total_list[i].a;
        tsum=tsum+total_list[i].t;
    }
    printf("%s\n",bignum2str(res).c_str());
    int id;
    FOR(i,1,n){
        id=total_list[i].i;
        printf("%d\n",id);
        REP(j,sz(stt[id])){
            if(j) putchar(' ');
            printf("%d",stt[id][j]);
        }
        puts("");
    }
    return 0;
}
        
        
