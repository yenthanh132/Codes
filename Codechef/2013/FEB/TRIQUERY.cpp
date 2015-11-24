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

const int maxn=300007;
const int maxv=300000;

int n,q,BIT[maxn],ans[maxn];
struct node{int x,y,d,id;} a[maxn*2];

bool cmp1(const node &a, const node &b){
    return a.y<b.y || (a.y==b.y && a.id>b.id);
}

bool cmp2(const node &a, const node &b){
    int v1=a.x+a.y+a.d;
    int v2=b.x+b.y+b.d;
    return v1<v2 || (v1==v2 && a.id<b.id);
}

void update(int p){
    for(int i=p; i<=maxv; i+=i&(-i)) BIT[i]++;
}

int get(int p){
    int ans=0;
    p=min(p,maxv);
    for(int i=p; i; i-=i&(-i)) ans+=BIT[i];
    return ans;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&q);
    FOR(i,1,n){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=0;
    }
    FOR(i,1,q){
        scanf("%d%d%d",&a[i+n].x,&a[i+n].y,&a[i+n].d);
        a[i+n].id=i;
    }
    sort(a+1,a+n+q+1,cmp1);
    FOR(i,1,n+q)
        if(a[i].id) ans[a[i].id]-=get(a[i].x+a[i].d)-get(a[i].x-1);
        else update(a[i].x);
    sort(a+1,a+n+q+1,cmp2);
    reset(BIT,0);
    FOR(i,1,n+q)
        if(a[i].id) ans[a[i].id]+=get(a[i].x+a[i].d)-get(a[i].x-1);
        else update(a[i].x);
    FOR(i,1,q) printf("%d\n",ans[i]);
    
    //getch();
    return 0;
}
