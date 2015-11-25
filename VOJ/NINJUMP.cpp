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
int n,x,y,u,v,h[maxn],dp[maxn][maxn][maxn];

void update(int &u, int v){
    u=min(u,v);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%d%d%d%d",&x,&y,&u,&v);
    FOR(i,1,n) scanf("%d",&h[i]), h[i]+=3;
    int maxh=0;
    FOR(i,1,n) maxh=max(maxh,h[i]);
    FOR(i,1,n) REP(j,maxh) REP(k,maxh) dp[i][j][k]=oo;
    dp[1][0][0]=0;
    int t,hj,hk,hi;
    FOR(i,1,n-1) REP(j,maxh) REP(k,maxh) if(dp[i][j][k]!=oo){
        t=dp[i][j][k];
        if(j==0) hi=h[i]-1; else hi=h[i];
        if(j==0) hj=h[i]-1; else hj=j;
        hk=max(k,hi);
        //long jump right
        if(hj>h[i+1]){
            //with high jump left
            if(k==0){
                update(dp[i+1][hj][0],t + y + max(hi-(h[i+1]-1),0)*u);
                update(dp[i+1][0][0],t + y + max(hi-(h[i+1]-2),0)*u);
            }
            //with long jump left
            update(dp[i+1][hj][hk],t + y + v);
            update(dp[i+1][0][hk], t + y + v);
            if(h[i+1]-1>hk) update(dp[i+1][hj][0], t + y + v);
            if(h[i+1]-2>hk) update(dp[i+1][0][0], t + y + v);
        }
        //high jump right
        if(j==0){
            //with high jump left
            if(k==0) update(dp[i+1][0][0], t + max(h[i+1]-(h[i]-1),0)*x + max((h[i]-1)-(h[i+1]-2),0)*u);            
            //with long jump left
            update(dp[i+1][0][hk], t + max(h[i+1]-(h[i]-1),0)*x + v);
            if(h[i+1]-2>hk) update(dp[i+1][0][0], t + max(h[i+1]-(h[i]-1),0)*x + v);
        }
    }
    printf("%d\n",dp[n][0][0]);
    //getch();
    return 0;
} 
            
