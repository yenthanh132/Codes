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

vector<int> list;
int n,m,d[maxn],v[maxn],from[maxn],to[maxn],t[maxn];
char buf[6];

bool insert(int l, int r, int type){
    if(d[l]==0){
        d[l]=r;
        v[l]=type;
        return 1;
    }
    if(d[l]>r){
        int sr=d[l], sv=v[l];
        d[l]=r; v[l]=type;
        r=sr; type=sv;
    }
    if(d[l]==r) return type==v[l];
    return insert(d[l]+1,r,type^v[l]);
}


int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d%s",&from[i],&to[i],buf);
        t[i]=(buf[0]=='o');
        list.pb(from[i]); list.pb(to[i]);
    }
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    FOR(i,1,m){
        from[i]=lower_bound(list.begin(),list.end(),from[i])-list.begin()+1;
        to[i]=lower_bound(list.begin(),list.end(),to[i])-list.begin()+1;
    }
    FOR(i,1,m) if(!insert(from[i],to[i],t[i])){
        printf("%d\n",i-1);
        return 0;
    }
    printf("%d\n",m);
    return 0;
}
