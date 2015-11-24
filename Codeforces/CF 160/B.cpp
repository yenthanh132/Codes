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

const int maxn=57;

int n,q,a[maxn],list[maxn],m;
double dp[maxn][maxn][maxn];
double res;

void optimize(){
    
    FOR(j,0,m) FOR(v,0,q-1) dp[0][j][v]=0;
    dp[0][0][0]=1;
    FOR(i,1,m)
        FOR(j,0,m) FOR(v,0,q){
            dp[i][j][v]=dp[i-1][j][v];
            if(v>=list[i] && j>0)
                dp[i][j][v]+=dp[i-1][j-1][v-list[i]];
        }
}

double gt[maxn];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int sum=0;
    FOR(i,1,n) scanf("%d",&a[i]), sum+=a[i];
    scanf("%d",&q);
    if(sum<=q){
        printf("%0.12lf\n",1.0*n);
        //getch();
        return 0;
    }
    gt[0]=1;
    FOR(i,1,n) gt[i]=gt[i-1]*i;
    
    res=0;    
    FOR(r,1,n){
        m=0;
        FOR(i,1,n) if(i!=r) list[++m]=a[i];
        optimize();
        FOR(i,1,m) FOR(v,max(q-a[r]+1,0),q){
            //cout<<r<<' '<<i<<' '<<v<<' '<<dp[m][i][v]<<endl;
            res+= i * dp[m][i][v] * gt[i] * gt[n-i-1]/gt[n];
        }
    }
    printf("%0.12lf\n",res);
    getch();
    return 0;
}
