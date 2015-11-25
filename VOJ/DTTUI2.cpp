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

const int maxn = 101;
const int maxm = 10001;

int n,m,f[maxn][maxm][11];
struct vang{int w,v,c;} a[maxn];

void optimize(){
    reset(f,0);
    FOR(i,1,n)
        FOR(j,0,m){
            f[i][j][0]=f[i-1][j][10];
            if(j>=a[i].w) f[i][j][0]=max(f[i][j][0],f[i-1][j-a[i].w][10]+a[i].v);
            FOR(k,1,10){
                f[i][j][k]=f[i][j][k-1];
                if(a[i].c>=(1<<k)){
                    if(j>=a[i].w*(1<<k-1)) f[i][j][k]=max(f[i][j][k],f[i][j-a[i].w*(1<<k-1)][k-1]+a[i].v*(1<<k-1));
                }else if(a[i].c>=(1<<k-1)){
                    int left=a[i].c-(1<<k-1);
                    if(j>=a[i].w*(1<<k-1)) f[i][j][k]=max(f[i][j][k],f[i][j-a[i].w*left][k-1]+a[i].v*left);
                }
            }
        }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i].w>>a[i].v>>a[i].c;
    optimize();
    cout<<f[n][m][10];
    //getch();
    return 0;
}
