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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;
const int dx[2]={1,0};
const int dy[2]={0,1};

char s[maxn][maxn];
vector<int> e[maxn*maxn];
int match[maxn*maxn],myq[maxn*maxn],trace[maxn*maxn],w,h,n,first,last,com[maxn*maxn];

void enlarge(int v){
    while(v!=-1){
        int u=trace[v];
        int next=match[u];
        match[u]=v; match[v]=u;
        v=next;
    }
}

bool find_path(bool doEnlarge){
    while(first<=last){
        int u=myq[first++];
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(trace[v]!=0) continue;
            trace[v]=u;
            if(match[v]==-1){
                if(doEnlarge) enlarge(v);
                return 1;
            }
            trace[match[v]]=u;
            myq[++last]=match[v];
        }
    }
    return 0;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d%d",&h,&w),w>0){
        for(int i=1; i<=h; ++i) scanf("%s",s[i]+1);
        n=w*h;
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int x=1; x<=h; ++x) for(int y=1; y<=w; ++y) if(s[x][y]=='.'){
            com[(x-1)*w+y]=(x+y)&1;
            for(int k=0; k<2; ++k){
                int xt=dx[k]+x, yt=dy[k]+y;
                if(xt<=h && yt<=w && s[xt][yt]=='.'){
                    int u=(x-1)*w+y;
                    int v=(xt-1)*w+yt;
                    e[u].pb(v); e[v].pb(u);
                }
            }
        }
        for(int i=1; i<=n; ++i) match[i]=-1;
        do{
            first=1; last=0;
            for(int i=1; i<=n; ++i) trace[i]=0;
            for(int i=1; i<=n; ++i) if(com[i]==0 && match[i]==-1) myq[++last]=i, trace[i]=-1;
        }while(find_path(1));

        for(int i=1; i<=h; ++i) for(int j=1; j<=w; ++j) if(s[i][j]=='.'){
            int id=(i-1)*w+j;
            if(match[id]==-1) s[i][j]='B';
            else{
                s[i][j]='A';
                first=last=1;
                for(int i=1; i<=n; ++i) trace[i]=0;
                myq[1]=match[id];
                trace[match[id]] = trace[id] = -1;
                if(find_path(0)) s[i][j]='B';
            }
        }
        for(int i=1; i<=h; ++i) printf("%s\n",s[i]+1);
        puts("");
    }
    return 0;
}
