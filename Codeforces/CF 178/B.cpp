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

const int maxv=207;
const int maxn=107;
bool dp[maxn][maxv][maxv];
int n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    int t,w;
    reset(dp,0);
    dp[0][0][0]=1;
    cin>>n;
    FOR(i,1,n){
        cin>>t>>w;
        FOR(x,0,200) FOR(y,0,200)
            if(dp[i-1][x][y]){
                dp[i][x+t][y]=1;
                if(y+w<=200) dp[i][x][y+w]=1;
            }
    }
    int res=oo;
    bool ok;
    FOR(x,1,200){
        ok=0;
        FOR(y,0,x) if(dp[n][x][y]){
            ok=1;
            break;
        }
        if(ok){
            res=x;
            break;
        }
    }
    cout<<res<<endl;
    
    //getch();
    return 0;
}
