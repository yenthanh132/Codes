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

ll m,n,k;

ll calc(ll v){
    ll res=0;
    for(ll i=1; i<=min(v,m); ++i){
        res+=min(n,v/i);
    }
    return res;
}

int main(){
    cin>>m>>n>>k;
    if(m>n) swap(m,n);

    ll l=1, r=m*n, mid, res;

    while(l<=r){
        ll mid=(l+r)/2;
        if(calc(mid)>=k){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<endl;
}
