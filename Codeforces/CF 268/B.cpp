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

const int maxn=100007;

int next[2][maxn];
int a,b,n,num[maxn],res[maxn];
map<int,int> pos;
bool free1[maxn];

bool dfs(int u, int ed, int root){
    if(next[ed][u]==-1) return 0;
    int v=next[ed][u];
    res[u]=res[v]=ed;
    int x=next[1^ed][v];
    if(x==-1 || x==root) return 1;
    return dfs(x,ed,root);
}

void doMark(int u){
    free1[u]=0;
    for(int k=0; k<2; ++k){
        int v=next[k][u];
        if(v!=-1 && free1[v]) doMark(v);
    }
}



int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1; i<=n; ++i){
        scanf("%d",&num[i]);
        pos[num[i]]=i;
    }
    reset(next,-1);
    for(int i=1; i<=n; ++i){
        if(num[i]<a){
            int v=a-num[i];
            if(pos.count(v)) next[0][i]=pos[v];
        }
        if(num[i]<b){
            int v=b-num[i];
            if(pos.count(v)) next[1][i]=pos[v];
        }
    }

    bool ok=1;
    reset(free1,1);
    for(int u=1; u<=n; ++u) if(free1[u]){
        if( ((next[0][u]!=-1) ^ (next[1][u]!=-1))
            || (next[0][u]==u) || next[1][u]==u){

            if(!dfs(u,0,u)
                && !dfs(u,1,u)){
                ok=0;
                break;
            }else
                doMark(u);

        }
    }

    if(ok){ //check for circle
        for(int u=1; u<=n; ++u) if(free1[u]){
            if(!dfs(u,0,u) && !dfs(u,1,u)){
                ok=0;
                break;
            }else
                doMark(u);
        }
    }

    if(!ok) puts("NO");
    else{
        puts("YES");
        for(int u=1; u<=n; ++u) printf("%d ",res[u]);
    }
    return 0;
}
