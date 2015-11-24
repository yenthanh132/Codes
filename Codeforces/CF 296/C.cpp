#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,m,deg[maxn];
multiset<int> a[maxn];
stack<int> mys;
vector<int> lst,euler;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    reset(deg,0);
    int u,v;
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        a[u].insert(v);
        a[v].insert(u);
        ++deg[u]; ++deg[v];
    }
    for(int i=1; i<=n; ++i) if(deg[i]&1) lst.pb(i);
    for(int i=0; i<sz(lst); i+=2){
        int u=lst[i], v=lst[i+1];
        a[u].insert(v); a[v].insert(u);
    }

    mys.push(1);
    while(!mys.empty()){
        int u=mys.top();
        if(a[u].empty()){
            euler.pb(u);
            mys.pop();
        }else{
            int v=*a[u].begin();
            a[u].erase(a[u].begin());
            a[v].erase(a[v].find(u));
            mys.push(v);
        }
    }
    if(sz(euler)%2==0) euler.pb(euler[0]);
    printf("%d\n",sz(euler)-1);
    for(int i=0; i<sz(euler)-1; ++i){
        int u=euler[i], v=euler[i+1];
        if(i&1) swap(u,v);
        printf("%d %d\n",u,v);
    }
}

