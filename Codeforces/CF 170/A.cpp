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

const int maxn=107;

bool mark[maxn];
int n,m;
vector<int> a[maxn];

void dfs(int u){
    mark[u]=0;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(mark[v]) dfs(v);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int res=0,res2=0;
    cin>>n>>m;
    reset(mark,0);
    int u,v,vt;
    FOR(i,1,n){
        cin>>u;
        if(u==0) res++;
        vt=-1;
        REP(ii,u){
            cin>>v;
            mark[v]=1;
            if(vt!=-1){
                a[vt].pb(v);
                a[v].pb(vt);
            }
            vt=v;
        }
    }
    
    FOR(i,1,m) if(mark[i]){
        res2++;
        dfs(i);
    }
    cout<<res+max(res2-1,0)<<endl;
    return 0;
}

