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

vector<pii> a[maxn];
int lock[maxn],mys[maxn],mys2[maxn];
int n,m,last,last2;


int DFS(int u){
    int v,id,x;
    int first=last;
    int first2=last2;
    REP(i,sz(a[u])){
        v=a[u][i].fi; id=a[u][i].se;
        if(lock[id]==0){
            mys2[++last2]=v;
            lock[id]=1;
        }
    } 
    
    FOR(it,first2+1,last2){
        v=mys2[it];
        x=DFS(v);
        if(x) printf("%d %d %d\n",u,v,x);
        else  mys[++last]=v;
    }
    
    while(last-first>1){
        x=mys[last--];
        v=mys[last--];
        printf("%d %d %d\n",v,u,x);
    }
    last2=first2;
    if(last>first){
        v=mys[last--];
        return v;   
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    int x,y;
    REP(i,m){
        scanf("%d%d",&x,&y); 
        a[x].pb(pii(y,i));
        a[y].pb(pii(x,i));  
    }
    reset(lock,0);
    last=last2=0;
  
    if(m&1) puts("No solution");
    else DFS(1);
}
