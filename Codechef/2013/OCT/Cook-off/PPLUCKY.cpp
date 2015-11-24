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

int next[maxn],prev[maxn],BIT[maxn],n;
char s[maxn];
vector<int> myq[2];

void update(int p, int v){
    for(int i=p; i<=n; i+=i&(-i)) BIT[i]+=v;
}

int get(int p){
    int res=0;
    for(int i=p; i; i-=i&(-i)) res+=BIT[i];
    return res;
}

void del(int p){
    next[prev[p]]=next[p];
    prev[next[p]]=prev[p];  
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);   
        scanf("%s",s+1);
        FOR(i,1,n){
            prev[i]=i-1;
            next[i]=i+1;
        }
        reset(BIT,0);
        ll res=0;
         
        myq[0].clear();
        myq[1].clear();
        FOR(i,1,n) if(s[i]=='4' && s[i+1]=='7'){
            myq[0].pb(i);
        }  
        int u,v;
        int flag=0;
        while(1){
            if(myq[flag].empty()) break;
            myq[1^flag].clear();
            REP(i,sz(myq[flag])){
                u=myq[flag][i];
                res+=u-get(u);
                del(u);
                del(next[u]);
                if(prev[u]>0 && s[prev[u]]=='4'){
                    v=prev[u];
                    if(next[v]<=n && s[next[v]]=='7') myq[1^flag].pb(v);
                }
            }
            REP(i,sz(myq[flag])){
                u=myq[flag][i];
                update(u,1);
                update(next[u],1);
            }
            flag^=1;
        }
        cout<<res<<endl;
    }
    //getch();
    return 0;
}
