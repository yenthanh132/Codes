#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

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


const int maxn=5007;

bignum f[2][maxn];
int ds[2][maxn];
int cnt[2];
int a[maxn];
int n,m,r;

bignum sum[maxn];

void calc(int flag){
    sum[0]=int2bignum(0);
    for(int i=1; i<=cnt[1^flag]; ++i) sum[i]=sum[i-1]+f[1^flag][i];
    int j=1;
    for(int i=1; i<=cnt[flag]; ++i){
        while(j<=cnt[1^flag] && ds[flag][i] - ds[1^flag][j] > m) ++j;
        f[flag][i]=sum[cnt[1^flag]]-sum[j-1];
    }
}

int main(){
    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; ++i) scanf("%d",&a[i]);
        cnt[0]=1; ds[0][1]=a[0];
        for(int i=0; i<2; ++i) for(int j=0; j<=n; ++j) f[i][j]=int2bignum(0);
        f[0][1]=int2bignum(1);
        scanf("%d",&r);
        int x,y,flag=0;
        for(int i=0; i<r; ++i){
            flag^=1;
            cnt[flag]=0;
            scanf("%d%d",&x,&y);
            for(int j=x; j<=y; ++j) ds[flag][++cnt[flag]]=a[j];
            calc(flag);
        }
        flag^=1;
        cnt[flag]=1; ds[flag][1]=a[n-1];
        calc(flag);
        cout<<bignum2str(f[flag][1])<<endl;
        if(T>=1) cout<<endl;
    }

    return 0;
}

