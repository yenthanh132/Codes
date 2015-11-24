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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int n;
ll val[maxn],res,sum;
ll size[maxn];
vector<int> a[maxn];
bool getall=0;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);   
}

ll lcm(ll a, ll b){
    ll v=a/gcd(a,b);
    return v*b;
}

void dfs(int u, int p){ 
    if(getall) return; 
    int v,cnt=0;
    ll minv=oo;
    size[u]=1;

    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        cnt++;
        dfs(v,u);
        if(getall) return;
        minv=min(minv,val[v]);
        size[u]=lcm(size[u],size[v]);
        if(size[u]>sum) getall=1;
    }
    if(cnt==0){
        return;
    }    
    minv-=minv%size[u];
    
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        res+=val[v]-minv;
    }
    val[u]=minv*cnt;    
    size[u]*=cnt;
    if(size[u]>sum) getall=1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    res=sum=0;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%I64d",&val[i]), sum+=val[i];;
    int u,v;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
    }
    
    getall=0;
    dfs(1,-1);
    if(!getall) cout<<res<<endl;
    else cout<<sum<<endl;
    //getch();
    return 0;
}
