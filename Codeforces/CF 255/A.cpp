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

const int maxn=100006;

int n,a[maxn],l[maxn],r[maxn];
vector<pii> b;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    l[1]=1;
    for(int i=2; i<=n; ++i)
        if(a[i-1]<a[i]) l[i]=l[i-1]+1;
        else l[i]=1;
    r[n]=1;
    for(int i=n-1; i>=1; --i)
        if(a[i]<a[i+1]) r[i]=r[i+1]+1;
        else r[i]=1;

    int res=l[1];
    for(int i=1; i<=n; ++i) res=max(res,l[i]);

    for(int i=1; i<=n; ++i){
        res=max(res,l[i-1]+1);
        res=max(res,r[i+1]+1);
        if(2<=i && i<n && a[i-1]+1<a[i+1]) res=max(res,l[i-1]+r[i+1]+1);
    }

    cout<<res<<endl;
    return 0;
}
