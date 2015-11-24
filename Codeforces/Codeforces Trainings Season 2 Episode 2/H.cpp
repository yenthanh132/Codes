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
typedef unsigned long long ll;

const int maxn=111;

int n,a[maxn];
ll dp[2][maxn][maxn];
bool free1[2][maxn][maxn];
char op[maxn];
char s[maxn*10];

ll calc(ll a, ll b, char op){
    if(op=='+') return a+b;
    return a*b;
}

ll fmin(int l, int r){
    if(!free1[0][l][r]) return dp[0][l][r];
    if(l==r) return a[l];
    free1[0][l][r]=0;
    ll &res=dp[0][l][r]; res=-1;
    for(int k=l; k<r; ++k) res=min(res,calc(fmin(l,k),fmin(k+1,r),op[k]));
    return res;
}


ll fmax(int l, int r){
    if(!free1[1][l][r]) return dp[1][l][r];
    if(l==r) return a[l];
    free1[1][l][r]=0;
    ll &res=dp[1][l][r]; res=0;
    for(int k=l; k<r; ++k) res=max(res,calc(fmax(l,k),fmax(k+1,r),op[k]));
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%s",s),s[0]!='E'){
        n=0;
        int len=strlen(s);
        for(int i=0; i<len; ){
            int v=0;
            int j=i;
            while(j<len && s[j]!='+' && s[j]!='*'){
                v=v*10+s[j]-'0';
                ++j;
            }
            a[++n]=v;
            if(j<len) op[n]=s[j];
            i=j+1;
        }
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) free1[0][i][j]=free1[1][i][j]=1;
        cout<<fmin(1,n)<<' '<<fmax(1,n)<<endl;
    }
}
