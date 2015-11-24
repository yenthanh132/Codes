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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int n,k,a[maxn];
ll res,vright[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int T;
    scanf("%d",&T);   
    REP(tt,T){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%d",&a[i]);
        res=-oo;
        ll sum=0, mins=0, vleft=-oo;
        vright[n+1]=-oo;
        FORD(i,n,1){
            sum+=a[i];
            vright[i]=max(vright[i+1],sum-mins);
            mins=min(mins,sum);
        }
        sum=0, mins=0;
        FOR(i,1,n-k-1){
            sum+=a[i];
            vleft=max(vleft,sum-mins);
            mins=min(mins,sum);
            res=max(res, vleft + vright[i+k+1]);
        }
        printf("%lld\n",res);
    }
}
