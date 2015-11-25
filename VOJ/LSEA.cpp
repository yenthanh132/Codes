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

const int maxn = 2007;
char a[maxn][maxn];
int mystack[maxn],last,m,n,h[maxn],v[maxn],w;
ll res,cnt[maxn],dp[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    reset(h,0);
    res=0;
    FOR(i,1,m){
        last=1; mystack[1]=0;
        v[0]=dp[0]=cnt[0]=0;
        FOR(j,1,n){
            res+=1ll*i*j*(i+1)*(j+1)/4;
            if(j>1 && a[i][j-1]!=a[i][j]){
                last=1;
                v[j-1]=cnt[j-1]=dp[j-1]=0;
                mystack[1]=j-1;
            }
            if(i>1 && a[i][j]==a[i-1][j]) h[j]++; else h[j]=1;
            v[j]=h[j];
            while(v[mystack[last]]>=v[j]) last--;
            w=j-mystack[last]; 
            dp[j]=(1ll*w*(w+1)/2) * (1ll*h[j]*(h[j]+1)/2);
            dp[j]+=dp[mystack[last]] + cnt[mystack[last]]*w;
            cnt[j]=cnt[mystack[last]] + 1ll*w*h[j]*(h[j]+1)/2;
            res-=dp[j];
            mystack[++last]=j;
        }
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
            
            
