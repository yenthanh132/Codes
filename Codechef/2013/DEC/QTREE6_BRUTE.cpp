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

int color[maxn],n,m,myq[maxn],first,last,mark[maxn];
vector<int> a[maxn];

int count(int u, int id){
    myq[first=last=1]=u;
    mark[u]=id;
    int v;
    while(first<=last){
        u=myq[first++];
        REP(i,sz(a[u])){
            v=a[u][i];
            if(mark[v]!=id && color[v]==color[u]){
                mark[v]=id;
                myq[++last]=v;
            }
        }               
    }
    return last;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int u,v;
    scanf("%d",&n);
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);   
    }
    scanf("%d",&m);
    reset(color,0);
    reset(mark,0);
    REP(tt,m){
        scanf("%d%d",&u,&v);
        if(u==1) color[v]^=1;
        else printf("%d\n",count(v,tt+1));
    }   
    return 0;
}
    
