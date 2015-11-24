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

int f[111][111][2];
int n,k,d;

int main(){
    
    cin>>n>>k>>d;
    reset(f,0);
    f[0][0][0]=1;    
    FOR(i,0,n) FOR(s,0,n) FOR(z,0,1){
        FOR(v,1,k) if(s+v<=n){
            int z2=z|(v>=d);
            f[i+1][s+v][z2]=(f[i+1][s+v][z2] + f[i][s][z])%oo;
        }
    }
    int res=0;
    FOR(i,1,n) res=(res+f[i][n][1])%oo;
    cout<<res<<endl;
    
}
