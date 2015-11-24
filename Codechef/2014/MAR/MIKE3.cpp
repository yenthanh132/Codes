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
 
const int maxm=20;
const int maxn=20007;
vector<int> arr[maxn];
bool match[maxm][maxm];
bool mark[1<<maxm];
int n,m;
 
int cntbit(int mask){
    int res=0;;
    REP(i,m) if((mask>>i)&1) ++res;
    return res;
}
 
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    
    
    REP(i,m){
        int k,v;
        scanf("%d",&k);
        REP(j,k){
            scanf("%d",&v);   
            arr[v].pb(i);
        }   
    }
    reset(match,1);
    FOR(v,1,n)
        REP(j,sz(arr[v]))
            REP(k,sz(arr[v]))
                match[arr[v][j]][arr[v][k]]=0;  
    int res=1;
    REP(i,m) mark[1<<i]=1;
    REP(mask,1<<m) if(mark[mask]){
        
        res=max(res,cntbit(mask));
        REPD(i,m) if(((mask>>i)&1)==0 && !mark[mask|(1<<i)]){
            bool ok=1;
            REP(j,m) if(((mask>>j)&1) && !match[i][j]){
                ok=0;
                break;
            }
            if(ok) mark[mask|(1<<i)]=1;            
        }else if(((mask>>i)&1)==1) break;
    }
    cout<<res<<endl;
}
