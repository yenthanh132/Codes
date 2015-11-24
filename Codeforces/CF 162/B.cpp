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
const int maxv=100000;

int n,a[maxn],dp[maxn];
int cnt,list[maxn],frac[maxn],d;
bool isprime[maxn];

void init(){
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;
    list[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) list[++cnt]=i;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int res,ans=0,v;
    init();
    FOR(i,1,n){
        v=a[i];
        d=res=0;
        for(int j=1; list[j]*list[j]<=v; j++)
            if(v%list[j]==0){
                res=max(res,dp[list[j]]+1);
                frac[++d]=list[j];
                while(v%list[j]==0) v/=list[j];
            }
        if(v>1){
            frac[++d]=v;
            res=max(res,dp[v]+1);
        }
        FOR(j,1,d) dp[frac[j]]=max(dp[frac[j]],res);
        ans=max(ans,res);
    }
    if(n==1 && a[1]==1) ans=1;
    printf("%d\n",ans);
    return 0;
}
