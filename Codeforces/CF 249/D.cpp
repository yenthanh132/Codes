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

const int dx[8] = {-1,-1,-1,0,1,1,1,0};
const int dy[8] = {-1,0,1,1,1,0,-1,-1};

const int maxn=444;
char arr[maxn][maxn];
int sum[maxn][maxn];
int m,n;
ll res;

bool inside(int x, int y){
    return (1<=x && x<=m && 1<=y && y<=n);
}

bool has(int x1, int y1, int x2, int y2){
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    return (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]>0);
}

ll cal(int x, int y){
    int dx1,dy1,dx2,dy2,x1,y1,x2,y2;
    ll res=0;
    REP(k,8){
        if(k&1) continue;
        dx1=dx[k]; dy1=dy[k];
        FOR(v,-1,2){
            if(v==0) continue;
            int k2=(k+v+8)%8;
            dx2=dx[k2]; dy2=dy[k2];
            x1=x2=x; y1=y2=y;
            while(1){
                x1+=dx1; y1+=dy1; x2+=dx2; y2+=dy2;
                if(!inside(x1,y1) || !inside(x2,y2) || arr[x1][y1]=='1' || arr[x2][y2]=='1') break;
                if(!has(x1,y1,x2,y2))
                    if(v==2) res+=2; else res+=1;
            }
        }
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",arr[i]+1);
    FOR(i,1,m) FOR(j,1,n) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j]-'0';
    res=0;
    FOR(i,1,m) FOR(j,1,n) if(arr[i][j]=='0') res+=cal(i,j);
    cout<<res/2<<endl;
    return 0;
}

