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

int gcd(int a, int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

int main(){
    int T,a,b,c;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d%d",&a,&b,&c);
        if(c<=max(a,b) && c%gcd(a,b)==0) puts("YES"); else puts("NO");
    }
    return 0;
}
