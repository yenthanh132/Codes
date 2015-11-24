#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
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

const int maxn=1007;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int a[maxn][maxn],m,n,deg[maxn][maxn],cnt,i0,j0,last;
bool e[maxn][maxn][4];
pii mys[maxn*maxn],list[maxn*maxn];
int arr[maxn*maxn];

int invert(int k){
    if(k==0) return 2;
    if(k==2) return 0;
    if(k==1) return 3;
    if(k==3) return 1;
}

int getk(pii a, pii b){
    REP(k,4) if(a.fi+dx[k]==b.fi && a.se+dy[k]==b.se) return k;
    return -1;
}

int gcd(int a, int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

void euler(int x, int y){
    reset(deg,0);
    mys[1]=pii(x,y);
    last=1;
    int xt,yt;

    while(last>0){
        x=mys[last].fi; y=mys[last].se;
        deg[x][y]=1;
        bool found=0;
        REP(k,4){
            if(e[x][y][k]){
                xt=x+dx[k]; yt=y+dy[k];
                e[x][y][k]=0;
                e[xt][yt][invert(k)]=0;
                mys[++last]=pii(xt,yt);
                found=1;
                break;
            }
        }
        if(!found){
            list[++cnt]=mys[last--];
            if(cnt>1) arr[cnt-1]=getk(list[cnt-1],list[cnt]);
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m)
        FOR(j,1,n) scanf("%d",&a[i][j]);
    cnt=0;
    reset(e,0);
    FOR(i,1,m) FOR(j,1,n) if(a[i][j]){
        int x,y;
        REP(k,4){
            x=i+dx[k]; y=j+dy[k];
            if(x>=1 && x<=m && y>=1 && y<=n && a[x][y]==1){
                ++deg[i][j];
                e[i][j][k]=1;
            }
        }
        if(deg[i][j]&1){
            ++cnt;
            i0=i; j0=j;
        }
    }
    if(cnt!=0 && cnt!=2){
        puts("-1");
        return 0;
    }
    if(cnt==0){
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]){
            i0=i; j0=j;
            goto solve;
        }
    }
solve:
    cnt=0;
    euler(i0,j0);

    FOR(i,1,m) FOR(j,1,n) if(a[i][j] && !deg[i][j]){
        puts("-1");
        return 0;
    }

    int val=0;
    int i=1;
    while(i<cnt){
        int j=i;
        while(j+1<cnt && arr[j+1]==arr[i]) ++j;
        val=gcd(val,j-i+1);
        i=j+1;
    }

    if(val<=1) puts("-1");
    else{
        FOR(v,2,val) if(val%v==0) printf("%d ",v);
    }

    return 0;
}

