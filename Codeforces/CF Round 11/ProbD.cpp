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

const int maxn = 19;

ll f[1<<19][maxn],res;
int n,m;
bool a[maxn][maxn];

int firstpop(int v){
    int i;
    for(i=0; ((v>>i)&1)==0; i++);
    return i;
}

int countpop(int v){
    int res=0;
    REP(i,n) if((v>>i)&1) res++;
    return res;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int u,v;
    cin>>n>>m;
    reset(f,0); reset(a,0);
    REP(i,m){
        cin>>u>>v;
        u--; v--;
        a[u][v]=a[v][u]=1;
        f[(1<<u) | (1<<v)][max(u,v)]++;
    }
    res=0;
    REP(id,1<<n){
        if(countpop(id)<2) continue;
        u=firstpop(id);
        if(countpop(id)>2){
            for(v=u+1; v<n; v++) if(((id>>v)&1) && a[u][v]) res+=f[id][v];
        }
        FOR(i,u+1,n-1) if((id>>i)&1)
            FOR(j,u+1,n-1) if(!((id>>j)&1) && a[i][j]) f[id | (1<<j)][j]+=f[id][i];
    }
    cout<<res/2<<endl;
    //getch();
    return 0;
}
                   
        
        
