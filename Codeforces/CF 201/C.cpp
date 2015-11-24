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

int n,a,b;
vector<int> list[2];

int main(){
    scanf("%d",&n);
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        list[0].pb(v);
    }
    sort(list[0].begin(),list[0].end());
    list[0].resize(unique(list[0].begin(),list[0].end())-list[0].begin());
    scanf("%d%d",&a,&b);
    int minv,res=0,flag=0;
    while(a!=b){
        flag^=1;
        list[flag].clear();
        minv=a-1;
        REP(i,sz(list[1^flag])){
            v=list[1^flag][i];
            if(a-a%v>=b){
                list[flag].pb(v);
                minv=min(minv,a-a%v);
            }               
        }
        a=minv;
        res++;
    }
    printf("%d\n",res);
    return 0;
}
