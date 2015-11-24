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

const int maxn=1007;
struct GraphInversions {
    bool mark[maxn];
    vector<int> e[maxn], V;
    int n,k,bit[maxn],res;

    void update(int p, int v){
        for(;p;p-=p&(-p)) bit[p]+=v;
    }

    int get(int p){
        int r=0;
        for(;p<=1000;p+=p&(-p)) r+=bit[p];
        return r;
    }

    void dfs(int u, int dep, int sum){

        sum+=get(V[u]+1);
        if(dep==k){
            res=min(res,sum);
            return;
        }

        mark[u]=1;
        update(V[u],1);

        int v;
        REP(i,sz(e[u])){
            v=e[u][i];
            if(mark[v]) continue;
            dfs(v,dep+1,sum);
        }

        mark[u]=0;
        update(V[u],-1);
    }

	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> _V, int K) {
        V=_V;
        k=K;
        n=sz(A);
        REP(i,n){
            int u=A[i], v=B[i];
            e[u].pb(v); e[v].pb(u);
        }
        res=oo;
        reset(mark,0); reset(bit,0);
        REP(i,n) dfs(i,1,0);
        if(res==oo) res=-1;
        return res;
	}
};
