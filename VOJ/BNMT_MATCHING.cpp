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

const int maxn=47;

int row[maxn],col[maxn],r,c,n,m,mX[maxn*maxn],mY[maxn*maxn],dis[maxn*maxn];
pii rowseq[maxn],colseq[maxn];
vector<int> a[maxn*maxn];
char arr[maxn][maxn];

bool findpath(){
    queue<int> q;
    FOR(i,1,m) if(mX[i]==0){
        q.push(i);
        dis[i]=0;
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) q.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}
            
//#include <conio.h>            

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test;
    scanf("%d",&test);
    FOR(tt,1,test){
        scanf("%d%d",&r,&c);
        FOR(i,1,r) scanf("%s",arr[i]+1);
        
        reset(row,0); reset(col,0);
        FOR(i,1,r) FOR(j,1,c) if(arr[i][j]=='1'){
            row[i]++;
            col[j]++;
        }
        
        int res=oo,ans,vr,vc;
        
        FOR(x,0,c) if((x*r)%c==0){
            int y=x*r/c;
            ans=vr=vc=0;
            m=n=0;
            FOR(i,1,r) if(row[i]!=x){
                rowseq[i]=pii(m+1,m+abs(row[i]-x));
                m+=abs(row[i]-x);
            }
            FOR(i,1,c) if(col[i]!=y){
                colseq[i]=pii(n+1,n+abs(col[i]-y));
                n+=abs(col[i]-y);
            }
            
            FOR(i,1,m) a[i].clear();
            FOR(i,1,m) mX[i]=0;
            FOR(i,1,n) mY[i]=0;
            
            FOR(i,1,r) FOR(j,1,c){
                if((arr[i][j]=='1' && row[i]>x && col[j]>y)
                or (arr[i][j]=='0' && row[i]<x && col[j]<y))
                    FOR(x,rowseq[i].fi,rowseq[i].se)
                        FOR(y,colseq[j].fi,colseq[j].se)
                            a[x].pb(y);
            }
           
            while(findpath())
                FOR(i,1,m) if(mX[i]==0 && dfs(i)) ans++;
            FOR(i,1,r) vr+=abs(row[i]-x);
            FOR(i,1,c) vc+=abs(col[i]-y);
            FOR(i,1,m) if(mX[i]) vr--;
            FOR(i,1,n) if(mY[i]) vc--;                    
            
            ans+=vr+vc+min(vr,vc);
            res=min(res,ans);
        }   
       
        printf("Case %d: %d\n",tt,res);
    }
    //getch();
    return 0;
}
