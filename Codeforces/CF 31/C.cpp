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

const int maxn=5007;

int n;
struct node{
    int l,r,id;
    bool operator <(const node &a) const{
        return l<a.l;
    }
} a[maxn];
vector<int> list;

bool check(int id){
    int v=0;
    FOR(i,1,n) if(i!=id){
        if(v>a[i].l) return 0;
        v=a[i].r;
    }
    return 1;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].l,&a[i].r), a[i].id=i;
    sort(a+1,a+n+1);
    
    FOR(i,1,n) if(check(i)) list.pb(a[i].id);
    sort(list.begin(),list.end());
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
    return 0;
}
