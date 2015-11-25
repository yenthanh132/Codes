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

const int maxn=47;
const int maxm=2*maxn*maxn;

struct edge{int x,y,c,f;} e[maxm];
int head[maxn*2],Link[maxm],row[maxn],col[maxn],r,c,st,fi,n,m;
char arr[maxn][maxn];

//For maxflow algorithm
#define _(u) (u&1?u+1:u-1)  
int trace[maxn*2];

bool findpath(){
    queue<int> myqueue;
    myqueue.push(st);
    FOR(i,1,n) trace[i]=oo; trace[st]=0;
    int u,v,i;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        i=head[u];
        while(i){
            v=e[i].y;
            if(trace[v]==oo && e[i].c>e[i].f){
                trace[v]=i;
                if(v==fi) return 1;
                myqueue.push(v);
            }
            i=Link[i];
        }
    }
    return 0;
}

void incflow(){
    int i,v;
    v=fi;
    do{
        i=trace[v];
        e[i].f++;
        e[_(i)].f--;
        v=e[i].x;
    }while(v!=st);
}
      
void push(int u, int v){
    e[++m].x=u; e[m].y=v; e[m].c=1; e[m].f=0;
    Link[m]=head[u]; head[u]=m;
    e[++m].x=v; e[m].y=u; e[m].c=e[m].f=0;
    Link[m]=head[v]; head[v]=m;
}

//#include <conio.h>            

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test;
    scanf("%d",&test);
    FOR(tt,1,test){
        scanf("%d%d",&r,&c);
        FOR(i,1,r) scanf("%s",arr[i]+1);
        
        reset(row,0); reset(col,0);
        FOR(i,1,r) FOR(j,1,c) if(arr[i][j]=='1'){
            row[i]++;
            col[j]++;
        }
        
        n=r+c+2;
        st=n-1; fi=n;
        int res=oo,ans,vr,vc;
        
        m=0;
        reset(head,0);
        FOR(i,1,r) push(st,i);
        FOR(j,1,c) push(j+r,fi);
        FOR(i,1,r) FOR(j,1,c) push(i,j+r);
        
        FOR(x,0,c) if((x*r)%c==0){
            int y=x*r/c;
            ans=vr=vc=0;
            

            //--------------------------------
            FOR(i,1,r){
                e[i*2-1].c=abs(x-row[i]);
                ans+=abs(x-row[i]);
                e[i*2-1].f=e[i*2].f=0;
            }
            FOR(j,1,c){
                e[j*2-1 + r*2].c=abs(y-col[j]);
                ans+=abs(y-col[j]);
                e[j*2-1 + r*2].f=e[j*2 + r*2].f=0;
            }     
            if(res<=ans/2) continue;
                   
            ans=0;
            int num=(r+c)*2;
            FOR(i,1,r) FOR(j,1,c){
                num++;
                if((arr[i][j]=='1' && row[i]>x && col[j]>y)
                or (arr[i][j]=='0' && row[i]<x && col[j]<y)) e[num].c=1; else e[num].c=0;
                e[num].f=0;
                e[++num].f=0;
            }
            
            while(findpath()){
                incflow();
                ans++;
                if(ans>=res) continue;
            }
            if(ans>=res) continue;
            
            int i=head[st];
            while(i){
                vr+=abs(row[e[i].y]-x)-e[i].f;
                i=Link[i];
            }
            i=head[fi];
            while(i){
                vc+=abs(col[e[i].y-r]-y)-e[_(i)].f;
                i=Link[i];
            }
            ans+=vr+vc+min(vr,vc);
            res=min(res,ans);
        }   
       
        printf("Case %d: %d",tt,res);
        if(tt<test) puts("");
    }
    //getch();
    return 0;
}
