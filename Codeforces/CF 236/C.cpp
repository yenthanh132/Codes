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

const int maxn=2007;
const int LEN=50;
int a[maxn][maxn],n,mys[maxn],last,num[maxn],low[maxn],cnt,cnt_com;
vector<int> e[maxn];
bool free1[maxn];

void DFS(int u){
    num[u]=low[u]=++cnt;
    mys[++last]=u;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(!free1[v]) continue;
        if(num[v]==0){
            DFS(v);
            low[u]=min(low[u],low[v]);   
        }else low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        cnt_com++;
        do{
            v=mys[last--];  
            free1[v]=0; 
        }while(v!=u);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n){
        scanf("%d",&a[i][j]);
        if(a[i][j]>0) e[j].pb(i);
    }
    
    reset(num,0); cnt=0; cnt_com=0; last=0;
    reset(free1,1);
    FOR(i,1,n) if(num[i]==0)  DFS(i);   
    if(cnt_com==1)
        printf("YES");
    else 
        printf("NO");
    return 0;
}
    

