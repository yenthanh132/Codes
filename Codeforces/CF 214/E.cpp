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

int m,n,k,s,a[10][10];
vector<pii> list[10];

int cal(int x, int y){
    if(x>y) swap(x,y);
    if(a[x][y]!=-1) return a[x][y];

    int minx1=oo, miny1=oo;
    int maxx1=-oo, maxy1=-oo;
    REP(i,sz(list[x])){
        minx1=min(minx1,list[x][i].fi);
        miny1=min(miny1,list[x][i].se);
        maxx1=max(maxx1,list[x][i].fi);
        maxy1=max(maxy1,list[x][i].se);   
    }
    int minx2=oo, miny2=oo;
    int maxx2=-oo, maxy2=-oo;
    REP(i,sz(list[y])){
        minx2=min(minx2,list[y][i].fi);
        miny2=min(miny2,list[y][i].se);
        maxx2=max(maxx2,list[y][i].fi);
        maxy2=max(maxy2,list[y][i].se);   
    }
    a[x][y]=max( max(maxx2-minx1, maxx1-minx2), max(maxy2-miny1, maxy1-miny2));
    return a[x][y];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d%d%d",&m,&n,&k,&s);
    int v,u;
    FOR(x,1,m) FOR(y,1,n){
        scanf("%d",&v);
        list[v].pb(pii(x+y,x-y));
    }
    reset(a,-1);
    u=-1;
    int res=0;
    REP(i,s){
        scanf("%d",&v);
        if(u!=-1) res=max(res,cal(u,v));
        u=v;
    }
    
    printf("%d\n",res);

}
