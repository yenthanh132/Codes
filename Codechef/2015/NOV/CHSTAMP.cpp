#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef long long ll;

const int maxn=200007;
const int maxv=50000;

int mark[maxn],n,m,a[maxn];
vector<iii> e[maxn];
priority_queue<iii> myq;
bool check[maxn];
int hasPop[maxn],idx;

void dijkstra(int r){
    while(!myq.empty()) myq.pop();
    myq.push(iii(oo,pii(r,-1)));
    ++idx;
    while(!myq.empty()){
        iii p=myq.top(); myq.pop();
        int u=p.second.first, t=p.first, id=p.second.second;
        if(hasPop[u]==idx) continue;
        hasPop[u]=idx;
        mark[u]=max(mark[u],r);
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first, t2=e[u][i].second.first, id2=e[u][i].second.second;
            if(!check[id2] && t2 <= t){
                myq.push(iii(t2,pii(v, id2)));
                check[id2] = 1;
            }
        }
    }
}

int tt;
int markValue[maxn];

int main(){
//    freopen("input.txt","r",stdin);

    idx=0;
    reset(hasPop,0);

    int T;
    scanf("%d",&T);
    tt=0;
    while(T--){
        ++tt;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=maxv; ++i) e[i].clear();
        for(int i=1; i<=maxv; ++i) mark[i]=i;
        for(int i=0; i<m*2; ++i) check[i]=0;

        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for(int i=0; i<m; ++i){
            int t,a,b;
            scanf("%d%d%d",&t,&a,&b);
            e[a].pb(iii(b,pii(t,i*2)));
            e[b].pb(iii(a,pii(t,i*2+1)));
            markValue[a]=markValue[b]=tt;
        }

        for(int i=maxv; i>=1; --i) if(markValue[i]) dijkstra(i);
        ll res=0;
        for(int i=1; i<=n; ++i) res += mark[a[i]];
        printf("%lld\n",res);
    }
}
