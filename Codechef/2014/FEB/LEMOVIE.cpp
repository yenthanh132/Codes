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

const int maxn=207;

ll C[maxn][maxn],frac[maxn];
int T,n,k,a[maxn];
ll f[maxn][maxn];


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    C[0][0]=1;
    FOR(i,1,200){
        C[i][0]=1;
        FOR(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;   
    }
    frac[0]=1;
    FOR(i,1,200) frac[i]=(frac[i-1]*i)%oo;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);   
        reset(f,0);
        ll res=frac[n-1];
        f[n][1]=1;
        FORD(i,n-1,1) FOR(j,1,k){
            FOR(z,i+1,n){
                int j2=j;
                if(a[i]<a[z]) --j2;
                if(j2>0) f[i][j] = (f[i][j] + (f[z][j2]*C[n-i-1][z-i-1])%oo * frac[z-i-1])%oo;   
            }
            res = (res + (f[i][j]*C[n-1][i-1])%oo *frac[i-1])%oo;
        }
        cout<<res<<endl;
    }   
}
