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

const int maxn=107;

double p[maxn];
double f[maxn][maxn];
int n;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%lf",&p[i]);
    for(int i=1; i<=n; ++i) if(p[i]==1){
        puts("1");
        return 0;
    }
    sort(p+1,p+n+1,greater<double>());
    double res = 0;
    double s1 = 1, s2 = 0;
    for(int i=1; i<=n; ++i){
        s1 *= 1-p[i];
        s2 += p[i]/(1-p[i]);
        res = max(res,s1*s2);
    }
    printf("%0.12lf\n",res);
}
