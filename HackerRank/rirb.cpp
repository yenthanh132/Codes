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

const int maxn=65;
ll f[maxn][maxn][maxn][2],val[maxn][maxn];
int bit[maxn];

void cal(ll V, int sign){
    for(int i=0; i<60; ++i) if(V>>i&1) bit[i+1]=1; else bit[i+1]=0;
    reset(f,0);
    f[60][0][0][0]=1;
    for(int i=60; i>=1; --i) for(int j=0; j<=60; ++j) for(int z=0; z<=60; ++z)
        for(int s=0; s<2; ++s) if(f[i][j][z][s]){
            if(s>0){
                f[i-1][j][z][s] += f[i][j][z][s];
                f[i-1][j+1][z?z:i][s] += f[i][j][z][s];
            }else{
                if(bit[i]==1){
                    f[i-1][j+1][z?z:i][s] += f[i][j][z][s];
                    f[i-1][j][z][s|1] += f[i][j][z][s];
                }else{
                    f[i-1][j][z][s] += f[i][j][z][s];
                }
            }
        }
    for(int j=0; j<=60; ++j) for(int z=1; z<=60; ++z)
        val[z][j] += sign*(f[0][j][z][0]+f[0][j][z][1]);
}

void solve(ll A, ll B){
    reset(val,0);
    cal(B,1); cal(A-1,-1);
    double r1, r2;
    r1 = r2 = 0;
    for(int j=0; j<=60; ++j) for(int z=1; z<=60; ++z){
        r1 += 1.0*val[z][j]/(B-A+1)*j/z;
        r2 += val[z][j] * j;
    }
    r2 /= (B-A+1);
    printf("%0.5lf %0.5lf\n",r1,r2);
}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    ll A,B;
    for(int tt=1; tt<=T; ++tt){
        scanf("%lld%lld",&A,&B);
        solve(A,B);
    }
    return 0;
}
