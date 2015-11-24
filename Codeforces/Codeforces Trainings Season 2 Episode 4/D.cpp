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

int n,m,sx,sy;
pii p[5];
char s[maxn][maxn],st[maxn][maxn];
char table[10][10],key[10];

pii point(int x, int y, pii p0, pii px, pii py){
    pii ox = pii((px.first-p0.first)/(n-1), (px.second-p0.second)/(n-1));
    pii oy = pii((py.first-p0.first)/(n-1), (py.second-p0.second)/(n-1));
    pii res = pii(p0.first + ox.first*(x-1) + oy.first * (y-1), p0.second + ox.second*(x-1) + oy.second*(y-1));
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) s[i][j]='.';

    int x,y;
    p[1]=pii(1,1);
    p[2]=pii(1,n);
    p[3]=pii(n,n);
    p[4]=pii(n,1);
    sx=sy=1;

    for(int i=0; i<m; ++i){
        scanf("%s",key);
        if(key[1]=='O'){ //ROTATE
            scanf("%s",key);
            if(strlen(key)==2){ //CW
                for(int i=5; i>1; --i) p[i]=p[i-1];
                p[1]=p[5];
            }else{ //CCW
                for(int i=0; i<4; ++i) p[i]=p[i+1];
                p[4]=p[0];
            }
        }else if(key[1]=='I'){ //MIRROR
            scanf("%s",key);
            if(key[0]=='H'){ //HOR
                swap(p[1],p[4]);
                swap(p[2],p[3]);
            }else{ //VER
                swap(p[1],p[2]);
                swap(p[3],p[4]);
            }
        }else{ //REPLACE
            scanf("%d%d",&x,&y);
            for(int i=1; i<=3; ++i) scanf("%s",table[i]+1);
            for(int i=1; i<=3; ++i) for(int j=1; j<=3; ++j){
                int xt=x+i-1, yt=y+j-1;
                pii pos = point(xt,yt,p[1],p[4],p[2]);
                s[pos.first][pos.second]=table[i][j];
            }
        }
    }

    for(int x=1; x<=n; ++x){
        for(int y=1; y<=n; ++y){
            pii pos=point(x,y,p[1],p[4],p[2]);
            printf("%c",s[pos.first][pos.second]);
        }
        puts("");
    }
}

