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

const int maxn=100007;

int a[maxn],n,d;

int main(){
   //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&d);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1; i<n; ){
        if(abs(a[i]-a[i+1])<=d){
            res++;
            i+=2;
        }else i++;
    }
    cout<<res<<endl;
    return 0;
}
