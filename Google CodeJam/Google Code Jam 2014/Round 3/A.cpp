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

int a[maxn],N,p,q,r,s;
ll ls[maxn],rs[maxn];

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        printf("Case #%d: ",tt);
        scanf("%d%d%d%d%d",&N,&p,&q,&r,&s);
        ls[0]=0;
        FOR(i,1,N) a[i]=(1ll*(i-1)*p+q)%r+s, ls[i]=ls[i-1]+a[i];
        rs[N+1]=0;
        FORD(i,N,1) rs[i]=rs[i+1]+a[i];
        double res=0;
        FOR(j,1,N){
            ll maxv=rs[j+1],t;
            ll sum=ls[j];
            int left=0, right=j-1, mid, pos=0;
            while(left<=right){
                mid=(left+right)/2;
                if(ls[mid]*2<=sum){
                    pos=mid;
                    left=mid+1;
                }else right=mid-1;
            }
            t=max(maxv, max(ls[pos],ls[j]-ls[pos]));
            res=max(res,1.0*(ls[N]-t)/ls[N]);
            if(pos+1<j){
                ++pos;
                t=max(maxv, max(ls[pos],ls[j]-ls[pos]));
                res=max(res,1.0*(ls[N]-t)/ls[N]);
            }

        }
        printf("%0.9lf\n",res);
    }
}
