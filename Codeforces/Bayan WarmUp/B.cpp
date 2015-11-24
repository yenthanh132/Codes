#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=22;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const char dc[4]={'^','>','v','<'};

bool mark[maxn][maxn];
char h[maxn],v[maxn];
int m,n;

void dfs(int x, int y){
    mark[x][y]=1;
    for(int k=0; k<4; ++k) if(dc[k]==h[x] || dc[k]==v[y]){
        int xt=x+dx[k], yt=y+dy[k];
        if(xt<1 || xt>m || yt<1 || yt>n) continue;
        if(mark[xt][yt]) continue;
        dfs(xt,yt);
    }
}

bool check(int x, int y){
    reset(mark,0);
    dfs(x,y);
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(!mark[i][j]) return 0;
    return 1;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
//    scanf("%s",h+1);
//    scanf("%s",v+1);
//    bool ok=1;
//    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(!check(i,j)) ok=0;
//    if(ok) puts("YES"); else puts("NO");
    string hor,vert;
    cin>>hor>>vert;
    if(hor[0]=='<' && vert[0]=='^' || hor[0]=='>' && vert[sz(vert)-1]=='^' || hor[sz(hor)-1]=='<' && vert[0]=='v' || hor[sz(hor)-1]=='>' && vert[sz(vert)-1]=='v') cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}

