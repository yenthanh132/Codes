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

int a[maxn][maxn],f[4][maxn][maxn],m,n;

void init(){
    reset(f,0);
    FOR(i,1,m) FOR(j,1,n){
        f[0][i][j]=max(f[0][i-1][j],f[0][i][j-1])+a[i][j];   
    }   
    FOR(i,1,m) FORD(j,n,1){
        f[1][i][j]=max(f[1][i-1][j],f[1][i][j+1])+a[i][j];
    }
    FORD(i,m,1) FORD(j,n,1){
        f[2][i][j]=max(f[2][i+1][j],f[2][i][j+1])+a[i][j];           
    }
    FORD(i,m,1) FOR(j,1,n){
        f[3][i][j]=max(f[3][i+1][j],f[3][i][j-1])+a[i][j];   
    }
}

void solve(){
    int res=-oo;
    FOR(i,2,m-1) FOR(j,2,n-1){
        res=max(res ,
            max(f[0][i][j-1] + f[2][i][j+1] + f[3][i+1][j] + f[1][i-1][j],
                f[0][i-1][j] + f[2][i+1][j] + f[3][i][j-1] + f[1][i][j+1]));   
    }   
    printf("%d\n",res);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&m,&n);
    FOR(i,1,m)
        FOR(j,1,n) scanf("%d",&a[i][j]);   
    
    init();
    solve();
    return 0;
}
