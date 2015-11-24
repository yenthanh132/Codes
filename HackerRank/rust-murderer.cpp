#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

set<pii> se;
set<int> nodes;
int n,T,m;
int d[maxn],myq[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        se.clear();
        for(int i=0; i<m; ++i){
            int u,v;
            scanf("%d%d",&u,&v);
            se.insert(pii(u,v)); se.insert(pii(v,u));
        }

        int s;
        scanf("%d",&s);
        nodes.clear();
        for(int i=1; i<=n; ++i) if(i!=s) nodes.insert(i);
        d[s]=0;
        int first=1,last=1; myq[1]=s;
        while(first<=last){
            int u=myq[first++];
            vector<int> dels;
            for(set<int>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
                int v=*it;
                if(!se.count(pii(u,v))){
                    d[v]=d[u]+1;
                    dels.pb(v);
                    myq[++last]=v;
                }
            }
            for(int i=0; i<sz(dels); ++i) nodes.erase(dels[i]);
        }

        for(int i=1; i<=n; ++i) if(d[i]) printf("%d ",d[i]); puts("");
    }
}

