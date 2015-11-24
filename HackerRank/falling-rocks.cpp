#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[1111][1111];
int w,h;
bool found;
bool free1[1111][1111];

void dfs(int x, int y){
    free1[x][y]=0;
    if(y==h){
        found=1;
        return;
    }
    for(int v=-1; v<=1; ++v){
        int xt=x+v;
        if(xt<1 || xt>w) continue;
        if(s[y][xt]=='R' || s[y+1][xt]=='R') continue;
        if(free1[xt][y+1]) dfs(xt,y+1);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&w,&h);
    for(int i=1; i<=h; ++i) scanf("%s",s[i]+1);
    found=0; reset(free1,1);
    for(int j=1; j<=w; ++j) if(s[1][j]=='Y') dfs(j,1);
    if(found) puts("YES"); else puts("NO");
}

