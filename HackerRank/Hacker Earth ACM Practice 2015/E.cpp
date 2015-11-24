#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int n,T[maxn],m,k,d[maxn],myq[maxn];
vector<pii> e[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    for(int i=1; i<=m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(pii(v,i));
        e[v].pb(pii(u,i));
    }

    reset(T,63);
    for(int i=1; i<=k; ++i){
        scanf("%d%d",&u,&v);
        T[v]=u;
    }

    reset(d,-1);
    d[1]=0; myq[1]=1;
    int first=1,last=1;
    while(first<=last){
        int u=myq[first++];
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first, limit=T[e[u][i].second];
            if(d[v]==-1 && d[u]<limit){
                d[v]=d[u]+1;
                myq[++last]=v;
            }
        }
    }
    printf("%d\n",d[n]);
}

