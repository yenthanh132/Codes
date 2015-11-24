#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int org = 50;
int T,X,R,C,cnt;
int mark[100][100];
bool check;

//for fill checking
int x1,x2,y1,y2,comcnt;

void dfs(int x, int y){
    mark[x][y]=cnt;
    ++comcnt;
    for(int k=0; k<4; ++k){
        int xt=x+dx[k], yt=y+dy[k];
        if(xt<x1 || xt>x2 || yt<y1 || yt>y2 || mark[xt][yt]==-1 || mark[xt][yt]==cnt) continue;
        dfs(xt,yt);
    }
}

bool fill_check(){
    ++cnt;
    for(int x=x1; x<=x2; ++x) for(int y=y1; y<=y2; ++y) if(mark[x][y]!=-1 && mark[x][y]!=cnt){
        comcnt = 0;
        dfs(x,y);
        if(comcnt%X) return 0;
    }
    return 1;
}

void duyet(int i, int x, int y, int minx, int maxx, int miny, int maxy){
    if(!check) return;
    if(i>=X){
        int h=maxx-minx+1, w=maxy-miny+1;
        bool ok=0;
        for(int ix=minx-(R-h); ix<=minx; ++ix)
            for(int iy=miny-(C-w); iy<=miny; ++iy){
                x1=ix; y1=iy;
                x2=ix+R-1; y2=iy+C-1;
                if(fill_check()) ok=1;
            }
        for(int ix=minx-(C-h); ix<=minx; ++ix)
            for(int iy=miny-(R-w); iy<=miny; ++iy){
                x1=ix; y1=iy;
                x2=ix+C-1; y2=iy+R-1;
                if(fill_check()) ok=1;
            }
        if(!ok){
            check=0;
        }
        return;
    }
    for(int k=0; k<4; ++k){
        if(i==1 && k==3) continue; //do not move down on first step
        int xt=x+dx[k], yt=y+dy[k];
        if(mark[xt][yt]==-1) continue;
        mark[xt][yt]=-1;
        duyet(i+1,xt,yt,min(minx,xt),max(maxx,xt), min(miny,yt), max(maxy,yt));
        mark[xt][yt]=0;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d%d",&X,&R,&C);
        printf("Case #%d: ",tt);
        if(X>=7 || (R*C)%X>0){
            puts("RICHARD");
            continue;
        }

        check = 1;
        reset(mark,0); cnt=0;
        mark[org][org]=-1;
        duyet(1,org,org,org,org,org,org);

        if(check) puts("GABRIEL");
        else puts("RICHARD");
    }
}

