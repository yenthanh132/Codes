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

int a[maxn],n,m,w,d[maxn];

bool check(ll h){
    reset(d,0);
    int val = 0;
    int x = m;
    for(int i=1; i<=n; ++i){
        val+=d[i];
        while(a[i]+val<h){
            if(x==0) return 0;
            val++;
            d[min(i+w,n+1)]--;
            --x;
        }
    }
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    ll l=0, r=oo*2, mid, res = 0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res<<endl;
}
