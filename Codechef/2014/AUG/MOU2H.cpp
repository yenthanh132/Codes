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
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int n,a[maxn],pos[maxn],arr[maxn],b[maxn];
ll f[maxn],s[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for(int i=1; i<n; ++i) a[i]-=a[i+1];
        --n;
        //nomarlize
        for(int i=1; i<=n; ++i) b[i]=a[i];
        sort(b+1,b+n+1);
        int m=unique(b+1,b+n+1)-(b+1);
        for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1,b+m+1,a[i])-b;

        for(int v=1; v<=m; ++v) pos[v]=0;


        s[0]=1;
        for(int i=1; i<=n; ++i){
            f[i] = s[i-1];
            int pre=pos[a[i]];
            if(pre>0) f[i] = (f[i] - s[pre-1] + oo)%oo;
            pos[a[i]]=i;
            s[i] = (s[i-1] + f[i])%oo;
        }
        ll res = s[n]-1;
        if(res<0) res+=oo;
        printf("%lld\n",res);
    }
    return 0;
}
