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

const int maxn=40;

char s[maxn][maxn];
bool mark[maxn][maxn];
int m,n;

void init(){
    FOR(i,1,19) 
        if(i&1){
            FOR(j,1,28) if(j%3==1) s[i][j]=' '; else s[i][j]='-';
        } else{
            int p=1;
            FOR(j,1,9){
                s[i][p++]='|';
                s[i][p++]=i/2+'0';
                s[i][p++]=j+'0';   
            }
            s[i][p]='|';
        }
    reset(mark,0);
}

void fill(int x, int y, int h, int w){
    FOR(i,x*2,(x+h-1)*2) FOR(j,y*3-1,(y+w-1)*3) if(pii(i,j)!=pii(x*2,y*3-1) && pii(i,j)!=pii(x*2,y*3)) s[i][j]=' ';
    FOR(i,x,x+h-1) FOR(j,y,y+w-1) mark[i][j]=1;
}

int gety(int x){
    int y=1;
    while(mark[x][y]) y++;
    return y;   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&m);
    while(m){
        init();
        int n=0,c,x,y;
        FOR(i,1,m){
            scanf("%d",&c);
            REP(j,c){
                scanf("%d%d",&x,&y);
                if(i==1) n+=y;
                fill(i,gety(i),x,y);   
            }
        }
        FOR(i,1,m*2+1){
            FOR(j,1,n*3+1) printf("%c",s[i][j]);
            puts("");
        }
        puts("");
        scanf("%d",&m);
    }   
}
