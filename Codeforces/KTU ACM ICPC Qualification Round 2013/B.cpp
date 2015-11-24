#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

struct _point {
    double x, y;
};

_point p[5];
int t;
double S;


int main() {
    freopen("input.txt", "r", stdin);

    cin >> t;
    for (int te = 1; te <= t; te++) {
        for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
        cin >> S;
        double A = p[0].x*p[1].y + p[1].x*p[2].y + p[2].x*p[3].y + p[3].x*p[0].y
            - p[0].y*p[1].x - p[1].y*p[2].x - p[2].y*p[3].x - p[3].y*p[0].x;
        A = fabs(A) / 2.0;

        printf("Case #%d: %.2lf\n", te, (double)S / A);
    }

    return 0;
}

