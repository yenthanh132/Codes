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

const int maxn=407;

int m,n,k,s[maxn],col[maxn];
char a[maxn][maxn];
vector<int> list[26];
ll res;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) scanf("%s",a[i]+1);
    
    res=0;
    s[0]=0;
    FOR(i1,1,m-1){
        reset(col,0);
        FOR(j,1,n) if(a[i1][j]=='a') col[j]++;
        
        FOR(i2,i1+1,m){
            REP(i,26) list[i].clear();
            FOR(j,1,n){
                if(a[i2][j]=='a') col[j]++;
                s[j]=s[j-1]+col[j];
                if(a[i1][j]==a[i2][j]) list[a[i1][j]-'a'].pb(j);
            }
            REP(i,26){
                int x=0;
                REP(y,sz(list[i])){
                    while(x<=y && s[list[i][y]]-s[list[i][x]-1]>k) x++;
                    res+=max(y-x,0);
                }
            }
        }
    }
    
    cout<<res<<endl;
    return 0;
}
