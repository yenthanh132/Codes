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

int m,n,a[maxn];
vector<int> list[maxn];
ll sum,res;

int myabs(int v){
    return (v>0)?v:-v;   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d",&a[i]);   
    sum=0;
    FOR(i,1,m-1) sum+=myabs(a[i+1]-a[i]);
    res=sum;
    FOR(i,1,m){
        if(i>1 && a[i]!=a[i-1]) list[a[i]].pb(a[i-1]);   
        if(i<m && a[i]!=a[i+1]) list[a[i]].pb(a[i+1]);
    }
    FOR(v,1,n) if(!list[v].empty()){
        sort(list[v].begin(),list[v].end());
        ll tmp=sum;
        int v_mid=list[v][sz(list[v])/2];
        REP(i,sz(list[v])) tmp+=myabs(v_mid-list[v][i]) - myabs(v-list[v][i]);   
        res=min(res,tmp);
    }
    
    cout<<res<<endl;
    
    return 0;
}
