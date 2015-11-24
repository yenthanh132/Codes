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

const int maxn=13;

double x[maxn],y[maxn];
bool a[maxn][maxn];
int color[maxn];
int res,used[10],n,m;
bool mark[maxn];

double sqr(double a){return a*a;}

void DFSInit(int u){
    mark[u]=1;
    m++;
    FOR(v,1,n) if(!mark[v] && a[u][v]) DFSInit(v);
}

void DFS(int u, int c){
    FOR(v,1,n) if(a[u][v] && color[v]==color[u]) return;
    
    int max_color=0;
    FOR(x,1,5) if(used[x]) max_color++;
    if(max_color>=res) return;
    
    if(c==m){
        res=min(res,max_color);
        return;
    }    
    FOR(v,1,n) if(a[u][v] && color[v]==0){
        FOR(x,1,5) if(x!=color[u]){
            color[v]=x;
            used[x]++;
            DFS(v,c+1);
            used[x]--;
        }
        color[v]=0;   
    }
    
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    int tt=0;
    int ans;
    while(n){
        FOR(i,1,n) cin>>x[i]>>y[i];
        reset(a,0);
        FOR(u,1,n) FOR(v,1,n) if(u!=v && sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]))-1e-9<=20)
            a[u][v]=1;
        reset(used,0);
        
        reset(mark,0);
        reset(color,0);
        ans=0;
        FOR(i,1,n) if(!mark[i]){
            m=0;
            DFSInit(i);
            color[i]=1; used[1]=1;
            res=oo;
            DFS(i,1);
            ans=max(ans,res);
            used[1]=0;  
            color[i]=0;          
        }
        printf("The towers in case %d can be covered in %d frequencies.\n",++tt,ans);
        cin>>n;   
    }

    //getch();
    return 0;
}
