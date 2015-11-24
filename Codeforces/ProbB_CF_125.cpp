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

const int maxn = 100005;

int n,k, f[2][maxn];
char a[2][maxn];
queue<pii> myqueue;

bool bfs(){
    FOR(i,1,n) f[0][i]=f[1][i]=oo;
    myqueue.push(pii(0,1));
    f[0][1]=0;
    pii u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        v.fi=u.fi;
        if(u.se>1){
            v.se=u.se-1;
            if(a[v.fi][v.se]!='X' && v.se>f[u.fi][u.se]+1 && f[v.fi][v.se]==oo){
                f[v.fi][v.se]=f[u.fi][u.se]+1;
                myqueue.push(v);
            }
        }
        v.se=u.se+1;
        if(v.se>n) return true;
            if(a[v.fi][v.se]!='X' && v.se>f[u.fi][u.se]+1 && f[v.fi][v.se]==oo){
                f[v.fi][v.se]=f[u.fi][u.se]+1;
                myqueue.push(v);
            }
        
        v.fi=1-u.fi;
        v.se=u.se+k;
        if(v.se>n) return true;
            if(a[v.fi][v.se]!='X' && v.se>f[u.fi][u.se]+1 && f[v.fi][v.se]==oo){
                f[v.fi][v.se]=f[u.fi][u.se]+1;
                myqueue.push(v);
            }
    }
    return false;
}

//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&n,&k);
    FOR(i,1,n) scanf("%c",&a[0][i]);
    scanf("\n");
    FOR(i,1,n) scanf("%c",&a[1][i]);
    if(bfs()) puts("YES"); else puts("NO");
    //getch();
    return 0;
}
    
