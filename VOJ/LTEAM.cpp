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
const int maxk=107;
const int maxq=1000007;

int n,m,k,cntq,s[maxk],cnt[maxn][2],ans[maxq];
vector<int> a[maxn];
struct query{int d,e,id;} list[maxq];
struct node{int u,flag,g;
    node(int a, int b, int c){
        u=a; flag=b; g=c;
    }
};
queue<node> q;

int dis[maxn][2][maxk];
int BIT[maxk][2];

void update(int i, int flag, int v){
    for(int j=i; j; j-=j&(-j)) BIT[j][flag]+=v;
}

int get(int i, int flag){
    int res=0;
    for(int j=i; j<=k; j+=j&(-j)) res+=BIT[j][flag];
    return res;
}

bool cmp(const query &a, const query &b){
    return a.d<b.d;
}

//#include <conio.h>
int main(){
    int u,v,g,flag;
    reset(cnt,0); reset(BIT,0);
    
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&k,&cntq);
    FOR(i,1,n) REP(flag,2) FOR(j,1,k) dis[i][flag][j]=oo;
    FOR(i,1,k){
        scanf("%d",&s[i]);
        q.push(node(s[i],0,i));
        dis[s[i]][0][i]=0;
        if(cnt[s[i]][0]) update(cnt[s[i]][0],0,-1);
        update(++cnt[s[i]][0],0,1);
    }
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    FOR(i,1,cntq) scanf("%d%d",&list[i].d,&list[i].e), list[i].id=i;;
    sort(list+1,list+cntq+1,cmp);
    
    int it=1;
    while(!q.empty()){
        u=q.front().u; flag=q.front().flag; g=q.front().g; q.pop();
        while(it<=cntq && list[it].d<dis[u][flag][g]){
            ans[list[it].id]=get(list[it].e,list[it].d&1);
            it++;
        }
        if(it>cntq) break;
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[v][1^flag][g]!=oo) continue;
            dis[v][1^flag][g]=dis[u][flag][g]+1;
            if(cnt[v][1^flag]) update(cnt[v][1^flag],1^flag,-1);
            update(++cnt[v][1^flag],1^flag,1);
            q.push(node(v,1^flag,g));
        }
    }
    while(it<=cntq){
        ans[list[it].id]=get(list[it].e,list[it].d&1);
        it++;
    }
    FOR(i,1,cntq) printf("%d\n",ans[i]);
    
    //getch();
    return 0;
}
       
