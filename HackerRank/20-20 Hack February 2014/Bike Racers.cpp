#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
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

const int maxn=257;

vector<int> a[maxn];
int mX[maxn],mY[maxn],dis[maxn],myq[maxn];
ll X0[maxn],Y0[maxn],X1[maxn],Y1[maxn];
int n,m,k;

bool findpath(){
    int first=1, last=0;
    FOR(i,1,n) if(mX[i]==0){
        myq[++last]=i;
        dis[i]=0;   
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(first<=last){
        u=myq[first++];
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[mY[v]]!=oo) continue;
            dis[mY[v]]=dis[u]+1;
            myq[++last]=mY[v];
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];   
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;   
        }
    }   
    dis[u]=oo;
    return 0;
}

bool check(ll v){
    FOR(i,1,n){
        a[i].clear();
        FOR(j,1,m) if((X0[i]-X1[j])*(X0[i]-X1[j])+(Y0[i]-Y1[j])*(Y0[i]-Y1[j]) <= v) a[i].pb(j);
    }
    reset(mX,0); reset(mY,0);
    int res=0;
    while(findpath())
        FOR(u,1,n) if(mX[u]==0 && dfs(u)){
            ++res;
            if(res>=k) return 1;
        }
    return 0;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%lld%lld",&X0[i],&Y0[i]);
    FOR(i,1,m) scanf("%lld%lld",&X1[i],&Y1[i]);
    ll res,left=0,right=100000000,mid;
    right=right*right*2;
    while(left<=right){
        mid=(left+right)/2;
        if(check(mid)){
            res=mid;
            right=mid-1;   
        }else left=mid+1;
    }
    printf("%lld\n",res);
    //getch();
    return 0;
}
