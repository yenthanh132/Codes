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

const int maxn=27;

int x[maxn],a[maxn],b[maxn],d[maxn],dp[maxn],f[maxn];
bool free1[maxn],found;
int n;

bool checkrev(){
    dp[n]=1;
    FORD(i,n-1,1){
        dp[i]=1;
        FOR(j,i+1,n) if(d[i]>d[j]) dp[i]=max(dp[i],dp[j]+1);
        if(dp[i]!=b[i]) return 0;
    }
    return 1;
}

void duyet(int i){
    if(i>n){
        if(checkrev()){
            found=1;
            FOR(j,1,n) x[j]=d[j];
        }
        return;
    }
    if(found) return;
    int t=0;
    FOR(v,1,n) if(free1[v]){
        if(found) break;
        d[i]=v;
        f[i]=1;
        if(v<a[i] || v<b[i]) continue;
        FOR(j,1,i-1) if(d[j]<d[i]) f[i]=max(f[i],f[j]+1);
        free1[v]=0;
        dp[i]=1;
        bool ok=1;
        FORD(j,i-1,1){
            dp[j]=1;
            FOR(z,j+1,i) if(d[j]>d[z]) dp[j]=max(dp[j],dp[z]+1);
            if(dp[j]>b[j]) {
                ok=0;
                break;
            }
        }
        if(ok && f[i]==a[i]) duyet(i+1);
        free1[v]=1;
    }
}

#include <conio.h>
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-out.out","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        FOR(i,1,n) scanf("%d",&b[i]);
        found=0; reset(free1,1);
        duyet(1);
        printf("Case #%d:",tt);
        FOR(i,1,n) printf(" %d",x[i]);
        puts("");
    }    
    //getch();
    return 0;
}
