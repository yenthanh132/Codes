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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

vector<int> e[maxn];
vector<int> vec;
int lab[maxn],len[maxn][2], dep[maxn];
int n,m,q;
int mark[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;

    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

pii dfs(int u, int p){
    int v;
    mark[u]=1;
    pii r = pii(u,0);
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i];
        if(v==p) continue;
        dsu(u,v);
        pii t = dfs(v,u);
        t.second++;
        if(r.second<t.second) r=t;
    }
    return r;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    int u,v,k;
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }

    reset(lab,-1);
    reset(mark,0);
    for(int u=1; u<=n; ++u) if(!mark[u]){
        int length = dfs(dfs(u,-1).first,-1).second;
        int r=getroot(u);
        len[r][0]=length-length/2; len[r][1]=length/2;
    }
    for(int qq=0; qq<q; ++qq){
        scanf("%d%d",&k,&u);
        if(k==1){
            int r=getroot(u);
            printf("%d\n",len[r][0]+len[r][1]);
        }else{
            scanf("%d",&v);
            int r1=getroot(u);
            int r2=getroot(v);
            if(r1==r2) continue;
            dsu(r1,r2);
            int newr = getroot(u);

            int val;
            if(len[r1][0] > len[r2][0]){
                len[0][0]=len[r1][0];
                len[0][1]=len[r1][1];
                val = len[r2][0]+1;

            }else{
                len[0][0]=len[r2][0];
                len[0][1]=len[r2][1];
                val=len[r1][0]+1;
            }

                if(len[0][0]<val){
                    len[0][1]=len[0][0];
                    len[0][0]=val;
                }else if(len[0][1]<val)
                    len[0][1]=val;

            len[newr][0]=len[0][0];len[newr][1]=len[0][1];
        }
    }
}
