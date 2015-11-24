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

vector<int> next[5];
bool cycle;
bool free1[5],indfs[5];
int list[5];
int cnt;

void dfs(int u){
    free1[u]=0;
    indfs[u]=1;
    REP(i,sz(next[u])){
        int v=next[u][i];
        if(free1[v]) dfs(v);
        else if(indfs[v]) cycle=1;
    }
    indfs[u]=0;
    list[cnt--]=u;
}


#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    int u,v;
    FOR(i,1,3){
        cin>>s;
        u=s[0]-'A'; v=s[2]-'A';
        if(s[1]=='<') swap(u,v);
        next[u].pb(v);
    }
    cycle=0;
    reset(free1,1);
    reset(indfs,0);
    cnt=3;
    
    REP(i,3) if(free1[i]) dfs(i);
    if(cycle) puts("Impossible");
    else FORD(i,3,1) printf("%c",list[i]+'A');
    
    //getch();
    return 0;
}
