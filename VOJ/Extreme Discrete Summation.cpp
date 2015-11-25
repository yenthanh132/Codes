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

typedef unsigned long long ll;
typedef pair<int, int> pii;

int cnt[11],n,list[11],m;
ll gt[11],dp[15][10][100];

ll mypow(ll v0, ll n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=t*t;
    if(n&1) return t*v0; else return t;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gt[0]=gt[1]=1; FOR(i,2,8) gt[i]=gt[i-1]*i;
    scanf("%d",&n);
    while(n){
        int u;
        double v;
        reset(cnt,0);
        FOR(i,1,n){
            scanf("%lf",&v);
            u=int(v*10+1e-9)%10;
            cnt[u]++;
        }
        m=0;
        FOR(i,0,9) if(cnt[i]) list[++m]=i;
        reset(dp,0);
        dp[0][0][0]=1;
        FOR(i,1,m) FOR(j,0,8) FOR(v,0,99){
            FOR(k,0,j) 
                if(v-list[i]*k>=0)
                    dp[i][j][v]+=dp[i-1][j-k][v-list[i]*k] * 
                    mypow(cnt[list[i]],k) * (gt[j]/gt[k]/gt[j-k]);
        }
        ll res=0;
        FOR(v,0,99) res+=(v/10) * dp[m][8][v];
        printf("%llu\n",res);
        scanf("%d",&n);
    }
//    getch();
    return 0;
}
