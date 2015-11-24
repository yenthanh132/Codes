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

const int maxn=307;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

int m,n,k,xres,yres,vres;
char a[maxn][maxn];

bool found(int v){
    int xt,yt;
    bool ok;
    FOR(x,v,m-v) FOR(y,v,n-v) if(a[x][y]=='*'){
        ok=1;
        REP(kk,4){
            xt=x+dx[kk]*v;
            yt=y+dy[kk]*v;
            if(a[xt][yt]!='*'){
                ok=0;
                break;
            }
        }
        if(ok){
            k--;
            if(!k){
                xres=x; yres=y; vres=v;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) scanf("%s",a[i]+1);
    bool Found=0;
    FOR(x,1,(min(m,n)-1)/2) if(found(x)){
        Found=1;
        break;
    }
    if(!Found) puts("-1");
    else{
        printf("%d %d\n",xres,yres);
        REP(k,4) printf("%d %d\n",xres+dx[k]*vres,yres+dy[k]*vres);
    }
    return 0;
}
