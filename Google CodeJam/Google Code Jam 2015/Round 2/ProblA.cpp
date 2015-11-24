#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=207;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const char dir[4] = {'^','>','v','<'};

char a[maxn][maxn];
int T,m,n;
vector<pii> lst;

int getdir(char c){
    for(int i=0; i<4; ++i) if(dir[i]==c) return i;
    return -1;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&m,&n);
        for(int i=1; i<=m; ++i) scanf("%s",a[i]+1);
        lst.clear();
        for(int x=1; x<=m; ++x){
            for(int y=1; y<=n; ++y){
                int k=getdir(a[x][y]);
                if(k==-1) continue;
                int xt=x,yt=y;
                xt+=dx[k]; yt+=dy[k];
                bool found = 0;
                while(1<=xt && xt<=m && 1<=yt && yt<=n){
                    if(getdir(a[xt][yt])!=-1){
                        found=1;
                        break;
                    }
                    xt+=dx[k]; yt+=dy[k];
                }
                if(!found) lst.pb(pii(x,y));

            }
        }

        bool impossible = 0;
        for(int i=0; i<sz(lst); ++i){
            int x=lst[i].first, y=lst[i].second;
            int kt=getdir(a[x][y]);
            bool found = 0;
            for(int k=0; k<4 && !found; ++k) if(k!=kt){
                int xt=x+dx[k], yt=y+dy[k];
                while(1<=xt && xt<=m && 1<=yt && yt<=n){
                    if(getdir(a[xt][yt])!=-1){
                        found=1;
                        break;
                    }
                    xt+=dx[k]; yt+=dy[k];
                }
            }
            if(!found){
                impossible = 1;
                break;
            }
        }

        printf("Case #%d: ",tt);
        if(impossible) puts("IMPOSSIBLE");
        else printf("%d\n",sz(lst));
    }

    return 0;
}

