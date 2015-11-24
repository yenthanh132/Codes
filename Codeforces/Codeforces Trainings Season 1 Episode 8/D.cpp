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

int n,r;
set<ll> mys[70];
vector<ll> list[70];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&r);
    ll v;
    REP(i,r){
        scanf("%I64d",&v);
        FORD(i,n,0){
            mys[i].insert(v);
            v/=2;   
        }
    }
    list[0].pb(1);
    FOR(i,0,n){
        REP(j,sz(list[i])){
            ll v=list[i][j];
            if(mys[i].find(v)==mys[i].end()){
                printf("%I64d ",v);
            }else{
                list[i+1].pb(v*2);
                list[i+1].pb(v*2+1);   
            }
        }   
    }
}
