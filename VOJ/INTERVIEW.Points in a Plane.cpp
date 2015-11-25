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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 17
#define maxv 65536
#define base 1000000007

pii a[maxn];
int n,T,d[maxn],val[maxn],list[maxn],m,cost[maxv],count1[maxv];
bool free1[maxv];
vector<int> movelist;
queue<int> myqueue;

bool colliner(pii a, pii b, pii c){ return((a.fi-c.fi)*(a.se-b.se)==(a.fi-b.fi)*(a.se-c.se));}

void duyet(int i){
    if(i>m || d[i-1]==m) return;
    FOR(j,d[i-1]+1,m){
        d[i]=j;
        if(i<=2 || colliner(a[list[d[i-2]]],a[list[d[i-1]]],a[list[j]])){
            val[i]=val[i-1]+(1<<(list[j]-1));
            movelist.pb(val[i]);
            duyet(i+1);
        }
    }
}
        
void getmove(int id){
    m=0;
    REP(i,n) if(((id>>i)&1)==0) list[++m]=i+1;
    movelist.clear();
    d[1]=1; val[1]=(1<<(list[1]-1));
    movelist.pb(val[1]);
    duyet(2);
}

void solve(){
    int u,v,finish;
    myqueue=queue<int>();
    myqueue.push(0);
    cost[0]=0; count1[0]=1;
    finish=(1<<n)-1;
    cost[finish]=oo;
    reset(free1,true); free1[0]=false;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        if(cost[u]>=cost[finish]) break;
        getmove(u);
        REP(i,sz(movelist)){
            v=movelist[i];
            if(free1[u+v]){
                free1[u+v]=false;
                cost[u+v]=cost[u]+1;
                count1[u+v]=count1[u];
                myqueue.push(u+v);
            }else if(cost[u+v]==cost[u]+1)
                count1[u+v]=(count1[u+v]+count1[u])%base;
        }
    }
    FOR(i,2,cost[finish]) count1[finish]=((ll)count1[finish]*i)%base;
    cout<<cost[finish]<<" "<<count1[finish]<<endl;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
        solve();        
    }
    //getch();
    return 0;
}
