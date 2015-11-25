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
const int maxs=10007;

int rf[maxn][maxs],lf[maxs],n,a[maxn],s;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&s);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    rf[n+1][0]=1;
    FORD(i,n,1) FOR(j,0,s){
        rf[i][j]=rf[i+1][j];
        if(j>=a[i]) rf[i][j]=(rf[i][j]+rf[i+1][j-a[i]])%oo;
    }
    lf[0]=1;
    FOR(i,1,n){
        int res=0;
        FOR(j,0,s-a[i]) res=(res+1ll*lf[j]*rf[i+1][s-a[i]-j])%oo;
        printf("%d ",res);
        FORD(j,s,a[i]) lf[j]=(lf[j]+lf[j-a[i]])%oo;
    }
    //getch();
    return 0;
}
        

