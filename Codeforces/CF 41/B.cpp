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

const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};

int a[10][10];
int x[5],y[5];
bool mark[10][10];

bool dead(int x0, int y0){
    reset(a,0);
    FOR(i,1,2) if(x[i]!=x0 || y[i]!=y0){
        FOR(z,x[i]+1,8){
            a[z][y[i]]=1;
            if(mark[z][y[i]]) break;
        }
        FORD(z,x[i]-1,1){
            a[z][y[i]]=1;
            if(mark[z][y[i]]) break;
        }
        FOR(z,y[i]+1,8){
            a[x[i]][z]=1;
            if(mark[x[i]][z]) break;
        }
        FORD(z,y[i]-1,1){
            a[x[i]][z]=1;
            if(mark[x[i]][z]) break;
        }
    }
    int xt,yt;
    REP(k,8){
        xt=x[3]+dx[k]; yt=y[3]+dy[k];
        if(xt>=1 && xt<=8 && yt>=1 && yt<=8) a[xt][yt]=1;
    }
    return a[x0][y0]==1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    FOR(i,1,4){
        cin>>s;
        x[i]=s[0]-'a'+1;
        y[i]=s[1]-'0';
        if(i!=4) mark[x[i]][y[i]]=1;
    }
    
    bool check=dead(x[4],y[4]);
    int xt,yt;
    REP(k,8){
        if(!check) break;
        xt=x[4]+dx[k]; yt=y[4]+dy[k];
        if(xt>=1 && xt<=8 && yt>=1 && yt<=8 && !dead(xt,yt)){
            check=0;
        }
    }
    if(check) puts("CHECKMATE");
    else puts("OTHER");
    //getch();
    return 0;
}
    
    
