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

const int maxn=2007;

int h[maxn],m[maxn],n,x,t[maxn];
vector<pii> list[2];
bool mark[2][maxn];

int cal(int b){
    reset(mark,0);
    int res=0;
    int X=x;
    while(1){
        int u=-1, maxm=-oo;
        REP(i,sz(list[b])) if(!mark[b][i] && list[b][i].fi<=X && maxm<list[b][i].se){
            maxm=list[b][i].se;
            u=i;
        }
        if(u==-1) return res;
        ++res;
        X+=maxm;
        mark[b][u]=1;
        b^=1;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&x);
    FOR(i,1,n){
        scanf("%d%d%d",&t[i],&h[i],&m[i]);
        if(t[i]==0) list[0].pb(pii(h[i],m[i]));
        else list[1].pb(pii(h[i],m[i]));
    }

    int res=max(cal(1),cal(0));
    cout<<res<<endl;
}
