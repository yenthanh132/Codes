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

const int maxn=107;

int n,x,c[maxn],a[maxn];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&x);
    FOR(i,1,n) scanf("%d",&c[i]);
    FOR(i,1,n) a[i]=c[i]*(n-i+1);
    sort(a+1,a+n+1);
    int sum=0,res;
    FOR(i,1,n){
        sum+=a[i];
        if(sum>x){
            res=i-1;
            break;
        }
    }
    if(sum<=x) res=n;
    cout<<res<<endl;
}
