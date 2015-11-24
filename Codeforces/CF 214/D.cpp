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

const int maxn=1007;
const int maxv=1000007;

struct edge{
    int y,l,r;
    edge(){}
    edge(int a, int b, int c){
        y=a; l=b; r=c;   
    }
};

vector<edge> e[maxn];
vector<int> list_val;
int n,m,mark[maxn];

void dfs(int u, int &x, int &y){
    mark[u]=1;
    REP(i,sz(e[u])){
        edge &ed=e[u][i];
        if(ed.l<=x && y<=ed.r && !mark[ed.y]) dfs(ed.y,x,y);   
    }
}

bool check(int x, int y){
    reset(mark,0);
    dfs(1,x,y);
    return mark[n];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    int u,v,l,r;
    
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d%d%d",&u,&v,&l,&r);
        e[u].pb(edge(v,l,r));
        e[v].pb(edge(u,l,r));  
        list_val.pb(l); list_val.pb(r);
    }
    
    sort(list_val.begin(),list_val.end());
    list_val.resize(unique(list_val.begin(), list_val.end()) - list_val.begin());
    
    int res=0,i=0,j;
    REP(i,sz(list_val)) if(check(list_val[i], list_val[i])){
        int left=i+1, right=sz(list_val)-1, mid, pos=i;
        while(left<=right){
            mid=(left+right)/2;
            if(check(list_val[i], list_val[mid])){
                pos=mid;
                left=mid+1;   
            }else right=mid-1;
        }
        res=max(res,list_val[pos]-list_val[i]+1);
    }
    
    if(res==0) puts("Nice work, Dima!"); else printf("%d\n",res);
}
