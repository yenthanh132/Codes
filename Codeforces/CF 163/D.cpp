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

const int maxn=207;

int a[maxn][maxn],n,m,e[maxn][maxn];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,n) if(i==j) a[i][j]=0; else a[i][j]=oo;
    int u,v,w;
    reset(e,0);
    FOR(i,1,m){
        scanf("%d%d%d",&u,&v,&w);
        e[u][v]=e[v][u]=w;
        a[u][v]=min(a[u][v],w);
        a[v][u]=min(a[v][u],w);
    }
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    double res=oo;
    FOR(i,1,n-1) FOR(j,i+1,n) if(e[i][j]){
        int maxi,maxj,maxmid;
        maxi=maxj=maxmid=0;
        FOR(k,1,n){
            if(a[i][k]<a[j][k]) maxi=max(maxi,a[i][k]);
            if(a[j][k]<a[i][k]) maxj=max(maxj,a[j][k]);
            if(a[i][k]==a[j][k]) maxmid=max(maxmid,a[i][k]);
        }
        if(maxi>maxj) swap(maxi,maxj);
        maxj=max(maxj,maxmid);
        double t=(maxi+maxj+e[i][j])/2.0;
        if(t<maxi) t=maxi;
        if(t>maxi+e[i][j]) t=maxi+e[i][j];
        res=min(res,max(t,maxi+maxj+e[i][j]-t));
    }            
    printf("%0.2lf",res);
    getch();
    return 0;
}
