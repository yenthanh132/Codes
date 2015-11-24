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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;

#define maxn 207

int m,n,k,a[maxn][maxn],f[128][maxn][maxn];
pii list[8],trace[128][maxn][maxn];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
char arr[maxn][maxn];
bool free1[maxn][maxn];

void dijkstra(int id){
        set<piii> myset;
        FOR(i,1,m) FOR(j,1,n) myset.insert(piii(f[id][i][j],pii(i,j)));
        reset(free1,true);
        while(!myset.empty()){
            pii tail=myset.begin()->se; myset.erase(myset.begin());
            free1[tail.fi][tail.se]=false;
            REP(z,4){
                int x=dx[z]+tail.fi, y=dy[z]+tail.se;
                if(x<1 || x>m || y<1 || y>n || !free1[x][y]) continue;
                if(f[id][x][y]>f[id][tail.fi][tail.se]+a[x][y]){
                    myset.erase(myset.find(piii(f[id][x][y],pii(x,y))));
                    f[id][x][y]=f[id][tail.fi][tail.se]+a[x][y];
                    trace[id][x][y]=tail;
                    myset.insert(piii(f[id][x][y],pii(x,y)));
                }
            }
        }
}

void solve(){
    REP(id,1<<k) FOR(i,1,m) FOR(j,1,n) f[id][i][j]=oo;
    FOR(i,1,k){
        f[1<<i-1][list[i].fi][list[i].se]=a[list[i].fi][list[i].se]; 
        trace[1<<i-1][list[i].fi][list[i].se]=pii(-1,-1);
    }
    FOR(id,1,(1<<k)-1){
        FOR(i,1,m) FOR(j,1,n){
            vector<int> bits;
            REP(z,k) if((id>>z)&1) bits.pb(z);
            int subid;
            REP(z,1<<sz(bits)){
                subid=0;
                REP(h,sz(bits)) if((z>>h)&1) subid+=1<<bits[h];
                if(subid==id || subid==0) continue;
                if(f[id][i][j]>f[subid][i][j]+f[id^subid][i][j]){
                    f[id][i][j]=f[subid][i][j]+f[id^subid][i][j]-a[i][j];
                    trace[id][i][j]=pii(0,subid);
                }
            }
        }
        dijkstra(id);
    }
}

void traceback(int id, int x, int y){
    arr[x][y]='X';
    if(trace[id][x][y].fi==-1) return;
    if(trace[id][x][y].fi==0){
        int subid=trace[id][x][y].se;
        if(subid!=id) traceback(subid,x,y);
        if(id^subid!=id) traceback(id^subid,x,y);
    }else traceback(id,trace[id][x][y].fi,trace[id][x][y].se);
}
            
void output(){
    int x,y;
    x=y=1;
    FOR(i,1,m) FOR(j,1,n) if(f[(1<<k)-1][i][j]<f[(1<<k)-1][x][y]) x=i, y=j;
    printf("%d\n",f[(1<<k)-1][x][y]);
    FOR(i,1,m) FOR(j,1,n) arr[i][j]='.';
    traceback((1<<k)-1,x,y);
    FOR(i,1,m){
        FOR(j,1,n) printf("%c",arr[i][j]);
        printf("\n");
    }
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,k) scanf("%d%d",&list[i].fi,&list[i].se);
    solve();
    output();
    //getch();
    return 0;
}
    
