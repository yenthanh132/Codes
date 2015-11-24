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

int n,d[maxn],k,p,cnt[maxn],m;
vector<int> a[maxn];
ll s1[maxn],s2[maxn];

void dfs(int u, int dep){
    d[u]=dep;
    cnt[dep]++;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(d[v]==-1) dfs(v,dep+1);   
    }   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    int u,v;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    
    reset(cnt,0); reset(d,-1);
    dfs(1,0);
    int m=1;
    while(cnt[m+1]) ++m;
    
    
    //solve
    ll res=0;
    s1[0]=s2[0]=0;
    FOR(j,1,m){
        s1[j]=s1[j-1]+cnt[j];
        s2[j]=s2[j-1]+1ll*j*cnt[j];
    }
    
    FOR(j,1,m){
        int l=1, r=j-1, mid, i=j;    
        while(l<=r){
            mid=(l+r)/2;
            if( j * (s1[j-1] - s1[mid-1]) - (s2[j-1] - s2[mid-1]) <= p ){
                i=mid;
                r=mid-1;
            }else l=mid+1;
        }
        int left = p - ( j*(s1[j-1]-s1[i-1]) - (s2[j-1] - s2[i-1]));
        int plus = 0;
        if(i>1) plus = left/(j-(i-1));
        res=max(res,plus + s1[j]-s1[i-1]);
    }
    
    res=min(res,1ll*k);
    
    printf("%I64d\n",res);
    
    return 0;
}
