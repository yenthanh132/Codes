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

const int maxn=1000007;

int n,a,b,c,d,T,v,res,val[maxn];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d",&T);
    REP(tt,T){
        reset(val,0);
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        v=d; val[v]=1;
        FOR(i,2,n){
            v = (1ll*v*v*a + v*b + c)%1000000;
            ++val[v];
        }

        res=0;
        int flag=1;
        FORD(i,1000000,0) if(val[i]&1){
            if(flag) res+=i;
            else res-=i;
            flag^=1;
        }
        printf("%d\n",res);
    }
}
