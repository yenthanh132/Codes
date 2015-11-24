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

const int maxn=2007;

vector<int> fac[maxn];
int n,k;
ll f[maxn][maxn];

int main(){
    FOR(i,1,2000){
        for(int v=1; v*v<=i; ++v) if(i%v==0){
            fac[i].pb(v);
            if(i/v!=v) fac[i].pb(i/v);   
        }   
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    f[1][0]=1;
    cin>>n>>k;
    FOR(i,1,n) FOR(j,1,k){
        int v;
        f[i][j]=0;
        REP(z,sz(fac[i])){
            v=fac[i][z];
            f[i][j]+=f[v][j-1];     
        }   
        f[i][j]%=oo;
    }
    ll res=0;
    FOR(i,1,n) res+=f[i][k];
    cout<<res%oo<<endl;
    return 0;
}
