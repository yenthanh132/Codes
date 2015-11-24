#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int,char> pic;
typedef pair<string,int> psi;

const int maxn=20007;

int n,ans[maxn];
psi val[maxn];
vector<pic> e[maxn];

void dfs0(int u, int p){
    val[u] = psi("",u);
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==p) continue;
        dfs0(v,u);
        psi t = psi(e[u][i].second + val[v].first, val[v].second);
        if(val[u] < t) val[u] = t;
    }
}



void dfs(int u, int p, psi top){
    psi r = max(top,val[u]);
    ans[u] = r.second;
    psi max1,max2;
    max1=max2=psi("",u);
    int x1,x2;
    x1=x2=-1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==p) continue;
        psi t = val[v];
        t.first = e[u][i].second + t.first;
        if(max1 < t){
            x2 = x1;
            x1 = v;
            max2 = max1;
            max1 = t;
        }else if(max2 < t){
            x2 = v;
            max2 = t;
        }
    }

    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==p) continue;
        psi t = top;
        if(v!=x1) t = max(t, max1);
        else t = max(t, max2);
        t.first = e[u][i].second + t.first;
        dfs(v, u, t);
    }


}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n-1; ++i){
        int u,v;
        char s[5];
        scanf("%d%d%s",&u,&v,s);
        e[u].pb(pic(v,s[0]-'a'));
        e[v].pb(pic(u,s[0]-'a'));
    }
    dfs0(1,-1);
    dfs(1,-1,psi("",0));
    for(int u=1; u<=n; ++u){
        printf("%d ",ans[u]);
    }
}

