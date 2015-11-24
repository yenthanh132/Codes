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

const int maxn = 507;

int n,m,arr[maxn][maxn],s[maxn][26][2],f[maxn][26][26];
pii trace[maxn][26][26];

void optimize(){
    REP(x,26) REP(y,26) if(x!=y) f[0][x][y]=m-s[0][x][0]-s[0][y][1];
    FOR(i,1,n-1) REP(x,26) REP(y,26) if(x!=y){
        f[i][x][y]=oo;
        REP(xt,26) if(xt!=x) REP(yt,26) if(yt!=y && xt!=yt)
            if(f[i][x][y]>f[i-1][xt][yt]){
                f[i][x][y]=f[i-1][xt][yt];
                trace[i][x][y]=pii(xt,yt);
            }
        f[i][x][y]+=m-s[i][x][0]-s[i][y][1];
    }
}       

void output(){
    int xt,yt,minv=oo;
    REP(x,26) REP(y,26) if(x!=y && minv>f[n-1][x][y]){
        minv=f[n-1][x][y];
        xt=x; yt=y;
    }
    cout<<minv<<endl;
    REPD(i,n){
        REP(j,m) if(j&1) arr[i][j]=yt; else arr[i][j]=xt;
        pii t=trace[i][xt][yt];
        xt=t.fi; yt=t.se;
    }
    REP(i,n){
        REP(j,m) cout<<char(arr[i][j]+'a');
        cout<<endl;
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    char ch;
    REP(i,n) REP(j,m){
        cin>>ch;
        arr[i][j]=ch-'a';
    }
    REP(i,n) REP(j,m)
        REP(v,26) if(v==arr[i][j]) s[i][v][j%2]++;
    optimize();
    output();
    //getch();
    return 0;
}
    
