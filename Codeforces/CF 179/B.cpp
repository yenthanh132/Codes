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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#include <conio.h>

const int maxn=507;

ll a[maxn][maxn];
int n,x[maxn];
ll d[maxn],d2[maxn];
bool marked[maxn];
bool free1[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) scanf("%I64d",&a[i][j]);
    FOR(i,1,n) scanf("%d",&x[i]);
    
    vector<ll> list;
    reset(marked,0);
    FORD(i,n,1){
        int z=x[i],u;
        ll minv;
        FOR(i,1,n) d[i]=oo;
        d[z]=0;
        reset(free1,1);
        marked[z]=1;
        while(1){
            
            u=-1; minv=oo;
            FOR(i,1,n) if(marked[i] && free1[i] && d[i]<minv){
                minv=d[i];
                u=i;
            }
            if(u==-1) break;
            free1[u]=0;
            FOR(v,1,n) if(marked[v] && free1[v] && d[v]>d[u]+a[u][v])
                d[v]=d[u]+a[u][v];
        }
        
        FOR(i,1,n) d2[i]=oo;
        d2[z]=0;
        reset(free1,1);
        while(1){
            u=-1; minv=oo;
            FOR(i,1,n) if(marked[i] && free1[i] && d2[i]<minv){
                minv=d2[i];
                u=i;
            }
            if(u==-1) break;
            free1[u]=0;
            FOR(v,1,n) if(marked[v] && free1[v] && d2[v]>d2[u]+a[v][u])
                d2[v]=d2[u]+a[v][u];
        }
        
        FOR(x,1,n) if(marked[x]){
            a[x][z]=d2[x];
            a[z][x]=d[x];
        }
        FOR(x,1,n) if(marked[x]) FOR(y,1,n) if(x!=y && marked[y])
            a[x][y]=min(a[x][y],d2[x]+d[y]);
            
        ll res=0;
        FOR(x,1,n) if(marked[x]) FOR(y,1,n) if(x!=y && marked[y]) res+=a[x][y];
        list.pb(res);
    }
        
    REPD(i,n) printf("%I64d ",list[i]);    
    //getch();
    return 0;
}
