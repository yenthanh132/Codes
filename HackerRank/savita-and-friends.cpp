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
#define oo 1000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=200007;

vector<pii> e[maxn];
ll d[2][maxn];
int A,B,LEN,k,n,m,T;
set<pli> mys;
bool free1[maxn];

void dijkstra(int s, ll *d){
    for(int u=1; u<=n; ++u){
        d[u]=oo;
        free1[u]=1;
    }
    d[s]=0;
    mys.clear(); mys.insert(pli(0,s));
    while(!mys.empty()){
        int u=mys.begin()->second;
        mys.erase(mys.begin());
        free1[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first;
            if(free1[v] && d[v]>d[u]+e[u][i].second){
                if(d[v]!=oo) mys.erase(pli(d[v],v));
                d[v]=d[u]+e[u][i].second;
                mys.insert(pli(d[v],v));
            }
        }
    }
}

long double Alist[maxn],Blist[maxn];
int cnt[maxn], idA[maxn], idB[maxn];
long double pMin;
int per1[maxn],per2[maxn];

bool cmp1(const int &a, const int &b){
    return d[0][a]>d[0][b];
}

bool cmp2(const int &a, const int &b){
    return d[1][a]<d[1][b];
}

bool check(long double len){
    int cA=0, cB=0, cur=0;
    for(int i=1; i<=n; ++i){
        int u=per1[i];
        cnt[u]=0;
        if(len-d[0][u] >= 0){
            Alist[++cA]=len-d[0][u];
            idA[cA] = u;
            cnt[u]=1;
            ++cur;
        }
        u=per2[i];
        if(len - d[1][u] >= 0){
            Blist[++cB]=LEN-len+d[1][u];

            idB[cB] = u;
        }
    }
    if(cur==n){
        pMin = 0;
        return 1;
    }
    int j=1;
    for(int i=1; i<=cB; ++i){
        while(j<=cA && Alist[j] + 1e-9 < Blist[i]){
            if(--cnt[idA[j]] == 0) --cur;
            ++j;
        }
        if(++cnt[idB[i]]==1) ++cur;
        if(cur==n){
            pMin = Blist[i];
            return 1;
        }
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    cout.precision(5);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d%d",&n,&m,&k);
        int u,v,w;
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int i=1; i<=m; ++i){
            scanf("%d%d%d",&u,&v,&w);
            e[u].pb(pii(v,w));
            e[v].pb(pii(u,w));
            if(i==k) A=u, B=v, LEN=w;
        }
        dijkstra(A,d[0]);
        dijkstra(B,d[1]);
        for(int i=1; i<=n; ++i) per1[i]=per2[i]=i;
        sort(per1+1,per1+n+1,cmp1);
        sort(per2+1,per2+n+1,cmp2);
        long double l=0, r=1e14, mid;
        while(r-l>1e-5){
            mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
        long double res=(l+r)/2;
        check(res);
        cout<<fixed<<pMin<<' '<<res<<endl;
    }
    return 0;
}
