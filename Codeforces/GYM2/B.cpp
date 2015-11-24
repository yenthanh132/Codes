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

const int maxn=607;

int n,l,m,k;
ll dp[maxn][maxn];
char s[maxn][20];
bool mark[maxn][maxn];

bool check(int u, int v){
    FOR(i,2,k) if(s[u][i]!=s[v][i-1]) return 0;
    return 1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>l>>m;
    while(n){
        FOR(i,1,m) scanf("%s",s[i]+1);
        k=strlen(s[1]+1);
        FOR(u,1,m) FOR(v,1,m)
            mark[u][v]=check(u,v);
        if(k>l) puts("0");
        else{
            l-=k-1;
            FOR(j,1,m) dp[1][j]=1;
            FOR(i,2,l) FOR(j,1,m){
                dp[i][j]=0;
                FOR(z,1,m) if(mark[z][j]) dp[i][j]+=dp[i-1][z];   
            }
            ll res=0;
            FOR(j,1,m) res+=dp[l][j];
            printf("%I64d\n",res);
        }
        cin>>n>>l>>m;
    }
    //getch();
    return 0;
}
