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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 500007;
int m,n,T,d[maxn],deg[maxn];
ll res;
vector<int> a[maxn],listp;
vector<pii> S,M;

vector<pii> phantich(int n){
    vector<pii> ans;
    int c;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            c=0;
            while(n%i==0) c++, n/=i; 
            ans.pb(pii(i,c));
        }
    }
    if(n>1) ans.pb(pii(n,1));
    return ans;
}
    
bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int sn=int(sqrt(n)),k=0;
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k-1<=sn);
    return(k-1>sn);
}

void init(){
    FOR(i,2,maxn) if(isprime(i)) listp.pb(i);
}

int myqueue[maxn];

void build(){
    int first=1, last=0;
    FOR(i,1,n) if(deg[i]==0)
        myqueue[++last]=i;
    int u,v;
    while(first<=last){
        u=myqueue[first++];
        REP(i,sz(a[u])){
            v=a[u][i];
            d[v]+=d[u];
            deg[v]--;
            if(deg[v]==0) myqueue[++last]=v;
        }
    }
}

int mpow(int v, int n){    
    if(n==1) return v;
    ll t=mpow(v,n/2);
    if(n&1) return(((t*t)%m)*v)%m; else return (t*t)%m;
}

void euclid(int a, int b, int&x, int&y){
    if(a<b) euclid(b,a,y,x);
    else if(b==0) x=1, y=0;
    else{
        int x2,y2;
        euclid(b,a%b,x2,y2);
        x=y2; y=x2-(a/b)*y2;
    }
}

int nghichdao(int v){
    int x,y;
    euclid(v,m,x,y);
    return int(x);
}
    
void solve(){
    S.clear();
    M=phantich(m);
    ll v;
    int j=0;
    REP(i,sz(M)) M[i].se=0;
    REP(i,sz(listp)){
        if(listp[i]>=n) break;
        while(j<sz(M) && M[j].fi<listp[i]) j++;
        if(j<sz(M) && M[j].fi==listp[i]){
            v=M[j].fi; 
            while(n-1>=v){
                M[j].se+=(n-1)/v;
                v=v*M[j].fi;
            }
        }else{
            v=listp[i];
            S.pb(pii(v,0));
            while(n-1>=v){
                S.back().se+=(n-1)/v;
                v=v*listp[i];
            }
        }
    }
    res=1;
    int t;
    FOR(i,2,n) if(d[i]>1){
        t=d[i];
        REP(j,sz(M))
            while(t%M[j].fi==0){
                t/=M[j].fi;
                M[j].se--;
            }
        if(t>1) res=(res*nghichdao(t))%m;
    }
    REP(i,sz(M)) if(M[i].se) res=(res*mpow(M[i].fi,M[i].se))%m;
    REP(i,sz(S)) if(S[i].se) res=(res*mpow(S[i].fi,S[i].se))%m;
    if(res<0){
        t=-res;
        res+=((t-1)/m+1)*m;
    }
}
  
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&T);
    int v;
    init();
    REP(index,T){
        scanf("%d%d",&m,&n);
        FOR(i,1,n) a[i].clear();
        fill(deg+1,deg+n+1,0); fill(d+1,d+n+1,1);
        FOR(i,2,n){
            scanf("%d",&v);
            a[i].pb(v);
            deg[v]++;
        }
        build();
        solve();
        printf("%d\n",res);
    }
    cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    getch();
    return 0;
}

