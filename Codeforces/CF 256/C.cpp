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

const int maxn=5007;

int a[maxn],n;
int dp[maxn][maxn];

int f(int l, int r, int base){
    if(dp[l][r]!=-1) return dp[l][r];
    int &res=dp[l][r];
    res=r-l+1;
    int minv=oo;
    for(int i=l; i<=r; ++i) minv=min(minv,a[i]);
    int i=l;
    while(i<=r && a[i]==minv) ++i;
    int tmp=minv-base;
    while(i<=r && tmp<=res){
        int j=i;
        while(j+1<=r && a[j+1]>minv) ++j;
        tmp+=f(i,j,minv);
        i=j+1;
        while(i<=r && a[i]==minv) ++i;
    }
    res=min(res,tmp);
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    reset(dp,-1);
    cout<<f(1,n,0)<<endl;
    return 0;
}
