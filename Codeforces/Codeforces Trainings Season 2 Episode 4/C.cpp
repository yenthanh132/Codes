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

int a[maxn][maxn],n,d[maxn][maxn],dis[maxn][maxn];
pii myq[maxn*maxn*4];
int first,last;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n*2+1; ++i) for(int j=1; j<=n*2+1; ++j) scanf("%d",&a[i][j]);
    myq[first=last=1]=pii(n+1,n+1);
    reset(dis,-1);
    d[n+1][n+1]=oo;
    dis[n+1][n+1]=0;
    while(first<=last){
        int x=myq[first].first, y=myq[first++].second;
        for(int k=0; k<4; ++k){
            int xt=x+dx[k], yt=y+dy[k];
            if(xt<1 || xt>n*2+1 || yt<1 || yt>n*2+1) continue;
            int val=a[x][y]-a[xt][yt];
            if(0<=val && val<=d[x][y]){
                if(dis[xt][yt]==-1){
                    d[xt][yt]=val;
                    dis[xt][yt]=dis[x][y]+1;
                    myq[++last]=pii(xt,yt);
                }else if(dis[xt][yt]==dis[x][y]+1 && d[xt][yt]<val){
                    d[xt][yt]=val;
                    myq[++last]=pii(xt,yt);
                }
            }
        }
    }
    int xRet=-1,yRet, mindis=oo;
    for(int x=1; x<=n*2+1; ++x) for(int y=1; y<=n*2+1; ++y) if((x==1 || x==n*2+1 || y==1 || y==n*2+1) && dis[x][y]>=0){
        if(mindis>dis[x][y]){
            xRet=x;
            yRet=y;
            mindis=dis[x][y];
        }
    }
    if(mindis==oo) puts("IMPOSSIBLE");
    else printf("%d\n%d %d\n",mindis,xRet,yRet);
}

