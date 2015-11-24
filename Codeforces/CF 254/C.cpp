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
typedef pair<int,pii>iii;
typedef long long ll;

const int maxn=500007;
int n,a[maxn];
pii arr[maxn];
int prev[maxn],next[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i) prev[i]=i-1, next[i]=i+1;
    for(int i=1; i<=n; ++i) arr[i]=pii(a[i],i);
    ll res = 0;
    sort(arr+1,arr+n+1);
    for(int i=1; i<=n-2; ++i){
        int x = arr[i].second;
        if(prev[x]==0){
            res += arr[i].first;
            prev[next[x]] = 0;
            continue;
        }else if(next[x]==n+1){
            res += arr[i].first;
            next[prev[x]] = n+1;
            continue;
        }
        res += min(a[prev[x]], a[next[x]]);
        next[prev[x]] = next[x];
        prev[next[x]] = prev[x];
    }
    cout<<res<<endl;
    return 0;
}
