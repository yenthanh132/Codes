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

int a[maxn][maxn], dp[maxn][maxn][20], trace[maxn][maxn][20];
int m,n,k;
char s[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k); ++k;

    for(int i=1; i<=m; ++i){
        scanf("%s",s+1);
        for(int j=1; j<=n; ++j) a[i][j]=s[j]-'0';
    }
    reset(dp,-1);
    for(int y=1; y<=n; ++y) dp[m][y][a[m][y]%k]=a[m][y];
    for(int x=m; x>1; --x) for(int y=1; y<=n; ++y) for(int v=0; v<k; ++v) if(dp[x][y][v]!=-1){
        for(int yv=-1; yv<=1; yv+=2){
            int y2=y+yv;
            if(y2>=1 && y2<=n){
                int v2=(v+a[x-1][y2])%k;
                if(dp[x-1][y2][v2] < dp[x][y][v] + a[x-1][y2]){
                    dp[x-1][y2][v2] = dp[x][y][v] + a[x-1][y2];
                    trace[x-1][y2][v2] = y;
                }
            }
        }
    }

    int res=-1, p;
    for(int y=1; y<=n; ++y) if(res<dp[1][y][0]){
        res=dp[1][y][0];
        p=y;
    }
    if(res!=-1){
        printf("%d\n",res);
        string s="";
        for(int x=1, v = 0; x<m; ++x){
            int v2 = (v - a[x][p]%k + k)%k;
            int y2 = trace[x][p][v];
            if(y2>p) s="L"+s; else s="R"+s;
            p=y2; v=v2;
        }
        printf("%d\n",p);
        printf("%s\n",s.c_str());
    }else puts("-1");

    return 0;
}
