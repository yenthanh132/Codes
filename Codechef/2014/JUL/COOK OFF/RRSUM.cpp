
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

ll N,M;
ll q;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld%lld",&N,&M);
    ll len=N*2-1;
    for(int i=0; i<M; ++i){
        scanf("%lld",&q);
        if(q<N+1 || q>3*N) printf("0\n");
        else{
            ll val = q-(N+1);
            if(val*2 > len) val=len-val+1;
            printf("%lld\n",val);
        }
    }
    return 0;
}
