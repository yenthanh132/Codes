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

const int maxn=11;
const int maxm=1007;

bool dp[2][maxn][maxn];
pii trace[maxm][maxn][maxn];
bool mark[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    string s;
    int m;
    
    cin>>s;
    reset(mark,0);
    REP(i,10) if(s[i]=='1') mark[i+1]=1;
    cin>>m;

    int flag=1;
    reset(dp,0);
    dp[0][0][0]=1;
    FOR(i,1,m){
        FOR(x,0,10) FOR(y,0,10) dp[flag][x][y]=0;
        FOR(x,0,10) FOR(y,0,10) if(dp[flag^1][x][y]) FOR(z,1,10) if(mark[z] && z!=y && z>x){
            dp[flag][z-x][z]=1;   
            trace[i][z-x][z]=pii(x,y);
        }
        flag^=1;
    }
    
    bool res=0;
    int u,v;
    FOR(x,1,10) FOR(y,1,10) if(dp[1^flag][x][y]){
        res=1;
        u=x; v=y;
    }
    
    
    if(res){
        cout<<"YES"<<endl;
        vector<int> lst; 
        FORD(i,m,1){
            pii tmp=trace[i][u][v];
            lst.pb(v);
            u=tmp.fi; v=tmp.se;
        }      
        REPD(i,sz(lst)) cout<<lst[i]<<' '; cout<<endl;
    }else cout<<"NO"<<endl;
    
    getch();
    return 0;
}
    
    

