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

const int maxn=200007;

int mypow(int base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo; else return t;
}

int n,a[maxn],cnt[101];

int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        int res=mypow(2,n)-1,res2=n;
        FOR(d,-99,+99){
            reset(cnt,0);
            FOR(i,1,n){
                int v=a[i]-d;
                if(0<=v && v<=100){
                    res2+=cnt[v];
                    if(res2>oo) res2-=oo;
                    cnt[a[i]]+=cnt[v];
                    if(cnt[a[i]]>oo) cnt[a[i]]-=oo;
                }
                cnt[a[i]]++;
            }
        }
        res=(res-res2+oo)%oo;
        printf("%d\n",res);
    }
}

