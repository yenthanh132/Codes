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

const int maxn=3007;

int a[maxn][maxn*2],n,k,w,h,f[maxn][maxn*2];
ll res;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    h=n; w=n*2-1;
    int d=1;
    FOR(i,1,h){
        FOR(j,n-d/2,n+d/2) a[i][j]=1;
        d+=2;
    }
    int x,y,z;
    FOR(i,1,k){
        scanf("%d%d%d",&x,&y,&z);
        a[n-z+1][n+y-x]=0;
    }
    res=0;
    FOR(i,1,h) FOR(j,1,w) if(a[i][j] && !((i+j+n)&1)){
        f[i][j]=1;
        if(a[i-1][j]) f[i][j]=min(f[i-1][j-1],f[i-1][j+1])+1;
        res+=f[i][j];
    }
    FORD(i,h,1) FOR(j,1,w) if(a[i][j] && ((i+j+n)&1)){
        f[i][j]=1;
        if(a[i+1][j]) f[i][j]=min(f[i+1][j-1],f[i+1][j+1])+1;
        res+=f[i][j];
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
