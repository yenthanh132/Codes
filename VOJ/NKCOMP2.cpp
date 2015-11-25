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
const int maxm = 500007;

struct query1{int t,k,v;};
int n,m,root,d[maxn];
bool mark[maxn];
vector<int> a[maxn],list2[maxn],list3[maxn],listsum[maxn];
vector<pii> anslist;
vector<query1> list1[maxn];

void DFS(int u){
    int v,t;
    query1 q1;
    REP(i,sz(list1[u])){
        q1=list1[u][i];
        v=d[u]+q1.k;
        if(v>n) continue;
        if(listsum[v].empty()) listsum[v].pb(0), list3[v].pb(-1);
        listsum[v].pb(listsum[v].back()+q1.v); list3[v].pb(q1.t);
    }
    
    int left,right,mid,p;
    REP(i,sz(list2[u])){
        t=list2[u][i];
        v=d[u];
        if(listsum[v].empty()) listsum[v].pb(0), list3[v].pb(-1);
        left=1; right=sz(list3[v])-1; p=0;
        while(left<=right){
            mid=(left+right)/2;
            if(list3[v][mid]<=t){p=mid; left=mid+1;} else right=mid-1;
        }
        anslist.pb(pii(t,listsum[v][p]));
    }
    
    REP(i,sz(a[u])){
        v=a[u][i];
        d[v]=d[u]+1;
        DFS(v);
    }
    
    REP(i,sz(list1[u])){
        q1=list1[u][i];
        v=d[u]+q1.k;
        listsum[v].pop_back(); list3[v].pop_back();
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v,t,k;
    query1 q1;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        mark[v]=1;        
    }
    
    FOR(i,1,n) if(!mark[i]) {root=i; break;}
    
    scanf("%d",&m);
    REP(i,m){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&u,&k,&v);
            q1.t=i; q1.k=k; q1.v=v;
            list1[u].pb(q1);
        }else{
            scanf("%d",&u);
            list2[u].pb(i);
        }
    }
    
    d[root]=1;
    DFS(root);
    
    sort(anslist.begin(),anslist.end());
    REP(i,sz(anslist)) printf("%d\n",anslist[i].se);
    
    //getch();   
    return 0;
}
