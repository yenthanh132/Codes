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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

double f[maxn][maxn];
int n,m;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    f[1][1]=1;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(f[i][j]>0){
        f[i+1][j+1] += f[i][j]*(m-j)/(m*n-i);
        f[i+1][j] += f[i][j]*(m*(n-1) - (i-j))/(m*n-i);
    }
    double res = 0;
    for(int j=1; j<=m; ++j) res += f[n][j]*j/n;
    printf("%0.9lf\n",res);
    return 0;
}
