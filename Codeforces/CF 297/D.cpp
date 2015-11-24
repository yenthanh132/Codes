#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2006;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char a[maxn][maxn];
int m,n;
bool free1[maxn][maxn];

bool check(int x, int y){
    int c=0;
    if(a[x][y]=='*') ++c;
    if(a[x+1][y]=='*') ++c;
    if(a[x][y+1]=='*') ++c;
    if(a[x+1][y+1]=='*') ++c;
    return c<=1;
}

void clean(int x, int y){
    a[x][y]='.';
    a[x+1][y]='.';
    a[x][y+1]='.';
    a[x+1][y+1]='.';
}

void dfs(int x, int y){
    clean(x,y);
    free1[x][y]=0;
    for(int k=0; k<4; ++k){
        int xt=x+dx[k], yt=y+dy[k];
        if(xt<1 || xt>=m || yt<1 || yt>=n) continue;
        if(free1[xt][yt] && check(xt,yt)) dfs(xt,yt);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    reset(free1,1);
    scanf("%d%d",&m,&n);
    for(int i=1; i<=m; ++i) scanf("%s",a[i]+1);
    for(int i=1; i<m; ++i) for(int j=1; j<n; ++j)
        if(free1[i][j] && check(i,j))
            dfs(i,j);
    for(int i=1; i<=m; ++i) puts(a[i]+1);
}
