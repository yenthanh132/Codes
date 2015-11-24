#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define oo 1000000007
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

struct edge {
    int v, d, nr;
    edge(int _v = 0, int _d = 0, int _nr = 0) {
        v = _v; d = _d; nr = _nr;
    }
};

const int MAXN = 10005;

vector <edge> adj[MAXN];
int n, k, m, t;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> t;
    for (int te = 1; te <= t; te++) {
        cin >> n >> k >> m;
        while (m--) {
            int u, v, d, nr;
            cin >> u >> v >> d >> nr;
            adj[u].pb(edge(v, d, nr));
            adj[v].pb(edge(u, d, nr));
        }
        solve();
    }

    return 0;
}

