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

const int maxn = 107;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char arr[maxn][maxn];
bool mark[30];
int M,N,m,n,a,b,c;

char get(int x1, int y1, int x2, int y2){
    int xt,yt;
    reset(mark,1);
    FOR(x,x1,x2) FOR(y,y1,y2) REP(k,4){
        xt=x+dx[k]; yt=y+dy[k];
        if(xt>=1 && xt<=M && yt>=1 && yt<=N && arr[xt][yt]!='@') mark[arr[xt][yt]-'a']=0;
    }
    REP(i,26) if(mark[i]) return char('a'+i);
}

void fill(int x1, int y1, int x2, int y2){
    char ch=get(x1,y1,x2,y2);
    FOR(x,x1,x2) FOR(y,y1,y2) arr[x][y]=ch;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d%d%d",&m,&n,&a,&b,&c);
    M=m; N=n;
    bool ok=1;
    if((m*n)&1 || m*n>a*2+b*2+c*4) ok=0;
    else{
        FOR(x,1,m) FOR(y,1,n) arr[x][y]='@';
        if(m&1){
            if(a*2<n) ok=0;
            else{
                for(int y=1; y<=n; y+=2) fill(m,y,m,y+1);
                m--;
                a-=n/2;
            }
        }else if(n&1){
            if(b*2<m) ok=0;
            else{
                for(int x=1; x<=m; x+=2) fill(x,n,x+1,n);
                b-=m/2;
                n--;
            }
        }
        if(ok){
            for(int x=1; x<=m; x+=2) for(int y=1; y<=n; y+=2)
                if(c){
                    fill(x,y,x+1,y+1);
                    c--;
                }else if(a>=2){
                    fill(x,y,x,y+1);
                    fill(x+1,y,x+1,y+1);
                    a-=2;
                }else if(b>=2){
                    fill(x,y,x+1,y);
                    fill(x,y+1,x+1,y+1);
                    b-=2;
                }else ok=0;
        }
    }       
        
    if(!ok) printf("IMPOSSIBLE\n");
    else
        FOR(x,1,M){
            FOR(y,1,N) printf("%c",arr[x][y]);
            printf("\n");
        }
    //getch();
    return 0;
}
        
        
        
