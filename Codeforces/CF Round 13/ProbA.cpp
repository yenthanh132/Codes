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
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cal(int n){
    int s=0;
    FOR(i,2,n-1){
        int t=n;
        while(t){
            s=s+t%i;
            t/=i;
        }
    }
    return s;
}

int gcd(int a, int b){
    if(a<b) return gcd(b,a);
    else if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    int a=cal(n), b=n-2;
    cout<<a/gcd(a,b)<<'/'<<b/gcd(a,b);
    return 0;
}
