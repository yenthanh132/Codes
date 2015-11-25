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

const int maxn =107;
char a[maxn][maxn];
int s[2][maxn][maxn],m,n,p,col[maxn],row[maxn],lcol[maxn],rcol[maxn],trow[maxn],brow[maxn];

inline int get(int v, int x, int y){
    return(s[v][x+p-1][y+p-1]-s[v][x-1][y+p-1]-s[v][x+p-1][y-1]+s[v][x-1][y-1]);
}

inline int getpoint(int x, int y){
    return get(1,x,y)-get(0,x,y);
}

inline int gethcn(int v, int x1, int y1, int x2, int y2){
    return s[v][x2][y2]-s[v][x1-1][y2]-s[v][x2][y1-1]+s[v][x1-1][y1-1];
}

inline int giao(int x1, int y1, int x2, int y2){
    int i1,j1,i2,j2;
    if(x1<x2) i1=x2, i2=x1+p-1; else i1=x1, i2=x2+p-1;
    if(y1<y2) j1=y2, j2=y1+p-1; else j1=y1, j2=y2+p-1;
    return getpoint(x1,y1)+getpoint(x2,y2)-(gethcn(1,i1,j1,i2,j2)-gethcn(0,i1,j1,i2,j2))*2;
}
    
int main(){
    int v,res,xt,yt,x,y,x1,x2,y1,y2,i,j;
    
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d\n",&m,&n,&p);
    FOR(i,1,m){
        FOR(j,1,n) scanf("%c",&a[i][j]);
        scanf("\n");
    }
    
    FOR(i,1,m) FOR(j,1,n) REP(k,2) s[k][i][j]=s[k][i-1][j]+s[k][i][j-1]-s[k][i-1][j-1]+int(a[i][j]=='1'+k);
    FOR(i,1,m) row[i]=oo; FOR(j,1,n) col[j]=oo;
    FOR(i,1,m-p+1) FOR(j,1,n-p+1){
        v=getpoint(i,j);
        row[i]=min(row[i],v); col[j]=min(col[j],v);
    }
    trow[1]=row[1]; FOR(i,2,m-p+1) trow[i]=min(row[i],trow[i-1]);
    brow[m-p+1]=row[m-p+1]; FORD(i,m-p,1) brow[i]=min(row[i],brow[i+1]);
    lcol[1]=col[1]; FOR(j,2,n-p+1) lcol[j]=min(col[j],lcol[j-1]);
    rcol[n-p+1]=col[n-p+1]; FORD(j,n-p,1) rcol[j]=min(col[j],rcol[j+1]);
    
    FOR(i,1,m-p+1){
        FOR(j,1,n-p+1){
            v=oo;
            if(j+p<=n-p+1) v=min(v,rcol[j+p]);
            if(i+p<=m-p+1) v=min(v,brow[i+p]);
            if(i-p>=1) v=min(v,trow[i-p]);
            if(j-p>=1) v=min(v,lcol[j-p]);
            res=s[0][m][n]+getpoint(i,j)+v;
            v=s[0][m][n];
            x1=i; x2=i+p-1; y1=j; y2=j+p-1;
            for(x=x1;x<=x2;x++) for(y=y1;y<=y2;y++){
                xt=x; yt=y;
                if(xt>=1 && xt<=m-p+1 && yt>=1 && yt<=n-p+1) res=min(res,v+giao(i,j,xt,yt));
                xt=x-(p-1); yt=y;
                if(xt>=1 && xt<=m-p+1 && yt>=1 && yt<=n-p+1) res=min(res,v+giao(i,j,xt,yt));
                xt=x; yt=y-(p-1);
                if(xt>=1 && xt<=m-p+1 && yt>=1 && yt<=n-p+1) res=min(res,v+giao(i,j,xt,yt));
                xt=x-(p-1); yt=y-(p-1);
                if(xt>=1 && xt<=m-p+1 && yt>=1 && yt<=n-p+1) res=min(res,v+giao(i,j,xt,yt));
            }
            printf("%d ",res);   
        }
        printf("\n");
    }
    //cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
    
    
