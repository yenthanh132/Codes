#include <bits/stdc++.h>
using namespace std;

const int modl = 1000000000;

int n, b;
int f[2][44][44][44][44];


int main() {
    cin >> n >> b;

    f[1][1][1][1][1] = 1;
    for (int i = 1; i < n; i++) {
        int ii = i & 1;
        for (int j2 = 1; j2 <= i; j2++)
            for (int j3 = 1; j3 <= i; j3++)
                for (int j4 = 0; j4 <= i; j4++)
                    for (int j5 = 0; j5 <= i; j5++)
                        f[ii ^ 1][j2][j3][j4][j5] = 0;
        for (int j2 = 1; j2 <= i; j2++)
            for (int j3 = 1; j3 <= i; j3++)
                for (int j4 = 1; j4 <= i; j4++)
                    for (int j5 = 1; j5 <= i; j5++)
                        if (f[ii][j2][j3][j4][j5]) {
                            for (int j = 0; j <= i; j++) {
                                if (j == 0) {
                                    f[ii ^ 1][j2 + 1][j3 + 1][j4 + 1][j5 + 1] = f[ii ^ 1][j2 + 1][j3 + 1][j4 + 1][j5 + 1] + f[ii][j2][j3][j4][j5];
                                    if (f[ii ^ 1][j2 + 1][j3 + 1][j4 + 1][j5 + 1] >= modl)
                                        f[ii ^ 1][j2 + 1][j3 + 1][j4 + 1][j5 + 1] -= modl;
                                } else if (j <= j2) {
                                    f[ii ^ 1][j][j3 + 1][j4 + 1][j5 + 1] = f[ii ^ 1][j][j3 + 1][j4 + 1][j5 + 1] + f[ii][j2][j3][j4][j5];
                                    if (f[ii ^ 1][j][j3 + 1][j4 + 1][j5 + 1] >= modl)
                                        f[ii ^ 1][j][j3 + 1][j4 + 1][j5 + 1] -= modl;
                                } else if (j <= j3) {
                                    f[ii ^ 1][j2][j][j4 + 1][j5 + 1] = f[ii ^ 1][j2][j][j4 + 1][j5 + 1] + f[ii][j2][j3][j4][j5];
                                    if (f[ii ^ 1][j2][j][j4 + 1][j5 + 1] >= modl)
                                        f[ii ^ 1][j2][j][j4 + 1][j5 + 1] -= modl;
                                } else if (j <= j4) {
                                    f[ii ^ 1][j2][j3][j][j5 + 1] = f[ii ^ 1][j2][j3][j][j5 + 1] + f[ii][j2][j3][j4][j5];
                                    if (f[ii ^ 1][j2][j3][j][j5 + 1] >= modl)
                                        f[ii ^ 1][j2][j3][j][j5 + 1] -= modl;
                                } else if (j <= j5) {
                                    f[ii ^ 1][j2][j3][j4][j] = f[ii ^ 1][j2][j3][j4][j] + f[ii][j2][j3][j4][j5];
                                    if (f[ii ^ 1][j2][j3][j4][j] >= modl)
                                        f[ii ^ 1][j2][j3][j4][j] -= modl;
                                }
                            }
                        }
    }

    int ret = 0;
    if (b == 1) {
        ret = 1;
    } else if (b == 2) {
        for (int j2 = 0; j2 < n; j2++) {
            ret = ret + f[n & 1][j2][n][n][n];
            if (ret >= modl)
                ret -= modl;
        }
    } else if (b == 3) {
        for (int j2 = 0; j2 < n; j2++)
            for (int j3 = 0; j3 < n; j3++) {
                ret = ret + f[n & 1][j2][j3][n][n];
                if (ret >= modl)
                    ret -= modl;
            }
    } else if (b == 4) {
        for (int j2 = 0; j2 < n; j2++)
            for (int j3 = 0; j3 < n; j3++)
                for (int j4 = 0; j4 < n; j4++) {
                    ret = ret + f[n & 1][j2][j3][j4][n];
                    if (ret >= modl)
                        ret -= modl;
                }
    } else if (b == 5) {
        for (int j2 = 0; j2 < n; j2++)
            for (int j3 = 0; j3 < n; j3++)
                for (int j4 = 0; j4 < n; j4++)
                    for (int j5 = 0; j5 < n; j5++) {
                        ret = ret + f[n & 1][j2][j3][j4][j5];
                        if (ret >= modl)
                            ret -= modl;
                    }
    }
    cout << ret;

    return 0;
}
