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

int a[100007];

#include <conio.h>
int main(){
    int n;
    cin>>n;
    if(n==1) puts("1");
    else if((n/2)%2) puts("-1");
    else{
        a[n/2+1]=n/2+1;
        for(int i=1; i<=n/2; i+=2){
            a[i]=i+1;
            a[i+1]=n-i+1;
            a[n-i+1]=n-i;
            a[n-i]=i;
        }
        FOR(i,1,n) printf("%d ",a[i]);
    }
    return 0;
}
