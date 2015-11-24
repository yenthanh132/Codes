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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1005;

vector <int> a[MAXN];
int n, res;

void Try(int lo, int hi, int x) {
	if (lo == hi) return;
	int mid = (lo + hi) >> 1;
	for (int i = lo; i <= mid; ++i)
		a[x].push_back(i);
	Try(lo, mid, x + 1);
	Try(mid + 1, hi, x + 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	Try(1, n, 1);
	
	for (int i = 1; i <= n; ++i)
		if (sz(a[i]) > 0) res = i;
		
	printf("%d\n", res);
	for (int i = 1; i <= res; ++i) {
		printf("%d ", sz(a[i]));
		for (int j = 0; j < sz(a[i]); ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
