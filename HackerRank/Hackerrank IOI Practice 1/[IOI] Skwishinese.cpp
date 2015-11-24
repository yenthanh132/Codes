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

const int maxn=407;

char s[maxn];
int dp[maxn][maxn][maxn],jump[maxn][26],pos[26];
int n;

int cal(int i, int j, int p){
    if(i>j) return 0;
    if(p>n) return oo;
    if(dp[i][j][p]!=-1) return dp[i][j][p];
    int &res=dp[i][j][p]; res=oo;
    int newp;

    if(s[i]==s[j]){
        newp=jump[p][s[i]-'a'];
        if(newp<=n) res=min(res, cal(i+1,j-1,newp+1) + 1);
    }
    newp=jump[p][s[i]-'a'];
    if(newp<=n) res=min(res,cal(i+1,j,newp+1) + 1);
    newp=jump[p][s[j]-'a'];
    if(newp<=n) res=min(res,cal(i,j-1,newp+1) + 1);

    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    REP(v,26) pos[v]=n+1;
    FORD(i,n,1){
        pos[s[i]-'a']=i;
        REP(v,26) jump[i][v]=pos[v];
    }
    reset(dp,-1);
    cout<<cal(1,n,1)<<endl;

    return 0;
}

