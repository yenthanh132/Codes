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

const int maxn=5007;
const int maxm=30007*2;

struct edge{
    int x,y;
    ll c,f;
}e[maxm];
int head[maxn],jump[maxm],trace[maxn],myq[maxn];
int n,m,cnt;

void push(int x, int y, int w){
    jump[cnt] = head[x];
    e[cnt].x = x; e[cnt].y = y; e[cnt].c = w; e[cnt].f = 0;
    head[x] = cnt++;
    jump[cnt] = head[y];
    e[cnt].x = y; e[cnt].y = x; e[cnt].c = w; e[cnt].f = 0;
    head[y] = cnt++;
}

bool findpath(){
    int first=1, last=1, u, v;
    myq[1]=1;
    reset(trace,0); trace[1]=-1;
    while(first<=last){
        u=myq[first++];
        for(int i=head[u]; i; i=jump[i]){
            v=e[i].y;
            if(!trace[v] && e[i].c > e[i].f){
                trace[v] = i;
                myq[++last] = v;
            }
        }
    }
    return trace[n];
}

ll incflow(){
    ll ans = 0;
    int j,v;
    ll delta;
    for(int i=head[n]; i; i=jump[i]){
        v=e[i].y; delta = e[i^1].c - e[i^1].f;
        while(delta > 0 && v != 1){
            j = trace[v];
            if(j == 0){
                delta = 0;
                break;
            }
            delta = min(delta, e[j].c - e[j].f);
            v = e[j].x;
        }
        if(delta == 0) continue;
        ans += delta;
        e[i].f -= delta; e[i^1].f += delta;
        v=e[i].y;
        while(v!=1){
            j = trace[v];
            e[j].f += delta;
            e[j^1].f -= delta;
            v = e[j].x;
        }
    }
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int x,y,w;
    cnt=2; reset(head,0);
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&x,&y,&w);
        push(x,y,w);
    }
    ll res = 0;
    while(findpath()) res += incflow();
    cout<<res<<endl;
}
