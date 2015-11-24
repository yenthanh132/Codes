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

const int maxn=37;

vector<int> a[maxn];
int n,m,v[maxn],cast[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&m);
        FOR(i,1,n){
            a[i].clear();
            int c,v;
            scanf("%d",&c);
            REP(j,c){
                scanf("%d",&v);
                a[i].pb(v);
            }
            scanf("%d",&cast[i]);
        }  
        FOR(i,1,m) scanf("%d",&v[i]);
        int res=0;
        FOR(i,1,n){
            int minv=oo;
            REP(j,sz(a[i]))
                minv=min(minv,v[a[i][j]]);
            res+=minv*cast[i];
        }
        printf("%d\n",res);
    }
}
