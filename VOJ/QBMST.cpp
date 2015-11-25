#include <stdio.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
#define tr(contain,it) for(typeof(contain.begin()) it = contain.begin();it!=contain.end();it++)
#define oo 1000000007
#define maxn 10001

int n,m,d[maxn];
bool free1[maxn];
vector<ii> a[maxn];
set<ii> s;

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[--u].push_back(ii(--v,w));
        a[v].push_back(ii(u,w));
    }
    fill_n(d,n,oo);
    fill_n(free1,n,true);
    d[0]=0;
    s.insert(ii(0,0));
    for(int index=0;index<n-1;index++){
        int u=s.begin()->second; s.erase(s.begin());
        free1[u]=false;
        for(auto it=a[u].begin();it!=a[u].end();it++){
            int v=it->first, w=it->second;
            if (free1[v] && d[v]>w){
                if (d[v]!=oo) s.erase(s.find(ii(d[v],v)));
                d[v]=w;
                s.insert(ii(d[v],v));
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=d[i];
    printf("%d\n",ans);
    return 0;
}
            
