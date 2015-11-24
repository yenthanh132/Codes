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

const int maxn=100007;

int n,h,t,u,v,m,mark[maxn],list[maxn],num;
vector<int> a[maxn],head,tail;
set<pii> me;
pii e[maxn*2];

bool found(){
    int z,x,y,k;
    num=0;
    REP(i,m*2){
        u=e[i].fi; v=e[i].se;
        x=sz(a[u])-1;
        y=sz(a[v])-1;
        if(x<h || y<t) continue;
        
        num++;
        k=0;
        REP(j,sz(a[u])) mark[a[u][j]]=num;
        REP(j,sz(a[v])) if(mark[a[v][j]]==num) list[++k]=a[v][j];
            
        if(x+y-k>=h+t && x>=h && y>=t){
            
            num++;
            FOR(j,1,k) mark[list[j]]=num;
            
            REP(j,sz(a[u])) if(h>0 && a[u][j]!=v && mark[a[u][j]]!=num){
                head.pb(a[u][j]);
                h--;
                mark[a[u][j]]=num;
                if(h==0) break;
            }
            while(h>0){ 
                head.pb(list[k--]);
                h--;
            }
            REP(j,sz(a[v])) if(t>0 && a[v][j]!=u && mark[a[v][j]]!=num){
                tail.pb(a[v][j]);
                t--;
                mark[a[v][j]]=num;
                if(t==0) break;
            }
            while(t>0){
                tail.pb(list[k--]);
                t--;
            }
            return 1;
        }
    }
    return 0;
}
            
        #include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&h,&t);
    REP(i,m){
        scanf("%d%d",&e[i].fi,&e[i].se);
        e[i+m].fi=e[i].se; e[i+m].se=e[i].fi;
        a[e[i].fi].pb(e[i].se);
        a[e[i].se].pb(e[i].fi);
        me.insert(e[i]);
        me.insert(e[i+m]);
    }
    if(found()){
        puts("YES");
        printf("%d %d\n",u,v);
        REP(j,sz(head)) printf("%d ",head[j]);
        printf("\n");
        REP(j,sz(tail)) printf("%d ",tail[j]);
        printf("\n");
    }else puts("NO");
    //getch();
    return 0;
}
