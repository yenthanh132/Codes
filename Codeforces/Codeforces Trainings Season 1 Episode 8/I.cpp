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

const int maxn=27;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

char s[maxn];
bool mark[maxn][maxn];
int n,a[maxn][maxn],cnt,ans[10];

bool full(){
    FOR(i,1,n) FOR(j,1,n) if(a[i][j]!=a[1][1]) return 0;
    return 1;
}

void dfs2(int x, int y, int val){
    mark[x][y]=1;
    cnt++;
    int xt,yt;   
    REP(k,4){
        xt=x+dx[k];
        yt=y+dy[k];
        if(xt<1 || xt>n || yt<1 || yt>n || mark[xt][yt]) continue;
        if(a[xt][yt]==val) dfs2(xt,yt,val);
    }
}

void dfs1(int x, int y, int val){
    mark[x][y]=1;
    int xt,yt;
    REP(k,4){
        xt=x+dx[k];
        yt=y+dy[k];
        if(xt<1 || xt>n || yt<1 || yt>n || mark[xt][yt]) continue;
        if(a[xt][yt]==a[1][1]) dfs1(xt,yt,val);
        else if(a[xt][yt]==val) dfs2(xt,yt,val);
    }
}

int count(int v){
    reset(mark,0);
    cnt=0;
    dfs1(1,1,v);
    return cnt;
}

void dfs3(int x, int y, int old, int val){
    mark[x][y]=1;
    a[x][y]=val;
    int xt,yt;
    REP(k,4){
        xt=x+dx[k];
        yt=y+dy[k];
        if(xt<1 || xt>n || yt<1 || yt>n || mark[xt][yt]) continue;
        if(a[xt][yt]==old) dfs3(xt,yt,old,val);
    }
}

void fill(int v){
    reset(mark,0); 
    dfs3(1,1,a[1][1],v);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);   
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,n){
            scanf("%s",s+1);
            FOR(j,1,n) a[i][j]=s[j]-'0';
        }
        reset(ans,0);
        int res=0;
        while(!full()){
            int u=-1, maxv=-oo;
            FOR(i,1,6) {
                int v=count(i);
                if(v>maxv){
                    maxv=v;
                    u=i;
                }   
            }   
            res++;
            ans[u]++;
            fill(u);
        }
        printf("%d\n",res);
        FOR(i,1,6) printf("%d ",ans[i]);
        puts("");
    }
}
