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

int m,n,k,X,Y;
bool free1[maxn][maxn];
queue<pii> myq;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    int x,y;
    reset(free1,1);
    REP(i,k){
        scanf("%d%d",&x,&y);
        free1[x][y]=0;
        myq.push(pii(x,y));
    }
    while(!myq.empty()){
        X=myq.front().fi; Y=myq.front().se;
        myq.pop();
        REP(k,4){
            x=X+dx[k]; y=Y+dy[k];
            if(x>=1 && x<=m && y>=1 && y<=n && free1[x][y]){
                free1[x][y]=0;
                myq.push(pii(x,y));
            }
        }
    }
    printf("%d %d\n",X,Y);
    return 0;
}
