
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

const int maxn=100007;


int a[maxn],b[maxn],n,m,R[maxn],L[maxn];
int f[maxn],g[maxn];


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,m) scanf("%d",&b[i]);
    sort(b+1,b+m+1);

    int cnt=0;
    for(int i=1; i<=n;){
        int j=i;
        while(j+1<=n && a[j+1]==a[j]+1) ++j;
        R[j]=j;
        FORD(x,j-1,i) R[x]=R[x+1];
        L[i]=i;
        FOR(x,i+1,j) L[x]=L[x-1];
        i=j+1;
    }

    int p=0;
    FOR(x,1,n){
        f[x]=max(f[x],g[x-1]);
        if(R[x]==x){
            while(p+1<=m && b[p+1]<=a[x]) ++p;
            FORD(y,p,1){
                int need=a[x]-b[y];
                int cost=p-y+1;
                int left=x-need-1;
                if(need>x-1) break;
                f[x]=max(f[x],g[L[left]]+cost);
            }
            FOR(y,p+1,m){
                int need=b[y]-a[x];
                int cost=y-p;
                if(x+need>n) break;
                g[R[x+need]]=max(g[R[x+need]],f[x]+cost);
            }
        }
        g[x]=max(g[x],g[x-1]);
        g[x]=max(g[x],f[x]);
    }
    int res=0;
    FOR(x,1,n) res=max(res,max(f[x],g[x]));
    cout<<res<<endl;
    return 0;
}
