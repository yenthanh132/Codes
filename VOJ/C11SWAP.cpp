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

const int maxn = 107;

int n,p[maxn],pos[maxn],a[maxn], dp[maxn][maxn];
ll gt[maxn];

ll mpow(ll &v, int n){
    if(n==1) return v;
    ll t=mpow(v,n/2); t=(t*t)%oo;
    if(n&1) return (t*v)%oo; else return t;
}
    
int tron(int v1, int v2){
    ll v=(gt[v1+v2]*mpow(gt[v1],oo-2))%oo;
    return (v*mpow(gt[v2],oo-2))%oo;
}

int mcount(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];
    FOR(i,l,r) if(pos[a[i]]<l || pos[a[i]]>r) return 0;
    if(l==r) return 1;
    ll res=0,v1,v2;
    FOR(i,l,r-1){
        swap(a[i],a[i+1]);
        v1=mcount(l,i); if(v1) v2=mcount(i+1,r);
        v1=(v1*v2)%oo;
        res=(res+v1*tron(i-l,r-i-1))%oo;
        swap(a[i],a[i+1]);
    }
    dp[l][r]=res%oo;
    return dp[l][r];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    gt[0]=1; FOR(i,1,100) gt[i]=(gt[i-1]*i)%oo;
    cin>>n;
    REP(i,n) cin>>p[i], pos[p[i]]=i;
    REP(i,n) a[i]=i;
    REP(i,n) REP(j,n) dp[i][j]=-1;
    cout<<mcount(0,n-1)<<endl;
    //getch();
    return 0;
}
    
