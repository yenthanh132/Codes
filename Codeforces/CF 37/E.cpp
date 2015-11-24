#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int maxn=57;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char buf[maxn];
int a[maxn][maxn];
int m,n,d[maxn][maxn];
bool free1[maxn][maxn];
set<piii> mys;

int dijkstra(int x, int y){
    FOR(i,1,m) FOR(j,1,n) d[i][j]=oo, free1[i][j]=1;
    d[x][y]=0;
    mys.insert(piii(0,pii(x,y)));
    int xt,yt;
    while(!mys.empty()){
        x=mys.begin()->se.fi; y=mys.begin()->se.se; mys.erase(mys.begin());
        free1[x][y]=0;
        REP(k,4){
            xt=x+dx[k]; yt=y+dy[k];
            if(xt>=1 && xt<=m && yt>=1 && yt<=n && free1[xt][yt] && d[xt][yt]>d[x][y]+(a[x][y]^a[xt][yt])){
                if(d[xt][yt]!=oo) mys.erase(mys.find(piii(d[xt][yt],pii(xt,yt))));
                d[xt][yt]=d[x][y]+(a[x][y]^a[xt][yt]);
                mys.insert(piii(d[xt][yt],pii(xt,yt)));
            }
        }
    }
    int res=-1;
    FOR(i,1,m) FOR(j,1,n) if(a[i][j]) res=max(res,d[i][j]);
    return res+1;
}
    
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&m,&n);
    FOR(i,1,m){
        scanf("%s",buf+1);
        FOR(j,1,n) a[i][j]=(buf[j]=='B');
    }
    int res=oo;
    FOR(i,1,m) FOR(j,1,n) res=min(res,dijkstra(i,j));
    cout<<res<<endl;
    return 0;
}    
