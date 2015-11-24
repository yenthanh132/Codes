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

const int maxn=1007;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int m,n,d,x1,Y1,x2,y2,len,dis[maxn][maxn],mark[maxn][maxn];
vector<pii> list;
char a[maxn][maxn];

bool check(int id, int x1, int Y1, int x2, int y2){
    queue<pii> q;
    dis[x1][Y1]=0; dis[x2][y2]=0;
    mark[x1][Y1]=mark[x2][y2]=id;
    int x,y,xt,yt,c=0;
    q.push(pii(x1,Y1)); q.push(pii(x2,y2));
    if(a[x1][Y1]=='R') c++;
    if(pii(x1,Y1)!=pii(x2,y2) && a[x2][y2]=='R') c++;
    while(!q.empty()){
        x=q.front().fi; y=q.front().se; q.pop();
        REP(k,4){
            xt=x+dx[k]; yt=y+dy[k];
            if(a[xt][yt]=='X') continue;
            if(mark[xt][yt]!=id){
                mark[xt][yt]=id;
                dis[xt][yt]=dis[x][y]+1;    
                if(dis[xt][yt]<d) q.push(pii(xt,yt));
                if(a[xt][yt]=='R') c++;
            }
        }
    }
    
    return c==sz(list);
}
        
    

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&d);
    FOR(i,1,m) scanf("%s",a[i]+1);
    
    //Place for the first boom
    x1=Y1=oo;
    FOR(i,1,m) FOR(j,1,n) if(a[i][j]=='R'){
        if(x1==oo){
            x1=i;
            Y1=j;
        }
        list.pb(pii(i,j));
    }
    len=d+1;
    x2=y2=oo;
    int c=0,x,y;
    //Find a place to put down the second boom
    REP(i,sz(list)) if(list[i].fi>=x1+len || list[i].se>=Y1+len || list[i].fi<=x1-len || list[i].se<=Y1-len){
        x2=list[i].fi;
        y2=list[i].se;
        break;
    }
    if(x2==oo){
        x2=x1;
        y2=Y1;
    }
    
    //If there is no rats...
    if(x1==oo){
        FOR(i,1,m) FOR(j,1,n){
            if(a[i][j]!='X')
                if(x1==oo){
                    x1=i;
                    Y1=j;
                }else{
                    x2=i;
                    y2=j;
                    break;
                }
            if(x2!=oo) break;
        }
        if(x2==oo) puts("-1");
        else printf("%d %d %d %d\n",x1,Y1,x2,y2);
        return 0;
    }
    
    reset(mark,0);
    //Now check for every possible position
    int id=0;
    c=0;
    FOR(r1,x1-len+1,x1+len-1) if(1<=r1 && r1<=m)
        FOR(c1,Y1-len+1,Y1+len-1) if(1<=c1 && c1<=n && a[r1][c1]!='X')
            FOR(r2,x2-len+1,x2+len-1) if(1<=r2 && r2<=m)
                FOR(c2,y2-len+1,y2+len-1) if(1<=c2 && c2<=n && a[r2][c2]!='X' && pii(r1,c1)!=pii(r2,c2)){
                    if(check(++id,r1,c1,r2,c2)){
                        printf("%d %d %d %d\n",r1,c1,r2,c2);
                        return 0;
                    }
                }
    
    FOR(r1,x1-len+1,x1+len-1) if(1<=r1 && r1<=m)
        FOR(c1,Y1-len+1,Y1+len-1) if(1<=c1 && c1<=n && a[r1][c1]!='X')
            FOR(r2,x2-len+1,x2+len-1) if(1<=r2 && r2<=m)
                FOR(c2,y2-len+1,y2+len-1) if(1<=c2 && c2<=n && a[r2][c2]!='X')
                    if(check(++id,r1,c1,r2,c2)){
                        FOR(i,1,m) FOR(j,1,n) if(a[i][j]!='X' && pii(i,j)!=pii(r1,c1)){
                            printf("%d %d %d %d\n",r1,c1,i,j);
                            return 0;
                        }
                    }                    
                           
    puts("-1");
    return 0;
}
        
        
    

