#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char s[maxn][maxn];
int m,n,d[4][maxn][maxn];
pii myq[maxn*maxn];

pii bfs(int r, int f1, int f2);

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1; i<=m; ++i) scanf("%s",s[i]+1);
    ll res=oo;
    vector<ll> value;
    pii p = bfs(1,2,3);
    value.pb(p.first);
    value.pb(p.second);
    p = bfs(2,3,1);
    value.pb(p.first);
    bfs(3,1,2);

    sort(value.begin(),value.end());
    res = min(res, 1ll*value[0]+value[1]);

    for(int x=1; x<=m; ++x) for(int y=1; y<=n; ++y)
        if(d[1][x][y]!=oo && d[2][x][y]!=oo && d[3][x][y]!=oo)
            res=min(res, 1ll*d[1][x][y]+d[2][x][y]+d[3][x][y]-2);


    if(res==oo) res=-1;
    cout<<res<<endl;
}


pii bfs(int r, int f1, int f2){
    int d1=oo, d2=oo;
    int first=1, last=0;
    for(int x=1; x<=m; ++x) for(int y=1; y<=n; ++y)
        if(s[x][y]-'0'==r){
            myq[++last]=pii(x,y);
            d[r][x][y]=0;
        }else d[r][x][y]=oo;
    while(first<=last){
        int x=myq[first].first, y=myq[first].second; ++first;
        for(int k=0; k<4; ++k){
            int xt=x+dx[k], yt=y+dy[k];
            if(xt<1 || xt>m || yt<1 || yt>n || d[r][xt][yt]!=oo) continue;
            if(s[xt][yt]=='#') continue;
            if(s[xt][yt]-'0'==f1) d1=min(d1,d[r][x][y]);
            else if(s[xt][yt]-'0'==f2) d2=min(d2,d[r][x][y]);
            d[r][xt][yt]=d[r][x][y]+1;
            myq[++last]=pii(xt,yt);
        }
    }
    return pii(d1,d2);
}
