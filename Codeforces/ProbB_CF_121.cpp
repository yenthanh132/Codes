#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 100007
pii a[maxn];
int n,k,pos[maxn],res;
ll b,s[maxn],t;

bool mycmp(const pii& a, const pii& b){ return (a.fi>b.fi); }
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    scanf("%I64d",&b);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i].fi);
        a[i].se=i;
    }
    sort(a+1,a+n+1,mycmp);
    s[0]=0; for(int i=1;i<=k;i++) s[i]=s[i-1]+a[i].fi;
    res=n;
    for(int i=1;i<n;i++){
        if(i>=k) t=s[k-1]+a[i].fi; else t=s[k];
        if(t>b) res=min(res,a[i].se);
    }
    printf("%d\n",res);
    return 0;
}
    
