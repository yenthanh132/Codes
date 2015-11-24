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
typedef pair<int,pii> piii;

const int maxn = 1007;

int n,m,a[maxn][maxn],p[maxn],lab[maxn];
bool free1[maxn];
vector<piii> edge;

int findset(int u){
    if(lab[u]<0) return u;
    int r=findset(lab[u]);
    lab[u]=r; return r;
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
    scanf("%d",&m);
    FOR(i,1,m){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        edge.pb(piii(c,pii(x,y)));
    }
    sort(edge.begin(),edge.end());
    int cost=0, ce=0;
    FOR(i,1,n) lab[i]=-1;
    reset(free1,1);
    REP(i,m){
        int r1=findset(edge[i].se.fi), r2=findset(edge[i].se.se);
        if(r1!=r2 && free1[edge[i].se.se]){
            cost+=edge[i].fi;
            ce++;
            free1[edge[i].se.se]=0;
            if(ce==n-1) break;
            dsu(r1,r2);
        }
    }
    if(ce==n-1) cout<<cost; else cout<<-1;
    //getch();
    return 0;
}
    
    
