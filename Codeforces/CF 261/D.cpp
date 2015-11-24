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

int bit[maxn],n,a[maxn],val[maxn];
map<int,int> mc;

void update(int i, int v){
    for(;i;i-=i&(-i)) bit[i]+=v;
}

int get(int i){
    int res=0;
    for(;i<=n;i+=i&(-i)) res+=bit[i];
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    mc.clear();
    reset(bit,0);
    for(int i=1; i<=n; ++i){
        mc[a[i]]++;
        val[i] = mc[a[i]];
        update(val[i],1);
    }

    ll res = 0;
    mc.clear();
    for(int i=n; i>=1; --i){
        mc[a[i]]++;
        int x = mc[a[i]];
        update(val[i],-1);
        res += get(x+1);
    }

    cout<<res<<endl;
    return 0;
}
