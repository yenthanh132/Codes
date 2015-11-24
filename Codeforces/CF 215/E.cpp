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

int f[2][507][507];
int n,m,x;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d%d",&n,&m,&x);
    if(n>m){
        puts("0");
        return 0;   
    }
    f[0][0][0]=1;

    FOR(i,1,m){
        int cur=(i-1)%2;
        int next=i%2;
        FOR(j,0,n) FOR(k,0,n) f[next][j][k]=0;
        FOR(j,0,n) FOR(k,0,n) if(f[cur][j][k])
            if(i==x){
                f[next][j][k+1] = (f[next][j][k+1] + f[cur][j][k])%oo;
                f[next][j+1][k+1] = (f[next][j+1][k+1] + f[cur][j][k])%oo;
            }else{
                f[next][j][k+1] = (f[next][j][k+1] + f[cur][j][k])%oo;
                f[next][j+1][k+1] = (f[next][j+1][k+1] + f[cur][j][k])%oo;
                f[next][j][k] = (f[next][j][k] + f[cur][j][k])%oo;
                if(j<k) f[next][j+1][k] = (f[next][j+1][k] + f[cur][j][k])%oo;
            }
    }
    
    ll res = f[m%2][n][n];
    FOR(i,2,n) res=(res*i)%oo;
    printf("%I64d\n",res);
    
    return 0;
}
