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

int dp[1<<10][10][4], n;
vector<int> a[10][4];
pii p[10];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    REP(i,n) cin>>p[i].fi>>p[i].se;
    REP(i,n) REP(j,n) if(p[i].fi==p[j].fi || p[i].se==p[j].se)
        if(p[i].fi==p[j].fi)
            if(p[i].se<p[j].se) a[i][0].pb(j);
            else a[i][2].pb(j);
        else
            if(p[i].fi<p[j].fi) a[i][1].pb(j);
            else a[i][3].pb(j);
    
    //init;
    reset(dp,0);
    REP(i,n) if(p[i].fi==0 || p[i].se==0)
        if(p[i].fi==0) 
            if(p[i].se>0) dp[1<<i][i][0]++;
            else dp[1<<i][i][2]++;
        else
            if(p[i].fi>0) dp[1<<i][i][1]++;
            else dp[1<<i][i][3]++;
            
    int z;
    REP(i,1<<n)
        REP(j,n) if((i>>j)&1)
            REP(k,4) if(dp[i][j][k])
                REP(kt,4) if(kt!=k)
                    REP(ii,sz(a[j][kt])){
                        z=a[j][kt][ii]; 
                        if((i>>z)&1) continue;
                        dp[i+(1<<z)][z][kt]+=dp[i][j][k];
                    }
    
    //get result                
    int res=0,k;
    REP(i,n) if(p[i].fi==0 || p[i].se==0){
        if(p[i].fi==0) 
            if(p[i].se>0) k=2;
            else k=0;
        else
            if(p[i].fi>0) k=3;
            else k=1;
        REP(kt,4) if(kt!=k) res+=dp[(1<<n)-1][i][kt];
    }
    
    printf("%d\n",res);
    //getch();
    return 0;
}
        

    
        
            
        

