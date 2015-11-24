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

const int maxn=1000007;

int n,a[maxn],bit[maxn],f[maxn];
map<int,int> cnt;

int get(int i){
    int r=0;
    for(;i; i-=i&(-i)) r+=bit[i];
    return r;
}

void update(int i, int v){
    for(;i<=n; i+=i&(-i)) bit[i]+=v;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=n; i>=1; --i){
        cnt[a[i]]++;
        f[i]=cnt[a[i]];
        update(f[i],1);
    }
    cnt.clear();
    ll res = 0;
    for(int i=1; i<=n; ++i){
        cnt[a[i]]++;
        int x=cnt[a[i]];
        update(f[i],-1);
        res += get(x-1);
    }
    printf("%I64d\n",res);

    return 0;
}
