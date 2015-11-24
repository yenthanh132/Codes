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

const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};

int r,c,t,m,cnt;
char s[57][57];
bool free1[10][10];

void dfs(int x, int y){
    ++cnt;
    free1[x][y]=0;   
    int xt,yt,v=0;
    REP(k,8){
        xt=x+dx[k]; yt=y+dy[k];
        if(1<=xt && xt<=r && 1<=yt && yt<=c && s[xt][yt]=='*') ++v;
    }
    if(v>0) return;
    REP(k,8){
        xt=x+dx[k]; yt=y+dy[k];
        if(1<=xt && xt<=r && 1<=yt && yt<=c && free1[xt][yt] && s[xt][yt]=='.') dfs(xt,yt);
    }
}

int f(int x, int y){
    if(s[x][y]=='*') return 0;
    cnt=0;
    reset(free1,1);
    dfs(x,y);   
    return cnt;
}

bool check(int mask){
    int id=0;
    FOR(i,1,r) FOR(j,1,c) s[i][j]='.';
    FOR(i,1,r) FOR(j,1,c){        
        if((mask>>id)&1) s[i][j]='*';
        id++;
    }
    FOR(x,1,r) FOR(y,1,c) if(f(x,y)==r*c-m){
        s[x][y]='c';
        return 1;   
    }
    return 0;
}

int main(){
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);   
    
    cin>>t;
    FOR(tt,1,t){
        cin>>r>>c>>m;
        int n=r*c;
        bool found=0;
        REP(mask,1<<n){
            int cnt=0;
            REP(i,n) if((mask>>i)&1) ++cnt;
            if(cnt==m && check(mask)){
                found=1;
                break;   
            }
        }
        printf("Case #%d:\n",tt);
        if(found){
            FOR(i,1,r){
                FOR(j,1,c) putchar(s[i][j]);
                puts("");   
            }
        }else puts("Impossible");
    }
    
    return 0;
}
