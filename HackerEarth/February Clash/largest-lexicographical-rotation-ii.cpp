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
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[4000007];
int n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",s); n=strlen(s);
    int res = 0, p = 1, l = 0;
    while (p < n && res + l + 1 < n) {
        char c1 = s[res + l], c2 = s[(p + l) % n];
        if (c1 == c2) ++l;
        else if (c1 > c2) p += l + 1, l = 0;
        else if (c1 < c2) res = max(res + l + 1, p), p = res + 1, l = 0;
    }
    for(int i=res; i<n; ++i) printf("%c",s[i]);
    for(int i=0; i<res; ++i) printf("%c",s[i]);
}

