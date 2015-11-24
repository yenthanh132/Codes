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

const int maxn=207;

int f[maxn][maxn*maxn][2],a,b,n,h[maxn],s[maxn];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>a>>b;
    s[0]=0;
    FOR(i,1,n) cin>>h[i], s[i]=s[i-1]+h[i];
    FOR(i,1,n) FOR(v,0,a) REP(x,2) f[i][v][x]=oo;
    if(a>=h[1]) f[1][h[1]][0]=0;
    if(b>=h[1]) f[1][0][1]=0;
    FOR(i,1,n-1) FOR(va,0,a) REP(x,2) if(f[i][va][x]<oo){
        int ua=a-va, ub=b-(s[i]-va);
        if(ua>=h[i+1]) f[i+1][va+h[i+1]][0] = min(f[i+1][va+h[i+1]][0], f[i][va][x] + min(h[i],h[i+1])*(x!=0));
        if(ub>=h[i+1]) f[i+1][va][1] = min(f[i+1][va][1], f[i][va][x] + min(h[i],h[i+1])*(x!=1));        
    }
    int res=oo;
    FOR(v,0,a) REP(x,2) res=min(res,f[n][v][x]);
    if(res==oo) res=-1;
    cout<<res<<endl;
    
    return 0;
}
