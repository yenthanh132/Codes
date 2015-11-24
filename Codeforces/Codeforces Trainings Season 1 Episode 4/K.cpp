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

const int maxn=107;

int dp[maxn][10007];
int T,n,p,a[maxn],s[maxn],list[10007],c;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int find(ll v){
    int l=1, r=c,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(v==list[mid]) return mid;
        if(v<list[mid]) r=mid-1; else l=mid+1;
    }
    return -1;
}
    
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&p);
        c=0;
        for(int v=1; v*v<=p; ++v) if(p%v==0){
            list[++c]=v;
            if(p/v!=v) list[++c]=p/v;   
        }

        sort(list+1,list+c+1);
        s[0]=0;
        FOR(i,1,n) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
        
        FOR(i,0,n) FOR(j,1,c) dp[i][j]=oo;
        dp[0][1]=0;
        FOR(i,0,n-1) FOR(j,1,c) if(dp[i][j]!=oo){
            int v=list[j];
            FOR(k,i+1,n){
                int v2=s[k]-s[i];
                int pos=find(gcd(1ll*v*v2,p));
                if(pos!=-1) dp[k][pos]=min(dp[k][pos],dp[i][j]+1);
            }
        }
        int r1=0,r2;
        FOR(j,1,c) if(dp[n][j]!=oo){
            r1=list[j];
            r2=dp[n][j];
        }
        cout<<r1<<' '<<r2-1<<endl;
    }
     
    //getch();
    return 0;
}   
        
