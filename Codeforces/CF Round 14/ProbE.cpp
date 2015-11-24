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

int n,k,f[21][21][4];

#include <conio.h>
int main(){
    cin>>n>>k;
    REP(i,3) f[1][0][i]=1;
    FOR(i,2,n)
        FOR(j,1,k*2)
            REP(z,4)
                if(j&1){
                    FOR(x,1,3) if(z+x<4) f[i][j][z+x]+=f[i-1][j][z]+f[i-1][j-1][z];
                }
                else{
                    FOR(x,1,3) if(z-x>=0) f[i][j][z-x]+=f[i-1][j][z]+f[i-1][j-1][z];
                }
    int res=0;
    REP(x,4) res+=f[n][k*2][x];
    cout<<res;
    //getch();
    return 0;
}
                
            
