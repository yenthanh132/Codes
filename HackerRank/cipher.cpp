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
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int n,k,a[maxn];
char s[maxn];

int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int v=0;
    for(int i=1; i<=n; ++i){
        a[i] = v^(s[i]-'0');
        v ^= a[i];
        if(i>=k) v ^= a[i-k+1];
    }
    for(int i=1; i<=n; ++i) printf("%d",a[i]);
    printf("\n");
}
