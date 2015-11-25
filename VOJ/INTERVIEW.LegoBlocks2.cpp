#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 1001

ll f[maxn][maxn],g[maxn][5],sub[maxn],ans[maxn];

void optimize(){
    int i,j,k;
    for(i=1;i<maxn;i++) f[i][0]=f[0][i]=1;
    for(i=1;i<maxn;i++) for(j=1;j<maxn;j++){
        f[i][j]=0;
        for(k=1;k<=4 && j-k>=0;k++) f[i][j]=(f[i][j]+f[1][j-k]*f[i-1][j])%oo;
    }
    for(j=1;j<=4;j++) g[1][j]=1;
    for(i=2;i<maxn;i++){
        g[i][1]=1;
        g[i][2]=(g[i-1][2]*f[1][2]+1)%oo;
        g[i][3]=(g[i-1][3]*f[1][3]+g[i-1][2]*4+1)%oo;
        g[i][4]=(g[i-1][4]*f[1][4]+g[i-1][3]*8+g[i-1][2]*g[i-1][2]*4+g[i-1][2]*6+1)%oo;
    }
}

ll trumod(ll a, ll b){ return (a-b+(a<b?oo:0));}

void solve(int n, int m){
    if (m<=4){
        printf("%d\n",g[n][m]);
        return;
    }
    int i,j;
    for(i=1;i<=4;i++){sub[i]=trumod(f[n][i],g[n][i]); ans[i]=g[n][i];}
    for(i=5;i<=m;i++){
        sub[i]=ans[i-1];
        for(j=1;i-j>1;j++) sub[i]=(sub[i]+(sub[i-j]+ans[i-j])*ans[j])%oo;
        ans[i]=trumod(f[n][i],sub[i]);
    }
    printf("%d\n",ans[m]);
}
int main(){
    optimize();
    //freopen("test.txt","r",stdin);
    int test,n,m;
    scanf("%d",&test);
    for(int index=0;index<test;index++){
        scanf("%d%d",&n,&m);
        solve(n,m);
    }
    return 0;
}  
    
