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

bool check(ll n, ll k, ll d1, ll d2){
    ll v = (n-k) - (d1*2+d2);
    ll u = k - (d1+d2*2);
    if(v>=0 && v%3==0 && u>=0 && u%3==0) return 1;
    return 0;
}

int main(){
//freopen("input.txt","r",stdin);
    int t;
    ll n,k,d1,d2;
    scanf("%d",&t);
    for(int i=0; i<t; ++i){
        scanf("%I64d %I64d %I64d %I64d",&n,&k,&d1,&d2);
        if(d1>d2) swap(d1,d2);
        if(check(n,k,d1,d2) || check(n,k,d2,d1) || check(n,k,d2-d1,d1) || check(n,k,d1,d2-d1)) puts("yes");
        else puts("no");
    }
}
