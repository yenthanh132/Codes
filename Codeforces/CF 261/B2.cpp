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

const int maxn=200007;

int n,a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[1]==a[n]) cout<<0<<' '<<1ll*n*(n-1)/2<<endl;
    else{
        int l=1, r=n;
        while(l+1<=n && a[l+1]==a[1]) ++l;
        while(r-1>=1 && a[r-1]==a[n]) --r;
        cout<<a[n]-a[1]<<' '<<1ll*(n-r+1)*l<<endl;
    }
    return 0;
}
