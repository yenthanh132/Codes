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

const int maxn=50007;

vector<pii> a[maxn];
int n,m;
bool mark[maxn];

void DFS(int u, int &d){
    mark[u]=1;
    if(mark[n]) return;
    int v;
    REP(i,sz(a[u])) if(a[u][i].se<=d){   
        v=a[u][i].fi;
        if(!mark[v]) DFS(v,d);
    }
}

bool check(int d){
    FOR(i,1,n) mark[i]=0;
    DFS(1,d);
    return mark[n];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int l=0, r=0, mid, res=oo;
    int u,v,c;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&c);
        a[u].pb(pii(v,c));
        a[v].pb(pii(u,c));
        r=max(r,c);
    }
    
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    
    if(res==oo) puts("NO PATH EXISTS");
    else printf("%d\n",res);
    //getch();
    return 0;
}
