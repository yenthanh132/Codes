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

const int maxn=35;
const int maxv=1007;

int n,a[maxn][maxn],p[maxn],c1,c2,mX[maxv],mY[maxv],first[maxn],last[maxn],dis[maxv];
vector<int> e[maxv];

bool findpath(){
    queue<int> myq;
    FOR(i,1,c1) if(mX[i]==0){
        dis[i]=0;
        myq.push(i);
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myq.empty()){
        u=myq.front(); myq.pop();
        REP(i,sz(e[u])){
            v=e[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) myq.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mY[v]=u;
            mX[u]=v;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}


int solve(int s){
    int plus=0;
    FOR(i,1,n) if(i!=s && a[s][i]==2) plus++;
    FOR(i,1,n) if(i!=s && p[s]+plus<p[i]) return 0;
    c1=c2=0;
    FOR(i,1,n-1) FOR(j,i+1,n) if(a[i][j]==2 && i!=s && j!=s) c1++;
    first[0]=last[0]=0;
    FOR(i,1,n){
        first[i]=last[i-1]+1;
        last[i]=last[i-1];
        if(i==s) continue;
        FOR(j,1,n) if(i!=j && a[i][j]==2 && j!=s){
            if(last[i]-first[i]+1+p[i]>=p[s]+plus) break;
            c2++;
            last[i]++;
        }
    }
    FOR(i,1,c1) mX[i]=0, e[i].clear();
    FOR(i,1,c2) mY[i]=0;
    
    int it=0;
    FOR(i,1,n-1) FOR(j,i+1,n) if(a[i][j]==2 && i!=s && j!=s){
        ++it;
        FOR(z,first[i],last[i]) e[it].pb(z);
        FOR(z,first[j],last[j]) e[it].pb(z);
    }
    int cnt=0;
    while(findpath())
        FOR(i,1,c1) if(mX[i]==0 && dfs(i)) cnt++;
    return cnt==c1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
    
    FOR(i,1,n) FOR(j,1,n) if(a[i][j]==1) p[i]++;
 
    FOR(i,1,n) printf("%d",solve(i));
    //getch();
    return 0;
}
