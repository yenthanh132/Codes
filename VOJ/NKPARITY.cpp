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

const int maxn=307;

int n,a[maxn],num[maxn],res[maxn],total,list[maxn][3],c[3];
vector<int> Link[maxn];
bool ok;

void dfs(int u){
    if(ok) return;
    int v=num[u];
    list[++c[v]][v]=u;
    REP(i,sz(Link[u])){
        v=Link[u][i];
        if(num[v]==0){
            num[v]=3-num[u];
            dfs(v);
        }else if(num[v]==num[u]){
            ok=1;
            return;
        }
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        Link[x].pb(y);
        Link[y].pb(x);
    }
    ok=0;
    total=0;
    FOR(i,1,n) if(num[i]==0){
        num[i]=1;
        c[1]=c[2]=0;
        dfs(i);
        if(c[1]>c[2]) x=1; else x=2;
        FOR(j,1,c[x]) res[++total]=list[j][x];
        if(ok) break;
    }
     
    if(ok) puts("YES");
    else{
        puts("NO");
        printf("%d\n",total);
        sort(res+1,res+total+1);
        FOR(i,1,total-1) printf("%d ",res[i]);
        printf("%d\n",res[total]);
    }
    //getch();
    return 0;
}
        
