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

const int maxn=1000007;
int n,t,a[maxn],x[maxn];
bool open[maxn];
stack<int> mys;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[n-i+1]);
    scanf("%d",&t);
    int v;
    FOR(i,1,t){
        scanf("%d",&v);
        open[n-v+1]=1;
    }
    
    FOR(i,1,n)
        if(open[i] || mys.empty() || mys.top()!=a[i]){
            mys.push(a[i]);
            x[n-i+1]=-a[i];
        }else{
            mys.pop();
            x[n-i+1]=a[i];
        }
    
    if(mys.empty()){
        puts("YES");
        FOR(i,1,n) printf("%d ",x[i]);
    }else puts("NO");
    //getch();
    return 0;
}
