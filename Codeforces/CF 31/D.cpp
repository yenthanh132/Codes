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

const int maxn=207;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int a[maxn][maxn],w,h,n,cnt;
vector<int> list;

void dfs(int x, int y){
    a[x][y]=1;
    if(x&1 && y&1) cnt++;
    int xt,yt;
    REP(k,4){
        xt=x+dx[k]; yt=y+dy[k];
        if(xt>=0 && xt<=w*2 && yt>=0 && yt<=h*2 && a[xt][yt]==0) dfs(xt,yt);
    }
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    scanf("%d%d%d",&w,&h,&n);
    reset(a,0);
    FOR(x,0,2*w) a[x][0]=a[x][h*2]=1;
    FOR(y,0,2*h) a[0][y]=a[w*2][y]=1;
    int x1,y1,x2,y2;
    FOR(i,1,n){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(y1==y2) FOR(x,x1*2,x2*2) a[x][y1*2]=1;
        else FOR(y,y1*2,y2*2) a[x1*2][y]=1;
    }
    FOR(x,0,w*2) FOR(y,0,h*2) if(a[x][y]==0){
        cnt=0;
        dfs(x,y);
        list.pb(cnt);
    }
    sort(list.begin(),list.end());
    REP(i,sz(list)) printf("%d ",list[i]);
    return 0;
}
