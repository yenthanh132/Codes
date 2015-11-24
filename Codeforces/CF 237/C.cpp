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

int n,k,deg[maxn];
pii d[maxn];
vector<pii> list;
vector<int> val;
stack<int> sd[maxn];


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&d[i].fi), val.pb(d[i].fi), d[i].se=i;
    sort(val.begin(),val.end());
    val.resize(unique(val.begin(),val.end())-val.begin());
    if(val[0]!=0) goto not_found;
    REP(i,sz(val)-1) if(val[i]+1!=val[i+1]) goto not_found;
    reset(deg,0);
    sort(d+1,d+n+1);
    FOR(i,1,n) sd[d[i].fi].push(i);
    FOR(i,2,n){
        if(d[i].fi==0) goto not_found;
        int dis=d[i].fi;
        int v=d[i].se;
        while(1){
            if(sd[dis-1].empty()) goto not_found;  
            int t=sd[dis-1].top();         
            int u=d[t].se; 
            sd[dis-1].pop();
            if(deg[u]>=k) continue;
            list.pb(pii(u,v));
            ++deg[u]; ++deg[v];
            if(deg[v]>k) goto not_found;
            if(deg[u]<k) sd[dis-1].push(t);
            break;
        }        
    }
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d %d\n",list[i].fi,list[i].se);

    return 0;    
    not_found:
        puts("-1");
        return 0;
}
