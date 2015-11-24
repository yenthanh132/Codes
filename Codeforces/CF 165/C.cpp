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

const int maxn=200007;

struct edge{
    int y,w,id,v;
    edge(int a, int b, int c, int d){
        y=a; w=b;
        id=c; v=d;
    }
};
vector<edge> a[maxn];
int n,m,ans[maxn],vol[maxn],val[maxn];
bool free1[maxn];
queue<int> myq;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    reset(free1,1);
    int x,y,c;
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,&c);
        a[x].pb(edge(y,c,i,0));
        a[y].pb(edge(x,c,i,1));
        vol[x]+=c; vol[y]+=c;
    }
    REP(i,sz(a[1])){
        edge &t=a[1][i];
        if(!free1[t.id]) continue;
        ans[t.id]=t.v;
        val[t.y]+=t.w;
        free1[t.id]=0;
        if(t.y!=n && t.y!=1 && val[t.y]*2==vol[t.y]) myq.push(t.y);
    }
    while(!myq.empty()){
        x=myq.front(); myq.pop();
        REP(i,sz(a[x])){
            edge &t=a[x][i];
            if(!free1[t.id]) continue;
            ans[t.id]=t.v;
            val[t.y]+=t.w;
            free1[t.id]=0;
            if(t.y!=n && t.y!=1 && val[t.y]*2==vol[t.y]) myq.push(t.y);
        }
    }
    FOR(i,1,m) printf("%d\n",ans[i]);
    //getch();
    return 0;
}
