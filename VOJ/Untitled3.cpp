#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>

#define lfo(i, a, b) for(int i = a; i <= b; ++i)
#define rfo(i, a, b) for(int i = a; i >= b; --i)
#define rel(i, a, b) for(int i = a; i < b; ++i)
#define rer(i, a, b) for(int i = a; i > b; --i)
#define fore(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define rofe(i, c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); ++i)
#define reset(c, k) memset(c, k, sizeof(c))
#define length(c) int((c).length())
#define size(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define lob lower_bound
#define upb upper_bound
#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define ins insert
#define ers erase
#define mmap multimap
#define mset multiset
#define st1 first
#define nd2 second
#define mp make_pair

#define _min(a, b) ((a) < (b) ? (a) : (b))
#define _max(a, b) ((a) < (b) ? (b) : (a))
#define _abs(a) ((a) < 0 ? -(a) : (a))

using namespace std;

#define maxN 1005
#define maxM 111111

typedef double db;

typedef unsigned int uint;

typedef long long ll;

typedef unsigned long long ull;

typedef pair <int, int> prii;

typedef vector <int> vi;

int n, m, cl[maxN], kc[maxN];

int head[maxN], fr[maxM], to[maxM], ts[maxM];

prii adj[maxM];

void inp() {
    scanf("%d%d", &n, &m);
    reset(head, 0);
    lfo(i, 1, m) {
        scanf("%d%d%d", fr + i, to + i, ts + i);
        ++head[fr[i]];
    }
}

void MakeGraph() {
    int u, v = 1, w;
    lfo(i, 1, n) {
        u = head[i];
        head[i] = v;
        v += u;
    }
    head[0] = 1, head[n + 1] = v;
    lfo(i, 1, m) {
        u = fr[i], v = to[i], w = ts[i];
        adj[head[u]++] = mp(w, v);
    }
    rfo(i, n, 1) head[i] = head[i - 1];
}

int h[maxN], hn, pos[maxN];

inline void init() {
    hn = 0;
    h[0] = 0, kc[0] = -1;
}

inline void up(int k) {
    int v = h[k];
    while (kc[v] < kc[h[k >> 1]]) {
        h[k] = h[k >> 1], pos[h[k]] = k;
        k >>= 1;
    }
    h[k] = v, pos[v] = k;
}

inline void down(int k) {
    int v = h[k];
    while ((k << 1) <= hn) {
        int l = k << 1; l += l < hn && kc[h[l + 1]] < kc[h[l]];
        if (kc[v] <= kc[h[l]]) break;
        h[k] = h[l], pos[h[k]] = k;
        k = l;
    }
    h[k] = v, pos[v] = k;
}

inline void push(int v) {
    h[++hn] = v, pos[v] = hn;
    up(hn);
}

inline int get() {
    int res = h[1];
    h[1] = h[hn--], pos[h[1]] = 1;
    down(1);
    return res;
}

int dij(int xp) {
    init(), reset(cl, 0);
    rel(cur, head[xp], head[xp + 1]) {
        int v = adj[cur].nd2, w = adj[cur].st1;
        switch(cl[v]) {
            case 0:
                kc[v] = w, cl[v] = 1;
                push(v); break;
            case 1:
                if (kc[v] > w) {
                    kc[v] = w;
                    up(pos[v]);
                }
                break;
        }
    }
    while (hn > 0) {
        int u = get(); cl[u] = 2;
        if (u == xp) return kc[xp];
        rel(cur, head[u], head[u + 1]) {
            int v = adj[cur].nd2, w = adj[cur].st1;
            switch(cl[v]) {
                case 0:
                    kc[v] = kc[u] + w, cl[v] = 1;
                    push(v); break;
                case 1:
                    if (kc[v] > kc[u] + w) {
                        kc[v] = kc[u] + w;
                        up(pos[v]);
                    }
                    break;
            }
        }
    }
    return -1;
}

void solve() {
    MakeGraph();
    lfo(i, 1, n)
        printf("%d\n", dij(i));
}

int main() {
    freopen("test.txt", "r", stdin);
    freopen("TOURS.OUT", "w", stdout);
    srand(time(NULL));
    int t;
    scanf("%d", &t);
    lfo(i, 1, t) {
        inp();
        solve();
    }
    cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
