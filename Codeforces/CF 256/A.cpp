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

int main(){
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int a=a1+a2+a3;
    cin>>a1>>a2>>a3;
    int b=a1+a2+a3;
    int n;
    cin>>n;
    int need=0;
    if(a>0) need += (a-1)/5+1;
    if(b>0) need += (b-1)/10+1;
    if(need <= n) puts("YES");
    else puts("NO");
    return 0;
}

