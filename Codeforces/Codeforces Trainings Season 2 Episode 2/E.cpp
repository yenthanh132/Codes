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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;

vector<pii> e[maxn];
int n,m,A,k,d[maxn],mark[maxn];
set<pii> mys;
bool free1[maxn];
bool live[maxn];


int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&A,&k),n>0){
        for(int u=1; u<=n; ++u) e[u].clear();
        int u,v,w;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&u,&v,&w);
            e[u].pb(pii(v,w));
            e[v].pb(pii(u,w));
        }

        for(int i=1; i<=n; ++i) d[i]=oo;
        int res=n;
        reset(mark,0); reset(live,1);
        set<pii>::iterator it;
        for(int i=1; i<=A; ++i){
            scanf("%d",&v);
            mys.clear();
            if(d[v]>0){
                d[v]=0;
                mys.insert(pii(0,v));
            }
            while(!mys.empty()){
                u=mys.begin()->second;
                if(live[u]){
                    live[u]=0;
                    --res;
                }
                mys.erase(mys.begin());
                mark[u]=i;
                for(int j=0; j<sz(e[u]); ++j){
                    v=e[u][j].first;
                    if(mark[v]==i) continue;
                    w=e[u][j].second;
                    if(d[v]>d[u]+w && d[u]+w<k){
                        it=mys.find(pii(d[v],v));
                        if(it!=mys.end()) mys.erase(it);
                        d[v]=d[u]+w;
                        mys.insert(pii(d[v],v));
                    }
                }
            }
            printf("%d\n",res);
        }
        puts("");
    }
    return 0;
}
