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

const int maxn = 100007;

vector<int> BIT[maxn];
vector<int> list[maxn],a[maxn];
int n,m,d[maxn],pos[maxn],root,start[maxn],finish[maxn],counttime,maxdepth;

void DFS(int u){
    start[u]=++counttime;
    list[d[u]].pb(u);
    pos[u]=sz(list[d[u]])-1;
    int v;
    maxdepth=max(maxdepth,d[u]);
    REP(i,sz(a[u])){
        v=a[u][i];
        d[v]=d[u]+1;
        DFS(v);
    }
    finish[u]=counttime;
}

void updateBIT(int depth, int pos, int v){
    pos++;
    for(int i=pos; i<=sz(list[depth]); i+=i&(-i)) BIT[depth][i]+=v;
}

int getBIT(int depth, int pos){
    int res=0; pos++;
    for(int i=pos; i>0; i-=i&(-i)) res+=BIT[depth][i];
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int k,t,u,v,left,right,mid,p1,p2;
    reset(d,0);
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        d[v]++;
    }
    FOR(i,1,n){
        if(!d[i]) root=i;
        d[i]=0;
    }
    
    counttime=0;
    d[root]=1;
    DFS(root);
    
    FOR(i,1,maxdepth) BIT[i].resize(sz(list[i])+2);
    
    scanf("%d",&m);
    REP(i,m){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&u,&k,&v);
            if(d[u]+k>maxdepth) continue;
            t=d[u]+k;
            left=0; right=sz(list[t])-1; p1=right+1;
            while(left<=right){
                mid=(left+right)/2;
                if(start[list[t][mid]]>=start[u]){
                    p1=mid;
                    right=mid-1;
                }else left=mid+1;
            }
            
            left=0; right=sz(list[t])-1; p2=left-1;
            while(left<=right){
                mid=(left+right)/2;
                if(finish[list[t][mid]]<=finish[u]){
                    p2=mid;
                    left=mid+1;
                }else right=mid-1;
            }
            
            if(p1<=p2) updateBIT(t,p1,v), updateBIT(t,p2+1,-v);
        }else{
            scanf("%d",&u);
            printf("%d\n",getBIT(d[u],pos[u]));
        }
    }
    //getch();
    return 0;
}
    
