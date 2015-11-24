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

vector<int> e[maxn];
int n,m,val[maxn],lab[maxn];
vector<pii> list;
bool mark[maxn];
ll total;

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d",&val[i]);
        list.pb(pii(val[i],i));
    }
    sort(list.begin(),list.end(),greater<pii>());
    int x,y;
    REP(i,m){
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }


    total=0;
    reset(mark,0);
    FOR(u,1,n) lab[u]=-1;
    REP(i,n){
        int u=list[i].se, v;
        int sum=0;
        ll tmp=0;
        REP(j,sz(e[u])){
            v=e[u][j];
            if(!mark[v]) continue;
            int r1=getroot(u), r2=getroot(v);
            if(r1==r2) continue;
            tmp+=1ll*(-lab[r2])*sum;
            if(mark[v]) sum-=lab[r2];
            dsu(r1,r2);
        }
        mark[u]=1;
        total+=1ll*val[u]*(sum+tmp);

    }

    printf("%0.9lf\n",2.0*total/n/(n-1));
    return 0;
}
