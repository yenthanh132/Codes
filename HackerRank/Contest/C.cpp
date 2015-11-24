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

int n,T,IT[maxn*4],deg[maxn];
vector<int> a[maxn];
ll ans;

void update(int i, int l, int r, int p, int v){
    if(p<l || p>r) return;
    if(l==r){
        IT[i]+=v;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p,v); update(i*2+1,mid+1,r,p,v);
    IT[i]=IT[i*2]+IT[i*2+1];
}

int resIT;
void get(int i, int l, int r, int s, int f){
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        resIT+=IT[i];
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
}

void dfs(int u){
    update(1,1,n,u,1);
    int s=max(u-T,1), f=min(u+T,n);
    resIT=0;
    get(1,1,n,s,f);
    ans+=resIT-1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        dfs(v);
    }
    update(1,1,n,u,-1);
}

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&T);
    int u,v;
    reset(deg,0);
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        deg[v]++;
        a[u].pb(v);
    }
    ans=0;
    int start;
    FOR(i,1,n) if(deg[i]==0){
        start=i;
        break;
    }
    dfs(start);
    
    cout<<ans<<endl;
    return 0;
}
    
    
    
