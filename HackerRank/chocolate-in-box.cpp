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

int a[maxn],n;

int main(){
    scanf("%d",&n);
    int v=0;
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        v^=a[i];
    }

    int res=0;
    for(int i=1; i<=n; ++i)
        if( (v^a[i]) <= a[i]) ++res;

    cout<<res<<endl;

    return 0;
}
