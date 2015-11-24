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

int main(){
    int m,n,a,b;
    cin>>n>>m>>a>>b;
    int res = oo;
    for(int i=0; i<=n; ++i) res=min(res,b*i + max(0,n-m*i)*a);
    cout<<res<<endl;
    return 0;
}
