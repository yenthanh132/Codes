#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

char s[4][maxn];
bool mark[4][maxn];
int n,k;

bool ok;

bool check(int x, int y, int step){
    y+=step*2;
    if(y>n || s[x][y]=='.') return 1;
    return 0;
}

void dfs(int x, int y){
    mark[x][y]=1;
    if(y>n){
        ok=1;
        return;
    }
    for(int v=-1; v<=1; ++v){
        int xt=x+v;
        int yt=y+1;
        if(xt<1 || xt>3) continue;
        if(!check(x,yt,y-1) || !check(xt,yt,y) || !check(xt,yt,y-1)) continue;
        if(!mark[xt][yt]) dfs(xt,yt);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=3; ++i) scanf("%s",s[i]+1);
        reset(mark,0);
        int xs=1;
        while(s[xs][1]!='s') ++xs;
        ok=0;
        dfs(xs,1);
        if(ok) puts("YES");
        else puts("NO");
    }
}

