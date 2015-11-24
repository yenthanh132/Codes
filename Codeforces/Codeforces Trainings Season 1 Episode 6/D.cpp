#include <conio.h>
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

const int maxn=107;
struct tile{
    int x1,y1,x2,y2;
    int i1,j1,i2,j2;
}a[maxn];
int n,w,h,res;

void dfs(int x1, int y1, int x2, int y2){
    
    vector<pii> list;
    FOR(i,1,n) if(x1<=a[i].x1 && a[i].x2<=x2 && y1<=a[i].y1 && a[i].y2<=y2)
        list.pb(pii(a[i].x1,a[i].x2));     
    sort(list.begin(),list.end());
    int maxv=x1;
    REP(i,sz(list)){
        if(maxv<=list[i].fi && x1<list[i].fi){
            dfs(x1,y1,list[i].fi,y2);
            dfs(list[i].fi,y1,x2,y2);
            return;
        }
        maxv=max(maxv,list[i].se);   
    }
    
    list.clear();
    FOR(i,1,n) if(x1<=a[i].x1 && a[i].x2<=x2 && y1<=a[i].y1 && a[i].y2<=y2)
        list.pb(pii(a[i].y1,a[i].y2));     
    sort(list.begin(),list.end());
    maxv=y1;
    REP(i,sz(list)){
        if(maxv<=list[i].fi && y1<list[i].fi){
            dfs(x1,y1,x2,list[i].fi);
            dfs(x1,list[i].fi,x2,y2);
            return;
        }
        maxv=max(maxv,list[i].se);   
    }    
    
    res=max(res,(x2-x1)*(y2-y1));  
}

int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&w,&h);   
        scanf("%d",&n);
        res=0;
        FOR(i,1,n) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        
        dfs(0,0,w,h);
        printf("%d\n",res);
    }
    
    //getch();
    return 0;
}
