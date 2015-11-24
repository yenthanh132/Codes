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
#define sqr(x) x*x
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector <pii> fact, res;
int k, _k;

ll mypow(ll x, ll y) {
    if (y == 0) return 1;
    ll res = mypow(x , y / 2);
    res *= res;
    if (y & 1) res *= x;
    return res;
}

void dq(int pos, ll value) {
    if (pos == sz(fact)) {
        res.pb(pii(value + _k, (ll)_k * (ll)_k / value + (ll)_k));
        ll a=value+_k;
        ll b= (ll)_k * (ll)_k / value + (ll)_k;

        return;
    }
    for (int times = 0; times <= fact[pos].second; times++)
        dq(pos + 1, value * mypow(fact[pos].first, times));
}

int main(){

    scanf("%d", &k);
    if (k == 1) {
        puts("1"); puts("2 2"); return 0;
    }
    _k = k;
    int sqrtk = sqrt(k);
    for (int i = 2; i <= sqrtk; i++) {
        if (k % i) continue;
        int m = sz(fact);
        fact.pb(pii(i, 0));
        while (k % i == 0) {
            fact[m].second++;
            k /= i;
        }
    }
    if (k > 1)
        fact.pb(pii(k, 1));
    for (int i = 0; i < sz(fact); i++)
        fact[i].second *= 2;
//    for (int i = 0; i < sz(fact); i++)
//        cout << fact[i].first << " " << fact[i].second << endl;

    dq(0, 1);
    cout << sz(res) << endl;
    for (int i = 0; i < sz(res); i++)
        if(res[i].first *res[i].second !=_k*(res[i].first+res[i].second)){
        cout << res[i].first << " " << res[i].second << endl;
    }

    return 0;
}
