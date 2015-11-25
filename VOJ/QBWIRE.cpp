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

const int maxn = 501;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

bool free1[maxn][maxn],mark[maxn][maxn];
int trace[maxn][maxn],d[maxn][maxn],res,n;
pii a1,a2,b1,b2;

int bfs(pii s, pii f, pii p1, pii p2){
    queue<pii> myqueue;
    d[s.fi][s.se]=0;
    free1[s.fi][s.se]=0;
    trace[s.fi][s.se]=0;
    if(s==f) return 0;
    myqueue.push(s);
    pii u;
    int xt,yt;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(k,4){
            xt=u.fi+dx[k]; yt=u.se+dy[k];
            if(xt<0 || xt>=n || yt<0 || yt>=n || !free1[xt][yt] || pii(xt,yt)==p1 || pii(xt,yt)==p2 || mark[xt][yt]) continue;
            free1[xt][yt]=0;
            d[xt][yt]=d[u.fi][u.se]+1;
            trace[xt][yt]=k;
            if(pii(xt,yt)==f) return d[xt][yt];
            myqueue.push(pii(xt,yt));
        }
    }
    return oo;
}
 
void marktrace(pii s, pii f){
    mark[f.fi][f.se]=1;
    int k;
    while(f!=s){
        k=trace[f.fi][f.se];
        f.fi-=dx[k]; f.se-=dy[k];
        mark[f.fi][f.se]=1;
    }
}   
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T,d1,d2;
    cin>>T;
    REP(index,T){
        cin>>n;
        cin>>a1.fi>>a2.fi>>b1.fi>>b2.fi;
        cin>>a1.se>>a2.se>>b1.se>>b2.se;
        if(a1==b1 || a1==b2 || a2==b1 || a2==b2){
            cout<<"-1\n";
            continue;
        }
        res=oo;
        reset(free1,1); reset(mark,0);
        d1=bfs(a1,a2,b1,b2); 
        if(d1!=oo){
            marktrace(a1,a2);
            reset(free1,1);
            d2=bfs(b1,b2,a1,a2); res=min(res,d1+d2);
        }
        
        reset(free1,1); reset(mark,0);
        d1=bfs(b1,b2,a1,a2); 
        if(d1!=oo){
            marktrace(b1,b2);
            reset(free1,1);
            d2=bfs(a1,a2,b1,b2); res=min(res,d1+d2);
        }
        
        if(res==oo) cout<<"-1\n"; else cout<<res<<endl;
    }
    //getch();
    return 0;
}
    
