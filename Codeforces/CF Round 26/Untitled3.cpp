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

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int maxn = 100007;

int n,sk[maxn],sx[maxn],sy[maxn];
char s[maxn];
vector<pii> point;

void rotateL(int x0, int y0, int &x, int &y){
    int xt=x-x0, yt=y-y0;
    x=x0-yt; y=y0+xt;
}

void rotateR(int x0, int y0, int &x, int &y){
    int xt=x-x0, yt=y-y0;
    x=x0+yt; y=y0-xt;
}

int main(){
    //freopen("test.txt","r",stdin);
    gets(s);
    n=strlen(s);
    int k,x,y,xt,yt,x0,y0,x1,y1;
    x=y=k=0;
    REP(i,n){
        sx[i]=x; sy[i]=y; sk[i]=k;
        if(s[i]=='L') k=(k+3)%4;
        else if(s[i]=='R') k=(k+1)%4;
        else x+=dx[k], y+=dy[k];
    }
    
    REP(i,n){
        x0=sx[i]; y0=sy[i]; k=sk[i];
        if(s[i]=='L' || s[i]=='R'){
            xt=x; yt=y;
            if(s[i]=='L') rotateR(x0,y0,xt,yt); else rotateL(x0,y0,xt,yt);
            x1=xt+dx[k]; y1=yt+dy[k];
            point.pb(pii(x1,y1));
            x1=xt; y1=yt;
            if(s[i]=='L') rotateR(x0,y0,x1,y1); else rotateL(x0,y0,x1,y1);
            point.pb(pii(x1,y1));
        }else{
            xt=x-dx[k]; yt=y-dy[k];
            x1=xt; y1=yt; rotateL(x0,y0,x1,y1);
            point.pb(pii(x1,y1));
            x1=xt; y1=yt; rotateR(x0,y0,x1,y1);
            point.pb(pii(x1,y1));
        }
    }
    
    sort(point.begin(),point.end());
    int res=unique(point.begin(),point.end())-point.begin();
    printf("%d\n",res);
    
    return 0;
}
