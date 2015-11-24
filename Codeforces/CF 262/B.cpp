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

vector<int> res;

int cal(ll v){
    int res = 0;
    while(v){
        res+=v%10;
        v/=10;
    }
    return res;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    for(int v=1; v<=9*9; ++v){
        ll x = 1;
        for(int i=0; i<a; ++i) x*=v;
        x=x*b+c;
        if(1<=x && x<1000000000 && cal(x)==v) res.pb(x);
    }
    sort(res.begin(),res.end());
    cout<<sz(res)<<endl;
    for(int i=0; i<sz(res); ++i) cout<<res[i]<<' ';
    return 0;
}
