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

vector<int> list[maxn],a[maxn];
set<int> s;
int n,c[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int m,u,v;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&c[i]), list[c[i]].pb(i);
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    int res,cnt=-1;
    FOR(i,1,100000) if(!list[i].empty()){
        s.clear();
        REP(j,sz(list[i])){
            u=list[i][j];
            REP(z,sz(a[u])){
                v=a[u][z];
                if(c[v]!=i) s.insert(c[v]);
            }
        }
        if(cnt<sz(s)){
            cnt=sz(s);
            res=i;
        }
    }
    
    printf("%d\n",res);
    //getch();
    return 0;
}
