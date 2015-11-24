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

const int maxn=1007;

int n,heal,reg,cur;
struct node{int per,dam;} a[maxn];
bool free1[maxn];
vector<pii> list;
    
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    reset(free1,1);
    scanf("%d%d%d",&n,&heal,&reg);
    FOR(i,1,n) scanf("%d%d",&a[i].per,&a[i].dam);
    int maxv,p;
    cur=heal;
    int time=0;
    while(1){
        time++;
        maxv=-1;
        FOR(i,1,n) if(free1[i] && cur*100<=heal*a[i].per)
            if(maxv<a[i].dam || (maxv==a[i].dam && a[p].per>a[i].per)){
                maxv=a[i].dam;
                p=i;
            }
        if(maxv==-1 && reg>=0){
            puts("NO");
            return 0;
        }
        if(maxv!=-1){
            reg-=maxv;
            free1[p]=0;
            list.pb(pii(time-1,p));
        }
        cur+=reg;
        cur=min(cur,heal);
        
        if(cur<=0) break;
    }
    puts("YES");
    printf("%d %d\n",time,sz(list));
    REP(i,sz(list)) printf("%d %d\n",list[i].fi,list[i].se);
    return 0;
}
            
