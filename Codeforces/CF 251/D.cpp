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

const int maxn=222222;

int a[maxn],b[maxn],m,n,c[maxn*2],cnt;
ll sa[maxn],sb[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    cnt=0;
    FOR(i,1,m) scanf("%d",&a[i]), c[++cnt]=a[i];
    FOR(i,1,n) scanf("%d",&b[i]), c[++cnt]=b[i];
    sort(a+1,a+m+1); sort(b+1,b+n+1); sort(c+1,c+cnt+1);
    cnt=unique(c+1,c+cnt+1)-c-1;
    sa[0]=sb[0]=0;
    FOR(i,1,m) sa[i]=sa[i-1]+a[i];
    FOR(i,1,n) sb[i]=sb[i-1]+b[i];
    ll res=-1;
    int pa=m, pb=n;
    FORD(i,cnt,1){
        int v=c[i];
        while(pa>0 && a[pa]>v) --pa;
        while(pb>0 && b[pb]>v) --pb;
        ll val=( 1ll*v*pa-sa[pa] ) + ( sb[n]-sb[pb] - 1ll*v*(n-pb) );
        if(res==-1 || res>val) res=val;
        //cout<<1ll*v*pa-sa[pa]<<'+'<<( sb[n]-sb[pb] - 1ll*v*(n-pb) )<<endl;
        //cout<<v<<' '<<pa<<' '<<pb<<' '<<val<<endl;
    }
    cout<<res<<endl;
}

