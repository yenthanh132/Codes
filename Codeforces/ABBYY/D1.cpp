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

const int maxn=37;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n,b,a[maxn][maxn],q,mark[maxn][maxn],step[maxn][maxn];

int move(char ch){
    if(ch=='L') return 0;
    else if(ch=='U') return 1;
    else if(ch=='R') return 2;
    else return 3;
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&b);
    int x1,y1,x2,y2;
    FOR(i,0,b) FOR(j,0,b) a[i][j]=-1;
    REP(i,n){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2) FOR(y,min(y1,y2),max(y1,y2)) a[x1][y]=(y1<y2 ? 1 : 3);
        else if(y1==y2) FOR(x,min(x1,x2),max(x1,x2)) a[x][y1]=(x1<x2 ? 2 : 0);
    }
    scanf("%d",&q);
    int x,y;
    ll t;
    char buf[5];
    reset(mark,0);
    int id=0;
    FOR(i,1,q){
        id++;
        scanf("%d%d%s%I64d",&x,&y,buf,&t);   
        int k=move(buf[0]);
        if(a[x][y]!=-1) k=a[x][y];
        mark[x][y]=id;
        step[x][y]=0;
        x1=x; y1=y;
        while(t>0){
            x1=x; y1=y;
            if(a[x][y]!=-1) k=a[x][y];
            x+=dx[k]; y+=dy[k];
            if(x<0 || x>b || y<0 || y>b){
                t=0;
                break;
            }
            t--;
            if(t==0){
                x1=x; y1=y;
                break;
            }
            if(mark[x][y]==id){
                t=t%(step[x1][y1]+1);
                id++;  
            }else{
                mark[x][y]=id;
                step[x][y]=step[x1][y1]+1;
            }
        }
        printf("%d %d\n",x1,y1);
    }
    
    getch();
    return 0;
}
