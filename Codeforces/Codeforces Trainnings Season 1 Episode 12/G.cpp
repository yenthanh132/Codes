//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define pb push_back
//#define sz(a) int(a.size())
//#define sqr(x) (x)*(x)
//#define reset(a, b) memset(a, b, sizeof(a))
//#define oo 1000000007
//
//typedef pair<int, int> pii;
//typedef long long ll;
//
//const char c[4] = { '-', '|', '\\', '/' };
//const int b[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };
//
//string a[15];
//int n, m;
//
//bool inside(int x, int y) {
//    return x >= 0 && y >= 0 && x < n && y < m;
//}
//
//void proc(int x, int y, int d) {
//    while (inside(x, y) && a[x][y] == c[d]) {
//        a[x][y] = '.';
//        x += b[d][0]; y += b[d][1];
//    }
//}
//
//string solve() {
//    int cnt = 0;
//    for (int i = 0; i < n; i++)
//    for (int j = 0; j < m; j++) {
//        if (a[i][j] == '.') continue;
//        cnt++;
//        if (cnt > 1) return "INCORRECT";
//        if (a[i][j] == '\\') {
//            proc(i, j, 2);
//        }
//        else if (a[i][j] == '/') {
//            proc(i, j, 3);
//        }
//        else if (a[i][j] == '-') {
//            proc(i, j, 0);
//        }
//        else {
//            proc(i, j, 1);
//        }
//    }
//    if (cnt == 1) return "CORRECT";
//    return "INCORRECT";
//}
//
//int main() {
////    freopen("input.txt", "r", stdin);
//
//    ios::sync_with_stdio(0);
//    int nT; cin >> nT;
//    while (nT--) {
//        cin >> n >> m;
//        for (int i = 0; i < n; i++) cin >> a[i];
//        cout << solve() << '\n';
//    }
//
//    return 0;
//}
//
