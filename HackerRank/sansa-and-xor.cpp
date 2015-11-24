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

int main(){
    //freopen("input.txt","r",stdin);
    int T,v,n,res;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        res = 0;
        for(int i=1; i<=n; ++i){
            scanf("%d",&v);
            ll l=i, r=n-i+1;
            if((l*r)&1) res^=v;
        }
        printf("%d\n",res);
    }
    return 0;
}
