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

const int MAX = 200005;

int a[MAX], b1[MAX], b2[MAX], n, m, k;
vector <int> res1, res2;

void Merge1() {
	int i = 1, j = n + 1;
	k = 0;
	while (i <= n || j <= m)
		if (i > n)
			b1[++k] = j++;
		else if (j > m)
			b1[++k] = i++;
		else if (a[i] == a[j])
			b1[++k] = i++;
		else
			b1[++k] = j++;
	
	for (int i = m, flag = 1; i > 0; --i)
		if (a[b1[i]] == flag)
			res1.push_back(i), flag ^= 1;
	reverse(res1.begin(), res1.end());
}

void Merge2() {
	int i = 1, j = n + 1;
	k = 0;
	while (i <= n || j <= m)
		if (i > n)
			b2[++k] = j++;
		else if (j > m)cq
			b2[++k] = i++;
		else if (a[i] == a[j])
			b2[++k] = j++;
		else
			b2[++k] = i++;
	
	for (int i = m, flag = 1; i > 0; --i)
		if (a[b2[i]] == flag)
			res2.push_back(i), flag ^= 1;
	reverse(res2.begin(), res2.end());
}


int main() {
	//freopen("test.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	FOR(i, 1, m) scanf("%d", &a[n + i]);
	m += n;
	
	Merge1(); Merge2();
	
	if (sz(res1) < sz(res2)) {
		FOR(i, 1, m) printf("%d ", b1[i]); printf("\n");
		printf("%d\n", sz(res1));
		for (int i = 0; i < sz(res1); ++i)
			printf("%d ", res1[i]);
	} else {
		FOR(i, 1, m) printf("%d ", b2[i]); printf("\n");
		printf("%d\n", sz(res2));
		for (int i = 0; i < sz(res2); ++i)
			printf("%d ", res2[i]);
	}
}
