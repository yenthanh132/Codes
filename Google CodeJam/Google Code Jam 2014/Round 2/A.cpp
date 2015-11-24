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

const int maxn=10007;

int n,t,x;
int c[777];

int main(){
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    FOR(tt,1,t){
        scanf("%d%d",&n,&x);
        reset(c,0);
        int v;
        FOR(i,1,n){
            scanf("%d",&v);
            c[v]++;
        }
        int res=0;
        FORD(v,x,1){
            while(c[v]>0){
                ++res;
                c[v]--;
                FORD(u,x-v,1) if(c[u]>0){
                    --c[u];
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",tt,res);
    }
}

