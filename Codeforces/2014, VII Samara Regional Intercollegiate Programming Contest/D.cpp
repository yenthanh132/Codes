#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int m,n,v,xs,ys,xf,yf;
int d[maxn][maxn],com[maxn][maxn],cnt;
pii myq[maxn*maxn];
int first,last;
char arr[maxn][maxn];
int d2[maxn][maxn];
bool mark[maxn][maxn],can_go[maxn][maxn];

bool inside(int x, int y){
    return 1<=x && x<=m && 1<=y && y<=n;
}

void dfs(int x, int y){
    com[x][y]=cnt;
    myq[++last]=pii(x,y);
    d[x][y]=0;
    int xt,yt;
    for(int k=0; k<4; ++k){
        xt=x+dx[k]; yt=y+dy[k];
        if(inside(xt,yt) && com[xt][yt]==0 && arr[xt][yt]=='F') dfs(xt,yt);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&v);
    scanf("%d%d%d%d",&xs,&ys,&xf,&yf);
    cnt=0;
    for(int i=1; i<=m; ++i) scanf("%s",arr[i]+1);

    reset(com,0);
    first=1; last=0;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(!com[i][j] && arr[i][j]=='F'){
        ++cnt;
        dfs(i,j);
    }

    while(first<=last){
        int x=myq[first].first, y=myq[first++].second,xt,yt;
        if(d[x][y]==v) continue;
        for(int k=0; k<4; ++k){
            xt=x+dx[k]; yt=y+dy[k];
            if(!inside(xt,yt)) continue;
            if(com[xt][yt]) continue;
            com[xt][yt]=com[x][y];
            d[xt][yt]=d[x][y]+1;
            myq[++last]=pii(xt,yt);
        }
    }


    reset(can_go,0);
    //the guy walk
    reset(d2,-1);
    d2[xs][ys]=0;
    myq[first=last=1]=pii(xs,ys);
    while(first<=last){
        int x=myq[first].first, y=myq[first++].second,xt,yt;
        can_go[x][y]=1;
        if(d2[x][y]==v) continue;
        for(int k=0; k<4; ++k){
            xt=x+dx[k]; yt=y+dy[k];
            if(!inside(xt,yt) || d2[xt][yt]!=-1) continue;
            d2[xt][yt]=d2[x][y]+1;
            myq[++last]=pii(xt,yt);
        }
    }

    if(can_go[xf][yf]){
        puts("Hello, Deimos!");
        return 0;
    }

    //jump to the forest now
    first=1; last=0;
    reset(mark,0);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(com[i][j] && arr[i][j]=='F' && d2[i][j]!=-1){
            myq[++last]=pii(i,j);
            mark[i][j]=1;
        }
    while(first<=last){
        int x=myq[first].first, y=myq[first++].second,xt,yt;
        can_go[x][y]=1;
        for(int k=0; k<4; ++k){
            xt=x+dx[k]; yt=y+dy[k];
            if(!inside(xt,yt) || mark[xt][yt]) continue;
            if(com[x][y]==com[xt][yt] || (d[x][y]+d[xt][yt]+1<=v)){
                mark[xt][yt]=1;
                myq[++last]=pii(xt,yt);
            }
            if(d[x][y]+1<=v) can_go[xt][yt]=1;
        }
    }

    if(can_go[xf][yf]){
        puts("Hello, Deimos!");
    }else{
        puts("Dire victory");
    }
}

