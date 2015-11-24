#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

int t, n;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> t;
    for (int te = 1; te <= t; te++) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
        }
        if (n == 1) printf("Case #%d: 1\n", te);
        else printf("Case #%d: 2\n", te);
    }

    return 0;
}

