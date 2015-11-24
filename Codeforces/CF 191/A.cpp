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

const int maxn=106;

int a[maxn],n,s[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    int sum=0;
    scanf("%d",&n);
    s[0]=0;
    FOR(i,1,n){
        scanf("%d",&a[i]);
        sum+=a[i];
        s[i]=s[i-1]+a[i];
    }
    int res=-oo;
    FOR(i,1,n) FOR(j,i,n) res=max(res,sum+(j-i+1)-2*(s[j]-s[i-1]));
    cout<<res<<endl;
    return 0;
}
    
