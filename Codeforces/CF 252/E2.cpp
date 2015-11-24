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

const int maxn=333;
const int maxb=8;
double f[maxn][maxn][1<<maxb],pd;
int x,k,p,maxv;

int bound(int v){
    int res=0;
    REP(i,maxb) if((v>>i)&1) res+=1<<i;
    return res;
}

int cal(int v){
    int c=0;
    REP(i,maxb) if((v>>i)&1) return c; else ++c;
    return c;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t=0,xx;
    cin>>x>>k>>p;
    xx=x;
    pd=p/100.0;

    while(xx%2==0){
        t++;
        xx/=2;
    }
    maxv=k+t+32;

    FOR(i,0,k) FOR(j,0,maxv) REP(z,1<<maxb) f[i][j][z]=0;
    int v=0;
    REP(j,maxb) if((x>>j)&1) v+=1<<j;
    f[0][t][v]=1;

    FOR(i,0,k-1) FOR(j,0,maxv) REP(z,1<<maxb) if(f[i][j][z]){
        f[i+1][j+1][bound(z<<1)] += f[i][j][z]*pd;
        int z2=bound(z+1);
        f[i+1][cal(z2)][z2] += f[i][j][z]*(1-pd);
    }

    double res=0;
    FOR(j,0,maxv) REP(z,1<<maxb) if(f[k][j][z]>0){
        res+=f[k][j][z]*j;
    }
    printf("%0.9lf\n",res);
}

