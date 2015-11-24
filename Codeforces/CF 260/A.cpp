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

const int maxn=500007;

int n,a[maxn],cnt;
ll f[maxn][2];
ll v[maxn],num[maxn];

ll get(){
    f[1][0]=0; f[1][1]=v[1];
    for(int i=2; i<=cnt; ++i){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        f[i][1]=f[i-1][0]+v[i];
    }
    //cout<<cnt<<' '<<f[cnt][0]<<' '<<f[cnt][1]<<endl;
    return max(f[cnt][0],f[cnt][1]);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll res = 0;
    for(int i=1,j; i<=n; i=j+1){
        j=i;
        while(j+1<=n && a[j+1]<=a[j]+1) ++j;
        num[cnt = 1]=a[i];
        v[1] = a[i];
        for(int x=i+1; x<=j; ++x){
            if(num[cnt] == a[x]){
                v[cnt] += a[x];
            }else{
                num[++cnt] = a[x];
                v[cnt] = a[x];
            }
        }
        res += get();
    }
    cout<<res<<endl;
}
