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

const int maxn = 107;

int d[2][maxn],n,m;
double c[2][maxn];
vector<int> a[maxn];
bool free1[maxn];

void bfs(int id, int s){
    queue<int> myqueue;
    d[id][s]=0; c[id][s]=1;
    reset(free1,1);
    myqueue.push(s); free1[s]=0;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(free1[v]){
                free1[v]=0;
                myqueue.push(v);
                d[id][v]=d[id][u]+1;
                c[id][v]=c[id][u];
            }else if(d[id][v]==d[id][u]+1) c[id][v]+=c[id][u];
        }
    }
}
    
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    REP(i,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
    }
    bfs(0,1); bfs(1,n);
    double res=1;
    FOR(i,2,n-1) if(d[0][i]+d[1][i]==d[0][n]){
        res=max(res,2.0*(c[0][i]*c[1][i])/c[0][n]);
        //printf("%d %0.12lf\n",i,2.0*(c[0][i]*c[1][i])/c[0][n]);
    }
    printf("%0.12lf",res);
    //getch();
    return 0;
}
    
