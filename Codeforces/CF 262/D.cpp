
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

ll arr[20];
vector<ll> res;
ll l,r,k;
ll best;

bool find3(vector<ll> &tmp){
    ll x=1,y=2,z=3;
    while(x<l){
        x=x*2+1;
        y=y*2+1;
        z=z*2;
    }
    if(z<=r){
        tmp.clear();
        tmp.pb(x);
        tmp.pb(y);
        tmp.pb(z);
        return 1;
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>l>>r>>k;
    best = -1;
    if(k<=4){
        int K = k;
        for(int i=0; i<k; ++i) arr[i]=l+i;
        if(l+k<=r) arr[k]=l+k, ++K;
        for(int i=1; i<(1<<K); ++i){
            ll val = 0;
            vector<ll> tmp;
            for(int j=0; j<K; ++j) if(i>>j&1) val^=arr[j], tmp.pb(arr[j]);
            if(sz(tmp)<=k && (best==-1 || best > val)){
                best = val;
                res = tmp;
            }
        }
    }
    if(k==3 && best>0 && find3(res)) best = 0;
    if(k>=5){
        best = 0;
        if(l&1) ++l;
        for(int i=0; i<4; ++i) res.pb(l+i);
    }
    cout<<best<<endl;
    cout<<sz(res)<<endl;
    for(int i=0; i<sz(res); ++i) cout<<res[i]<<' ';
    cout<<endl;
}
