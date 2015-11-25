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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int n,res,minX[maxn],maxX[maxn],minY[maxn],maxY[maxn];
bool mark[maxn][maxn];
queue<pii> myq;

void update(int x, int y){
    minX[y]=min(minX[y],x);
    minY[x]=min(minY[x],y);
    maxX[y]=max(maxX[y],x);
    maxY[x]=max(maxY[x],y);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    int x,y,xt,yt;
    scanf("%d",&n);
    FOR(i,0,2000){
        minX[i]=oo;
        minY[i]=oo;
        maxX[i]=-oo;
        maxY[i]=-oo;
    }
    res=0;
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        x+=1000; y+=1000;
        if(!mark[x][y]) res++;
        mark[x][y]=1;
        update(x,y);
        myq.push(pii(x,y));
    }   
    while(!myq.empty()){
        x=myq.front().fi; y=myq.front().se; myq.pop();
        REP(k,4){
            xt=x+dx[k]; yt=y+dy[k];
            if(xt>=0 && xt<=2000 && yt>=0 && yt<=2000 && !mark[xt][yt]
                && minX[y]<=xt && xt<=maxX[y] && minY[x]<=yt && yt<=maxY[x]){
                mark[xt][yt]=1;
                myq.push(pii(xt,yt));
                update(xt,yt);
                res++;
            }
        }
    }
    printf("%d\n",res);
    //getch();
    return 0;
}       
