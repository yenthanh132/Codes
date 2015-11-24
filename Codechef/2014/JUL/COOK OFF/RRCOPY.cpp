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


int T,n;
set<int> mys;


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        int v;
        mys.clear();
        for(int i=1; i<=n; ++i){
            scanf("%d",&v);
            mys.insert(v);
        }
        cout<<sz(mys)<<endl;
    }
    return 0;
}
