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

int top[maxn][maxn],bot[maxn][maxn],Left[maxn][maxn],Rightt[maxn][maxn],a[maxn][maxn];
int m,n,q;

int main(){
    scanf("%d%d%d",&m,&n,&q);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,m) FOR(j,1,n) if(a[i][j]==1){
        Left[i][j]=Left[i][j-1]+1;
        top[i][j]=top[i-1][j]+1;   
    }else{
        Left[i][j]=top[i][j]=0;   
    }
    FORD(i,m,1) FORD(j,n,1) if(a[i][j]==1){
        bot[i][j]=bot[i+1][j]+1;
        Rightt[i][j]=Rightt[i][j+1]+1;   
    }else{
        bot[i][j]=Rightt[i][j]=0;   
    }
    
    int k,x,y;
    REP(t,q){
        scanf("%d%d%d",&k,&x,&y);
        if(k==1){
            a[x][y]^=1;        
            FORD(xt,x,1) bot[xt][y]=a[xt][y]*(bot[xt+1][y]+1);
            FOR(xt,x,m) top[xt][y]=a[xt][y]*(top[xt-1][y]+1);
            FORD(yt,y,1) Rightt[x][yt]=a[x][yt]*(Rightt[x][yt+1]+1);
            FOR(yt,y,n) Left[x][yt]=a[x][yt]*(Left[x][yt-1]+1);
        }else{
            int ans=0,l,r;
            if(a[x][y]!=0){
                l=oo; r=oo;
                FOR(yt,y,n){
                    if(a[x][yt]==0) break;
                    l=min(l,top[x][yt]);
                    r=min(r,bot[x][yt]);
                    ans=max(ans,(yt-y+1)*(r+l-1));
                }
                l=oo; r=oo;
                FORD(yt,y,1){
                    if(a[x][yt]==0) break;
                    l=min(l,top[x][yt]);
                    r=min(r,bot[x][yt]);
                    ans=max(ans,(y-yt+1)*(r+l-1));
                }
                l=oo; r=oo;
                FOR(xt,x,m){
                    if(a[xt][y]==0) break;
                    l=min(l,Left[xt][y]);
                    r=min(r,Rightt[xt][y]);
                    ans=max(ans,(xt-x+1)*(r+l-1));   
                }
                l=oo; r=oo;
                FORD(xt,x,1){
                    if(a[xt][y]==0) break;
                    l=min(l,Left[xt][y]);
                    r=min(r,Rightt[xt][y]);
                    ans=max(ans,(x-xt+1)*(r+l-1));   
                }
            }   
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
