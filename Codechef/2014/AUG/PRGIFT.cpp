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

int T,n,k,a[55];

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; ++i){
            scanf("%d",&a[i]);
        }
        bool found = 0;
        for(int l=1; l<=n; ++l) for(int r=l; r<=n; ++r){
            int c=0;
            for(int x=l; x<=r; ++x) if(a[x]%2==0) ++c;
            if(c==k){
                found=1;
            }
        }
        if(found) puts("YES"); else puts("NO");
    }
}
