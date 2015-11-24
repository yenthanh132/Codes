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

const int maxn=2007;
const ll vmod=(ll)round(1e9);

ll C[maxn][maxn];

int main(){
    reset(C,0);
    C[0][0]=1;
    for(int i=1; i<=2000; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%vmod;
    }
    int T;
    ll N,K;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>N>>K;
        cout<<C[N+K-1][K]<<endl;
    }
    return 0;
}
