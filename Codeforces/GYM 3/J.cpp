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

const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};

int n;
char a[12][12],b[12][12],c[12][12];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,n) scanf("%s",b[i]+1);
    
    bool touch=0;
    FOR(x,1,n) FOR(y,1,n){
        if(b[x][y]!='x'){
            c[x][y]='.';
            continue;
        }
        if(a[x][y]=='*'){
            touch=1;   
            continue;            
        }
        int d=0;
        REP(k,8) if(a[x+dx[k]][y+dy[k]]=='*') d++;
        c[x][y]=d+'0';
    }
    if(touch){
        FOR(x,1,n) FOR(y,1,n) if(a[x][y]=='*') c[x][y]='*';   
    }
    FOR(i,1,n){
        FOR(j,1,n) printf("%c",c[i][j]);
        puts("");
    }
    //getch();
    return 0;
}
