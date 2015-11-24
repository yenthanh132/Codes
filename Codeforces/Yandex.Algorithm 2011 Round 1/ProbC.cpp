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

const int maxn = 100007;

int n,k,root,val[maxn],Left[maxn],Right[maxn],lnode[maxn],rnode[maxn];
vector<int> a[maxn];
vector<bool> leaf;
vector<pair<int,double> > list;

void dfs1(int u){
    int v;
    Left[u]=Right[u]=val[u];
    REP(i,sz(a[u])){
        v=a[u][i];
        dfs1(v);
        Left[u]=min(Left[u],Left[v]);
        Right[u]=max(Right[u],Right[v]);
        if(val[v]<val[u]) lnode[u]=v; else rnode[u]=v;
    }
}

void dfs2(int u, ll sum, int c){
    if(a[u].empty()){
        list.pb(mp(val[u],1.0*sum/c));
        leaf.pb(1);
        return;
    }
    int l=lnode[u], r=rnode[u];
    dfs2(l,sum+Left[r],c+1);
    list.pb(mp(val[u],0)); leaf.pb(0);
    dfs2(r,sum+Right[l],c+1);
}

double get(int v){
    int l=0,r=n-1,mid,res=0;
    while(l<=r){
        mid=(l+r)/2;
        if(list[mid].fi<v){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    if(res==n-1 || leaf[res]) return(list[res].se); else return(list[res+1].se);
}
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v;
    FOR(i,1,n){
        scanf("%d%d",&u,&v);
        if(u==-1) root=i;
        else a[u].pb(i);
        val[i]=v;
    }
    dfs1(root);
    dfs2(root,0,0);
    
    scanf("%d",&k);
    REP(index,k){
        scanf("%d",&v);
        printf("%0.12f\n",get(v));
    }
    
    //getch();
    return 0;
}
        
