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

int a[maxn];
int dp[1<<20],n;
    

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    REP(tt,T){
        cin>>n;
        int k,v;
        reset(a,0);
        FOR(u,1,n){
            cin>>k;
            a[u]=1<<u-1;
            REP(i,k){
                cin>>v;
                a[u]|=1<<v-1;
            }   
        }
        
        dp[0]=0;
        FOR(i,1,(1<<n)-1) dp[i]=oo;
        REP(id,1<<n) if(dp[id]!=oo){
            int id2;
            FOR(u,1,n){
                id2=id | a[u];
                dp[id2]=min(dp[id2],dp[id]+1);   
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
        
    }    
}
