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

const int maxn=107;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char a[maxn][maxn];
int m,n;

bool found(int x, int y, char ch){
    int xt,yt;
    REP(k,4){
        xt=x+dx[k];
        yt=y+dy[k];
        if(xt>=1 && xt<=m && yt>=1 && yt<=n && a[xt][yt]==ch) return 1;   
    } 
    return 0;
}

void fill(int x1, int y1, int x2, int y2, char ch){
    FOR(x,x1,x2) FOR(y,y1,y2) a[x][y]=ch;   
}

bool ok(int x1, int y1, int x2, int y2, char ch){
    FOR(x,x1,x2){
        if(a[x][y1]!='@' || found(x,y1,ch)) return 0;
        if(a[x][y2]!='@' || found(x,y2,ch)) return 0;
    }
    FOR(y,y1,y2){
        if(a[x1][y]!='@' || found(x1,y,ch)) return 0;
        if(a[x2][y]!='@' || found(x2,y,ch)) return 0;
    }
    return 1;   
}

bool can_put(int x, int y, char ch){
    for(char c='A'; c<ch; ++c) if(!found(x,y,c)) return 1;
    return 0;   
}

void dofill(int x, int y, char ch){
    int l=1, r=min(m-x+1,n-y+1),len,res=1;
    for(len=1; len<=r && ok(x,y,x+len-1,y+len-1,ch); ++len){
        res=len;
        if(y+len<=n && can_put(x,y+len,ch)) break;
    }
    fill(x,y,x+res-1,y+res-1,ch);      
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m>>n;
    FOR(i,1,m) FOR(j,1,n) a[i][j]='@';
    
    FOR(x,1,m) FOR(y,1,n) if(a[x][y]=='@'){
        char ch='A';
        while(found(x,y,ch)) ++ch; 
        dofill(x,y,ch);
        
    }
        
    FOR(x,1,m){
        FOR(y,1,n) putchar(a[x][y]);
        puts("");   
    }
}
