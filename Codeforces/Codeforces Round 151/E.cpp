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

vector<int> a[maxn],query[maxn],idquery[maxn],list[maxn];
int n,m,root,cnt,val[maxn],h[maxn],maxh,first[maxn],last[maxn],num;
map<string,int> mname;
map<int,int> savepos;
char buf[30];
vector<pii> truyvan[maxn];
int BIT[maxn],res[maxn];

void dfs(int u){
    int v;
    first[u]=++num;
    maxh=max(maxh,h[u]);
    list[h[u]].pb(u);
    REP(i,sz(a[u])){
        v=a[u][i];
        h[v]=h[u]+1;
        dfs(v);
    }
    last[u]=num;
}

void update(int p,int v){
    p++;
    for(int i=p; i<=maxn-1; i+=i&(-i)) BIT[i]+=v;
}

int get(int p){
    p++;
    int res=0;
    for(int i=p; i>0; i-=i&(-i))
      res+=BIT[i];
    return res;
}

int getseq(int l, int r){
    return get(r)-get(l-1);
}

void solve(int h){
    if(query[h].empty()) return;
    int len=sz(list[h]);
    FOR(i,1,len) BIT[i]=0;
    FOR(i,0,len-1) truyvan[i].clear();
    
    int l,r,mid,left,right,v;
    REP(i,sz(query[h])){
        v=query[h][i];
        l=0; r=len-1;
        left=oo;
        while(l<=r){
            mid=(l+r)>>1;
            if(first[list[h][mid]]>=first[v]){
                left=mid;
                r=mid-1;
            }else l=mid+1;
        }
        l=0; r=len-1;
        right=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(last[list[h][mid]]<=last[v]){
                right=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(left<=right) truyvan[right].pb(pii(left,idquery[h][i]));
    }
    int id, u;
    savepos.clear();
    REP(i,len){
        u=list[h][i];
        if(savepos[val[u]]>0){
            update(savepos[val[u]]-1,-1);
        }
        update(i,1);
        savepos[val[u]]=i+1;
        
        REP(j,sz(truyvan[i])){
            v=truyvan[i][j].fi; 
            id=truyvan[i][j].se;
            res[id]=getseq(v,i);    
        }
    }
}
       
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    cnt=0;
    int p;
    FOR(i,1,n){
        scanf("%s %d\n",buf,&p);
        string tmp=string(buf);
        if(mname[tmp]==0) mname[tmp]=++cnt;
        val[i]=mname[tmp];
        a[p].pb(i);
    }
    
    h[0]=0; maxh=0; num=0;
    dfs(0);
    
    scanf("%d",&m);
    int v,k;
    reset(res,0);
    FOR(i,1,m){
        scanf("%d%d",&v,&k);
        if(h[v]+k<=maxh){
            query[h[v]+k].pb(v);
            idquery[h[v]+k].pb(i);
        }
    }
    
    FOR(i,1,maxh) solve(i);
    
    FOR(i,1,m) printf("%d\n",res[i]);
    //getch();
    return 0;
}
            
