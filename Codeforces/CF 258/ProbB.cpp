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

int n,a[maxn],l[maxn],r[maxn],jump[maxn];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    l[0]=1;
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        if(i==1 || a[i]>=a[i-1]) l[i]=l[i-1];
    }
    r[n+1]=1; jump[n+1]=n+1;
    for(int i=n; i>=1; --i){
        if(i<n && a[i]>=a[i+1]) jump[i]=jump[i+1];
        else jump[i]=i;
        if(i==n || a[i]<=a[i+1]) r[i]=r[i+1];
    }
    if(l[n]==1){
        puts("yes");
        puts("1 1");
        return 0;
    }
    for(int i=0; i<n; ++i) {
        if(!l[i]) break;
        int j=jump[i+1];
        if(r[j+1] && (i==0 || a[i]<=a[j]) && (i+1>n || j+1>n || a[i+1] <= a[j+1])){
            puts("yes");
            printf("%d %d\n",i+1,j);
            return 0;
        }
    }

    puts("no");
    return 0;
}
