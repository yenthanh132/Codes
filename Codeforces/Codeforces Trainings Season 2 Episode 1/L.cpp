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
int n,w[maxn],s[maxn],id[maxn];

bool cmp(const int &a, const int &b){
    return s[a]>s[b];
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&w[i],&s[i]), s[i]+=w[i], id[i]=i;
    sort(id+1,id+n+1,cmp);
    int res = -oo;
    int S=0;
    for(int i=n; i>=1; --i){
        S+=w[id[i]];
        res = max(res, S - s[id[i]]);
    }
    cout<<res<<endl;
}
