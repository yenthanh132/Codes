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

const int MAXV=10000000;
const int maxn=357;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int isprime[MAXV+1],n,test,a[maxn][maxn];
ll res;

void init(){
    isprime[2]=1;
    for(int i=3; i<=MAXV; i+=2) isprime[i]=1;
    for(int i=3; i*i<=MAXV; i+=2) if(isprime[i])
        for(int j=i*i; j<=MAXV; j+=2*i) isprime[j]=0;
    int c=1;
    for(int i=3; i<=MAXV; i+=2) if(isprime[i]) isprime[i]=++c;
}

void dfs(int x, int y, int bit0){
    a[x][y]=-1;
    int xt,yt;
    REP(k,4){
        xt=x+dx[k]; yt=y+dy[k];
        if(xt<1 || xt>n || yt<1 || yt>n) continue;
        if(a[xt][yt]!=-1 && !isprime[a[xt][yt]] && (a[xt][yt]&1)==bit0) dfs(xt,yt,bit0);
    }
}

int main(){
    init();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        res=0;
        FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
        FOR(i,1,n) FOR(j,1,n) if(a[i][j]!=-1)
            if(isprime[a[i][j]]) res+=isprime[a[i][j]]-1;
            else if(a[i][j]&1){
                res+=(a[i][j]+3)/2;
                dfs(i,j,1);
            }else{
                res+=a[i][j]/2;
                dfs(i,j,0);
            }                
        printf("%lld\n",res);
    }
    return 0;
}
