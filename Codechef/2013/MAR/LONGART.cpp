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
const int maxblock=30000;
int m,n,res,block,cblock[maxblock+1],arr[maxblock+1][maxn];
int pos1[maxn],pos2[maxn],a[maxn][maxn];
char s1[maxn],s2[maxn],w[maxn];
vector<int> Link[maxn];
int mX[maxn],mY[maxn],dis[maxn],myqueue[maxn],first,last;

bool findpath(){
    first=1; last=0;
    FOR(i,1,m) if(mX[i]==0){
        myqueue[++last]=i;
        dis[i]=0;
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(first<=last){
        u=myqueue[first++];
        REP(i,sz(Link[u])){
            v=Link[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) myqueue[++last]=mY[v];
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(Link[u])){
        v=Link[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

bool domatching(int v){
    FOR(i,1,m){
        Link[i].clear();
        FOR(j,1,n) if(a[i][j]>=v) Link[i].pb(j);
    }
    int res=0;
    reset(mX,0); reset(mY,0);
    while(findpath()) FOR(u,1,m) if(mX[u]==0 && dfs(u)) res++;
    return res==m;
}

int getmaxmatch(){
    int l=1,r=10000000,mid,res=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(domatching(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    //FOR(i,1,m) FOR(j,1,n) if(a[i][j]<res && a[i][j]>0) res=min(res,a[i][j]);
    if(res>0) domatching(res);
    return res;
}
    

void solve(){
    int v;
    res=block=0;
    while((v=getmaxmatch())!=0){
        res+=v;
        block++;
        if(block<=maxblock){
            cblock[block]=v;
            FOR(i,1,m){
                arr[block][i]=mX[i];
                a[i][mX[i]]-=v;
            }
        }
    }
}
            
//#include <conio.h>
int main(){
    int dem[maxn];
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test,c;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d %s",&m,s1+1);
        scanf("%d %s",&n,s2+1);
        reset(pos1,0); reset(pos2,0);
        FOR(i,1,m) pos1[s1[i]-33]=i;
        FOR(i,1,n) pos2[s2[i]-33]=i;
        reset(a,0);
        FOR(i,1,m) FOR(j,1,n){
            scanf("%s%d",w,&c);
            a[pos1[w[0]-33]][pos2[w[1]-33]]=c;
        }

        if(m>n){
            printf("0\n0\n");
            continue;
        }
        solve();
        printf("%d\n",res);
        if(block>maxblock) puts("-1");
        else{
            printf("%d\n",block);
            FOR(i,1,block){
                printf("%d",cblock[i]);
                FOR(j,1,m) printf(" %c%c",s1[j],s2[arr[i][j]]);
                puts("");
            }
        }
    }
    //getch();
    return 0;
}
        
            
