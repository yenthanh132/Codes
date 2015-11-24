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

const int maxn=1007;

int a[maxn],b[maxn],n,T;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        b[1]=a[1];
        b[n+1]=a[n];
        for(int i=2; i<=n; ++i) b[i]=lcm(a[i-1],a[i]);
        for(int i=1; i<=n; ++i) printf("%d ",b[i]);
        printf("%d\n",b[n+1]);
    }
    return 0;
}
