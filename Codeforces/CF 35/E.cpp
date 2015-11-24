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
typedef pair<int,pii>piii;

const int maxn=200007;
int n;
pii a[maxn];
vector<piii> list;
multiset<int> mys;

bool cmp(const pii &a, const pii &b){
    return a.fi<b.fi || (a.fi==b.fi && a.se>b.se);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int h,l,r;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d",&h,&l,&r);
        a[i]=pii(l,h); a[i+n]=pii(r,-h);
    }
    sort(a+1,a+n*2+1,cmp);
    int maxv,v;
    multiset<int>::iterator it;
    FOR(i,1,n*2){
        if(a[i].se>0){
            if(mys.empty()) maxv=0;
            else{
                it=mys.end();
                it--;
                maxv=*it;
            }
            mys.insert(a[i].se);
            it=mys.end(); it--; v=*it;
            if(maxv<v) list.pb(piii(a[i].fi, pii(maxv,v)));
        }else{
            it=mys.end(); it--;
            maxv=*it;
            mys.erase(mys.find(-a[i].se));
            if(mys.empty()) v=0; 
            else{
                it=mys.end(); 
                it--;
                v=*it;
            }
            if(maxv>v) list.pb(piii(a[i].fi, pii(maxv,v)));
        }
    }
    
    printf("%d\n",sz(list)*2);
    REP(i,sz(list)){
        printf("%d %d\n",list[i].fi,list[i].se.fi);
        printf("%d %d\n",list[i].fi,list[i].se.se);
    }
    return 0;
}
