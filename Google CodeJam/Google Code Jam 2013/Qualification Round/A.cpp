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

char a[5][5];
int T;

bool isfill(char key, int x1, int y1, int x2, int y2){
    FOR(x,x1,x2) FOR(y,y1,y2) if(a[x][y]!=key && a[x][y]!='T') return 0;
    return 1;
}

int res(){
    bool ok;
    FOR(i,1,4){
        ok=1;
        FOR(j,1,4) if(a[i][j]!='T' && a[i][j]!='X') ok=0;
        if(ok) return 1;
        ok=1;
        FOR(j,1,4) if(a[i][j]!='T' && a[i][j]!='O') ok=0;
        if(ok) return 2;
    }
    FOR(j,1,4){
        ok=1;
        FOR(i,1,4) if(a[i][j]!='T' && a[i][j]!='X') ok=0;
        if(ok) return 1;
        ok=1;
        FOR(i,1,4) if(a[i][j]!='T' && a[i][j]!='O') ok=0;
        if(ok) return 2;
    }
    
    ok=1;
    FOR(i,1,4) if(a[i][i]!='T' && a[i][i]!='X') ok=0;
    if(ok) return 1;
    ok=1;
    FOR(i,1,4) if(a[i][5-i]!='T' && a[i][5-i]!='X') ok=0;
    if(ok) return 1;
    
    ok=1;
    FOR(i,1,4) if(a[i][i]!='T' && a[i][i]!='O') ok=0;
    if(ok) return 2;
    ok=1;
    FOR(i,1,4) if(a[i][5-i]!='T' && a[i][5-i]!='O') ok=0;
    if(ok) return 2;
    
    ok=1;
    FOR(i,1,4) FOR(j,1,4) if(a[i][j]=='.') ok=0;
    if(ok) return 3;
    return 4;
}       

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    FOR(tt,1,T){
        FOR(i,1,4) scanf("%s",a[i]+1);
        printf("Case #%d: ",tt);
        int ans=res();
        if(ans==1) puts("X won");
        else if(ans==2) puts("O won");
        else if(ans==3) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}
