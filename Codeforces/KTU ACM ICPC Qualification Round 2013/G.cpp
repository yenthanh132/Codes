#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

const ll modl = 1e9 + 7;

ll pow(ll a, ll n) {
    if (n == 0) return 1;
    ll ret = pow(a, n/2);
    ret = (ret * ret) % modl;
    if (n&1) ret = (ret * a) % modl;
    return ret;
}

ll a[30030];
map<ll, int> f;

int main() {
//    freopen("input.txt", "r", stdin);

    int nTest;
    scanf("%d", &nTest);
    for (int test = 1; test <= nTest; test++) {
        int n;
        scanf("%d", &n);
        f.clear();
        ll ret = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", a+i);
            if (f[a[i]]) {
                f[a[i]]--;
                ret++;
            }
            else f[pow(a[i], modl-2)]++;
        }
        printf("Case #%d: %I64d\n", test, ret);
    }

    return 0;
}

