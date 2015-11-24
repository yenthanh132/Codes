#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <numeric>
#include <algorithm>
#define MX 400005
using namespace std;

struct Node {
	int l, r, pardp;
	Node *par, *sLink;
	map <char, Node*> chd;
	bool isLeaf;
     Node() {
		l = r = pardp = 0;
		par = sLink = NULL;
		chd.clear();
	}
	int len() {
		return r - l;
	}
	int depth() {
		return pardp + len();
	}
	bool inEdge(int pos) {
		return pos >= pardp && pos < depth();
	}
	void setEdge(Node *child, int l, int r, char *S) {
		child -> par = this;
		child -> pardp = depth();
		chd[S[l]] = child;
		child -> l = l, child -> r = r;
		isLeaf = false;
	}
	void print(char *S) {
		for (int i = l; i < r; i++) putchar(S[i]);
		puts("");
	}
};
char str[MX];
long long cnt[MX], val[MX];
int F[MX];
struct STree {
	Node *root, *needSLink, *cur;
	int jj, m, size;
	long long ans;
	bool needWalk;
	vector <Node> nodes;
	char *S;
	STree(char *str) {
		m = strlen(str);
		S = str;
		nodes.reserve(m * 2 + 10);
		jj = 1, size = 0;
		root = newNode();
		cur = newNode();
		root -> setEdge(cur, 0, m, S);
		needSLink = NULL;
		needWalk = true;
		for (int i = 0; i < m - 1; i++) extend(i);
	}
	Node *newNode() {
		nodes.push_back(Node());
		return &nodes[size++];
	}
	Node *walk_down(Node *c, int j, int i) {
		if (i - j + 1> 0)
		for (int h = j + c -> depth(); !c -> inEdge(i - j); h += c -> len())
		c = c -> chd[S[h]];
		return c;
	}
	void addSLink(Node *c) {
		if (needSLink) needSLink -> sLink = c;
		needSLink = NULL;
	}
	void extend(int i) {
		char c = S[i + 1];
		Node *leaf, *split;
		int k, pos;
		for (; jj <= i + 1; jj++) {
			if (needWalk) {
				if (!cur -> sLink && cur -> par) cur = cur -> par;
				cur = (cur -> sLink) ? cur -> sLink : root;
				cur = walk_down(cur, jj, i);
			}
			needWalk = true;
			k = i + 1 - jj;
			if (cur -> depth() == k) {
				addSLink(cur);
				if (cur -> chd[c]) {
					cur = cur -> chd[c];
					needWalk = false;
					break;
				}
				else {
					leaf = newNode();
					cur -> setEdge(leaf, i + 1, m, S);
				}
			}
			else {
				pos = cur -> l + k - cur -> pardp;
				if (S[pos] == c) {
					addSLink(cur);
					needWalk = false;
					break;
				}
				else {
					leaf = newNode();
					split = newNode();
					cur -> par -> setEdge(split, cur -> l, pos, S);
					split -> setEdge(cur, pos, cur -> r, S);
					split -> setEdge(leaf, i + 1, m, S);
					addSLink(split);
					if (split -> depth() == 1) split -> sLink = root;
					else needSLink = split;
					cur = split;
				}
			}
		}
	}
	void print(Node *c, int dp = 0) {
		for (int i = 0; i < dp; i++) printf("\t");
		c -> print(S);
		for (map <char, Node*> :: iterator it = c -> chd.begin(); it !=
		c -> chd.end(); it++) print(it -> second, dp + 1);
	}
     int calc(Node *c) {
          if (c -> chd.empty()) {
               cnt[1] += c -> len() - 1;
               return 1;
          }
          int ret = 0;
          for (map <char, Node*> :: iterator it = c -> chd.begin(); it != c -> chd.end(); it++) {
               ret += calc(it -> second);
          }
          cnt[ret] += c -> len();
          return ret;
     }
};
main() {
     freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
     int i, f, Q, N, T;
     for (scanf("%d", &T); T--; ) {
          scanf("%s", str);
          N = strlen(str);
          for (i = 0; i < N + 5; i++) cnt[i] = 0;
          str[N] = '$';
          str[N + 1] = 0;
          STree t(str);
          t.calc(t.root);
          val[N + 1] = 0;
          for (i = N; i >= 0; i--) {
                    val[i] = val[i + 1] + cnt[i] * i;
          }
          for(scanf("%d", &Q); Q--; ) {
               scanf("%d", &f);
               printf("%lld\n", val[f]);
          }
     }
}
