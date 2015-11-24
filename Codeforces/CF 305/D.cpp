#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=400007;
const int base=200000;
int n,deg[maxn],u[maxn],v[maxn];
char ans[maxn];
map<pii,int> pos;
multiset<int> e[maxn];
vector<int> odd;
vector<int> path;
stack<int> mys;
bool free1[maxn];

void dfs(int u){
    mys.push(u);
    while(!mys.empty()){
        int u=mys.top();
        free1[u]=0;
        if(e[u].empty()){
            path.pb(u);
            mys.pop();
        }else{
            int v=*e[u].begin();
            e[u].erase(e[u].begin());
            e[v].erase(e[v].find(u));
            mys.push(v);
        }
    }

    for(int i=0; i<sz(path)-1; ++i){
        int x=path[i], y=path[i+1];
        if((x<=base)!=(y<=base)){
            char ch='r';
            if(x>base){
                x-=base;
                swap(x,y);
            }else{
                y-=base;
                ch='b';
            }
            if(pos.count(pii(x,y))) ans[pos[pii(x,y)]]=ch;
        }
    }


}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&u[i],&v[i]);
        pos[pii(u[i],v[i])]=i;
        e[u[i]].insert(v[i]+base);
        ++deg[u[i]];
        e[v[i]+base].insert(u[i]);
        ++deg[v[i]+base];
    }

    for(int i=1; i<=base*2; ++i)
        if(deg[i]&1)
            odd.pb(i);
    for(int i=0; i<sz(odd); i+=2){
        int x=odd[i], y=odd[i+1];
        ++deg[x]; ++deg[y];
        e[x].insert(y);
        e[y].insert(x);
    }

    reset(free1,1);
    for(int i=1; i<=base*2; ++i) if(free1[i] && deg[i]>0) dfs(i);
    for(int i=1; i<=n; ++i) printf("%c",ans[i]);
}
