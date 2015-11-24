//#include <bits/stdc++.h>
//using namespace std;
//
//struct point {
//    double x, y;
//
//    point(double x = 0, double y = 0): x(x), y(y) {}
//};
//
//struct parabol {
//    double a, b, c;
//    double xl, xr;
//
//    parabol(double a = 0, double b = 0, double c = 0, double xl = 0, double xr = 0):
//        a(a), b(b), c(c), xl(xl), xr(xr) {}
//};
//
//point f(const parabol &p, const double &x) {
//    return point(x, p.a * x * x + p.b * x + p.c);
//}
//
//double calc(const parabol &p, const double &x, const point &a) {
//    point b = f(p, x);
//    return hypot(b.x - a.x, b.y - a.y);
//}
//
//double search_2(const parabol &p, const point &a, double l, double r, int rep) {
//    double ret = min(calc(p, l, a), calc(p, r, a));
//    if (rep >= 66)
//        return ret;
//
//    double lt = (2 * l + r) / 3;
//    double rt = (2 * r + l) / 3;
//    if (calc(p, lt, a) < calc(p, rt, a))
//        return min(ret, search_2(p, a, l, rt, rep + 1));
//    else
//        return min(ret, search_2(p, a, lt, r, rep + 1));
//}
//
//double search_1(const parabol &p1, const parabol &p2, double l, double r, int rep) {
//    double ret = min(search_2(p2, f(p1, l), p2.xl, p2.xr, 0), search_2(p2, f(p1, r), p2.xl, p2.xr, 0));
//    if (rep >= 66)
//        return ret;
//
//    double lt = (2 * l + r) / 3;
//    double rt = (2 * r + l) / 3;
//    if (search_2(p2, f(p1, lt), p2.xl, p2.xr, 0) < search_2(p2, f(p1, rt), p2.xl, p2.xr, 0))
//        return min(ret, search_1(p1, p2, l, rt, rep + 1));
//    else
//        return min(ret, search_1(p1, p2, lt, r, rep + 1));
//}
//
//int n;
//point v, w;
//parabol p[111];
//
//double d[111][111];
//
//int main() {
////    freopen("input.txt", "r", stdin);
//    ios::sync_with_stdio(false);
//
//    cin >> n;
//    cin >> v.x >> v.y;
//    cin >> w.x >> w.y;
//    for (int i = 1; i <= n; i++) {
//        cin >> p[i].a >> p[i].b >> p[i].c >> p[i].xl >> p[i].xr;
//    }
//
//    for (int i = 0; i <= n + 1; i++)
//        for (int j = 0; j <= n + 1; j++)
//            d[i][j] = 1e18;
//
//    d[0][n + 1] = hypot(v.x - w.x, v.y - w.y);
//    for (int i = 1; i <= n; i++) {
//        d[0][i] = search_2(p[i], v, p[i].xl, p[i].xr, 0);
//        d[i][n + 1] = search_2(p[i], w, p[i].xl, p[i].xr, 0);
//        for (int j = 1; j <= n; j++) {
//            d[i][j] = search_1(p[i], p[j], p[i].xl, p[i].xr, 0);
//            double l = max(p[i].xl, p[j].xl);
//            double r = max(p[i].xr, p[j].xr);
//            d[i][j] = min(d[i][j], search_1(p[i], p[j], l, r, 0));
//        }
//    }
//
//    for (int k = 0; k <= n + 1; k++)
//        for (int i = 0; i <= n + 1; i++)
//            for (int j = 0; j <= n + 1; j++)
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//
//
//    cout << fixed << setprecision(10) << d[0][n + 1];
//
//    return 0;
//}
