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

const int maxn = 501;

int a[maxn],b[maxn],n,m,f[maxn][maxn];
pii trace[maxn][maxn];

void optimize(){
    reset(f,0);
    FOR(i,1,n) FOR(j,1,m)
        if(a[i]==b[j]){
            f[i][j]=1;
            FOR(k,1,i-1) if(a[k]<a[i] && f[i][j]<f[k][j-1]+1){
                f[i][j]=f[k][j-1]+1;
                trace[i][j]=pii(k,j-1);
            }
        }else{
            f[i][j]=f[i][j-1];
            trace[i][j]=pii(i,j-1);
        }
}

void output(){
    int maxv=0, i, j, ii, jj;
    FOR(x,1,n) FOR(y,1,m) if(maxv<f[x][y]) maxv=f[x][y],i=x,j=y;
    cout<<f[i][j]<<endl;
    vector<int> list;
    while(f[i][j]>0){
        ii=trace[i][j].fi; jj=trace[i][j].se;
        if(f[i][j]==f[ii][jj]+1) list.pb(a[i]);
        i=ii; j=jj;
    }
    REPD(i,sz(list)) cout<<list[i]<<' ';
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n); FOR(i,1,n) scanf("%d",a+i);
    scanf("%d",&m); FOR(i,1,m) scanf("%d",b+i);
    
    optimize();
    output();
    //getch();
    return 0;
}

