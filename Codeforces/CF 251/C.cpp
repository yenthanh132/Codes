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

const int maxn=111111;
int n,k,p;
vector<int> a,b,list[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&p);
    int v;
    REP(i,n){
        scanf("%d",&v);
        if(v&1) a.pb(v); else b.pb(v);
    }
    if(sz(a)<k-p || ((sz(a)-(k-p))&1) || sz(b)+(sz(a)-(k-p))/2<p) puts("NO");
    else{
        puts("YES");
        FOR(i,1,k-p){
            list[i].pb(a[sz(a)-1]);
            a.pop_back();
        }
        FOR(i,k-p+1,k){
            if(!b.empty()){
                list[i].pb(b[sz(b)-1]);
                b.pop_back();
            }else{
                list[i].pb(a[sz(a)-1]);
                a.pop_back();
                list[i].pb(a[sz(a)-1]);
                a.pop_back();
            }
        }
        REP(i,sz(a)) list[1].pb(a[i]);
        REP(i,sz(b)) list[k].pb(b[i]);
        FOR(i,1,k){
            printf("%d",sz(list[i]));
            REP(j,sz(list[i])) printf(" %d",list[i][j]);
            puts("");
        }
    }
    return 0;
}

