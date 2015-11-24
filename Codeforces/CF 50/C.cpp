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

const int maxn=1007;

double dp[2][maxn];
int n,k;
unsigned long long d10[20];

ll cal(ll v){
    ll V=v;
    if(v==0) return 0;
    if(v<10) return 1;
    ll res=0;
    int u=0,last;
    while(v){
        last=v%10;
        v/=10;
        u++;
    }
    FOR(i,1,u-1) res+=d10[i];
    if(last == 1) res+=V-d10[u]+1;
    else res+=d10[u];
    return res;   
}

void cal(ll l, ll r, double &p0, double &p1){
    ll cnt=r-l+1;
    ll v=cal(r)-cal(l-1);
    p1=1.0*v/cnt;
    p0=1-p1;   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    d10[0]=1; d10[1]=1;
    FOR(i,2,19) d10[i]=d10[i-1]*10;
    ll l,r;    
    double p0,p1;
    cin>>n;
    int flag=0;
    FOR(i,1,n) dp[0][i]=0;
    dp[0][0]=1;
    FOR(i,1,n){
        flag^=1;
        FOR(i,0,n) dp[flag][i]=0;
        cin>>l>>r;
        cal(l,r,p0,p1);
        FOR(j,0,i-1){
            dp[flag][j]+=dp[1^flag][j]*p0;
            dp[flag][j+1]+=dp[1^flag][j]*p1;
        }
    }
    
    cin>>k;
    int u=0;
    while(u*100<n*k) u++;
    double res=0;
    FOR(i,u,n) res+=dp[flag][i];
    printf("%0.12lf\n",res);
    
    //getch();
    return 0;
}

