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

int n,m,k,a[maxn],c,lab[maxn],num[maxn];
bool mark[maxn][maxn],free1[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

void solve(){
    reset(free1,1);
    FOR(i,1,k) free1[a[i]]=0;
    k=0;
    FOR(i,1,n) if(free1[i]) a[++k]=i;
    
    FOR(i,1,n) lab[i]=-1;
    reset(mark,0);
    int u,v;
    FOR(i,1,n-3){
        do{
            u=rand()%(n-2)+1;
            v=rand()%(n-2)+1;
            if(u>v) swap(u,v);
            if(u!=v && u!=n-1 && v!=n){
                int r1=getroot(u), r2=getroot(v);
                if(r1!=r2){
                    mark[u][v]=1;
                    mark[v][u]=1;
                    dsu(r1,r2);
                    break;
                }
            }
        }while(1);        
    }
    mark[1][n-1]=mark[n-1][1]=1;
    mark[1][n]=mark[n][1]=1;
    c=n-1;
    FOR(u,1,n-3) FOR(v,u+1,n-2) if(c<m && mark[u][v]==0){
        mark[u][v]=mark[v][u]=1;
        c++;
        if(c==m) goto out;
    }
out:
    if(c<m){
        FOR(u,2,n-2){
            mark[u][n-1]=mark[n-1][u]=1;
            c++;
            if(c==m) break;
            if(u<=k){
                mark[u][n]=mark[n][u]=1;
                c++;
                if(c==m) break;
            }
        }
    }        
    if(c<m){
        puts("-1");
        return;
    }
    
    //numbering
    reset(free1,1);
    FOR(i,1,k){
        num[i]=a[i];
        free1[a[i]]=0;
    }
    FOR(i,k+1,n){
        u=1;
        while(!free1[u]) u++;
        free1[u]=0;
        num[i]=u;   
    }
    
    FOR(u,1,n-1) FOR(v,u+1,n) if(mark[u][v]) printf("%d %d\n",num[u],num[v]);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m>>k;
    FOR(i,1,k) cin>>a[i];
    if(k==n){
        puts("-1");
        return 0;
    }
    solve();
//getch();
    return 0;
}
        
