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

const int maxn=57;

int dp[maxn][maxn][2],n,k;
bool free1[maxn][maxn][2];
int c1,c2;
struct state{
    int v1,v2,left;
    state(){}
    state(int a, int b, int c){
        v1=a;
        v2=b;
        left=c;
    }
};
queue<state> myq;
ll cnt[maxn][maxn][2],tohop[maxn][maxn];

#include <conio.h>
int main(){
    tohop[0][0]=1;
    FOR(i,1,50){
        tohop[i][0]=1;
        FOR(j,1,i) tohop[i][j]=(tohop[i-1][j-1]+tohop[i-1][j])%oo;
    }
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%d",&k);
    k/=50;
    c1=c2=0;
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        if(v==50) c1++; else c2++;
    }
    
    FOR(i,0,n) FOR(j,0,n) REP(k,2) dp[i][j][k]=oo;
    dp[0][0][0]=0; cnt[0][0][0]=1;
    myq.push(state(0,0,0));
    int v1,v2,d1,d2,left;
    while(!myq.empty()){
        v1=myq.front().v1; v2=myq.front().v2; left=myq.front().left;
        myq.pop();
        if(left==0){
            d1=c1-v1;
            d2=c2-v2;
            FOR(t1,0,d1) FOR(t2,0,d2) if(t1+t2>0 && t1+t2*2<=k){
                if(dp[v1+t1][v2+t2][1] > dp[v1][v2][0] + 1){
                    dp[v1+t1][v2+t2][1] = dp[v1][v2][0] + 1;
                    cnt[v1+t1][v2+t2][1] = (cnt[v1][v2][0] * tohop[d1][t1] % oo) * tohop[d2][t2] %oo;
                    myq.push(state(v1+t1,v2+t2,1));
                }else if(dp[v1+t1][v2+t2][1] == dp[v1][v2][0] +1)
                    cnt[v1+t1][v2+t2][1] = (cnt[v1+t1][v2+t2][1] + ((cnt[v1][v2][0] * tohop[d1][t1] % oo) * tohop[d2][t2] %oo )) %oo;
            }
        }else{
            d1=v1;
            d2=v2;
            FOR(t1,0,d1) FOR(t2,0,d2) if(t1+t2>0 && t1+t2*2<=k){
                if(dp[v1-t1][v2-t2][0] > dp[v1][v2][1] + 1){
                    dp[v1-t1][v2-t2][0] = dp[v1][v2][1] + 1;
                    cnt[v1-t1][v2-t2][0] = (cnt[v1][v2][1] * tohop[d1][t1] % oo) * tohop[d2][t2] %oo;
                    myq.push(state(v1-t1,v2-t2,0));
                }else if(dp[v1-t1][v2-t2][0] == dp[v1][v2][1] + 1)
                    cnt[v1-t1][v2-t2][0] = (cnt[v1-t1][v2-t2][0] + ((cnt[v1][v2][1] * tohop[d1][t1] % oo) * tohop[d2][t2] %oo )) %oo;
            }
        }
    }
    
    if(dp[c1][c2][1]==oo){
        puts("-1");
        puts("0");
    }else{
        printf("%d\n",dp[c1][c2][1]);
        printf("%I64d\n",cnt[c1][c2][1]);
    }
    
    //getch();
    return 0;
}
            
            
