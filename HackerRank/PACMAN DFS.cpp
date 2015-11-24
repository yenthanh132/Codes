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

const int maxn=1007;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,1,-1,0};

vector<pii> list;
vector<string> a;
int trace[maxn][maxn],m,n;
bool free1[maxn][maxn];
bool found;

void duyet(int x, int y){
    if(found) return;
    free1[x][y]=0;
    list.pb(pii(x,y));
    if(a[x][y]=='.'){
        found=1;
        return;
    }
    int xt,yt;
    REP(k,4){
        if(found) return;
        xt=x+dx[k]; yt=y+dy[k];
        if(xt>=0 && xt<m && yt>=0 && yt<n && a[xt][yt]!='%' && free1[xt][yt]){
            trace[xt][yt]=k;
            duyet(xt,yt);
        }
    }
}    
    
void dfs( int x, int y, int pacman_x, int pacman_y, int food_x, int food_y, vector <string> grid){
    a=grid;
    m=x; n=y;
    reset(free1,1);
    duyet(pacman_x,pacman_y);
    cout<<sz(list)<<endl;
    REP(i,sz(list)) cout<<list[i].fi<<' '<<list[i].se<<endl;
    list.clear();
    while(food_x!=pacman_x || food_y!=pacman_y){
        list.pb(pii(food_x,food_y));
        int k=trace[food_x][food_y];
        food_x-=dx[k]; food_y-=dy[k];   
    }
    cout<<sz(list)<<endl;
    cout<<pacman_x<<' '<<pacman_y<<endl;
    REPD(i,sz(list)) cout<<list[i].fi<<' '<<list[i].se<<endl;
    //your logic here
}
