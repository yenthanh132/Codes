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
typedef pair<ll, int> pii;

const int maxn=200007;

ll a[maxn];
int n;

vector<pii> list;
int go(int x){
    list.clear();
    FOR(j,x,n){
        if(a[j]!=-1) list.pb(pii(a[j],j));
        if(sz(list)==2) break;   
    }
    if(sz(list)<2) return n+1;   
    if((list[1].fi-list[0].fi)%(list[1].se-list[0].se)!=0) return list[1].se;
    ll d=(list[1].fi-list[0].fi)/(list[1].se-list[0].se);
    int p1=list[0].se, p2=list[1].se;
    ll v1=list[0].fi, v2=list[1].fi;
    
    if(v1-d*(p1-x)<=0) return p2;
    FOR(j,p2,n){
        if( v2<=0 || (a[j]!=-1 && a[j]!=v2)) return j;
        v2+=d;
    }
    return n+1;
}

int main(){
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    FOR(i,1,n) cin>>a[i];
    
    int res=0;
    int x=1;
    while(x<=n){
        ++res;
        x=go(x);   
    }
    
    cout<<res<<endl;
}
    
