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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 107
int a[maxn][maxn],n,m,k,list[7],f[128][maxn],res;

void floyd(){
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
}

void solve(){
    REP(id,1<<k) FOR(i,1,n) f[id][i]=oo;
    REP(i,k) f[1<<i][list[i]]=0;
    FOR(id,1,(1<<k)-1){
        FOR(i,1,n){
            vector<int> bits;
            REP(j,k) if((id>>j)&1) bits.pb(j);
            int subid;
            REP(j,(1<<bits.size())){
                subid=0;
                REP(z,bits.size()) if((j>>z)&1) subid+=1<<bits[z];
                f[id][i]=min(f[id][i],f[subid][i]+f[id^subid][i]);
            }
        }
        //////////////////
        FOR(i,1,n) FOR(j,1,n) f[id][i]=min(f[id][i],f[id][j]+a[i][j]);        
    }
    res=oo;
    FOR(i,1,n) res=min(res,f[(1<<k)-1][i]);
}
    
//#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,n) a[i][j]=(i==j)?0:oo;
    REP(i,k) scanf("%d",list+i);
    int u,v,w;
    FOR(i,1,m){
        scanf("%d%d%d",&u,&v,&w);
        a[u][v]=a[v][u]=min(a[u][v],w);
    }
    floyd();
    solve();
    printf("%d\n",res);
    //getch();
    return 0;
}
