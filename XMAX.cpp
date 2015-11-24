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


const int maxn=100007;
ll a[maxn];
int n;

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
    int c = 1;
    for(int i=60; i>=0 && c<=n; --i){
        if(((a[c]>>i) & 1) == 0){
            for(int j=c+1; j<=n; ++j)
                if((a[j]>>i)&1){
                    swap(a[c],a[j]);
                    break;
                }
        }
        if((a[c]>>i)&1){
            for(int j=1; j<=n; ++j) if(j!=c && ((a[j]>>i)&1)) a[j]^=a[c];
            ++c;
        }
    }
    ll res = 0;
    for(int i=1; i<=n; ++i) res^=a[i];
    cout<<res<<endl;

    return 0;
}
