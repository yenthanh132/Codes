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

struct point{
    int x,y;
    
}a[maxn];

vector<point> listxy[maxn*2], listx[maxn],listy[maxn];
int n;
ll vlist[maxn];

bool found(int x, int y){
    ll v=1ll*x*1000000+y;
    int l=1, r=n, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(vlist[mid]==v) return 1;
        else if(vlist[mid]<v) l=mid+1;
        else r=mid-1;
    }   
    return 0;
}

bool cmp(const point &a, const point &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);   
}



int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);  
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].x,&a[i].y), vlist[i]=1ll*a[i].x*1000000+a[i].y;
    sort(vlist+1,vlist+n+1);
    sort(a+1,a+n+1,cmp);
    int res=0;
    FOR(i,1,n){
        int x=a[i].x,y=a[i].y,x2,y2;
        int id=x-y+maxn;
        if(sz(listxy[id])<=sz(listx[x]) && sz(listxy[id])<=sz(listy[y])){
            REP(j,sz(listxy[id])){
                x2=listxy[id][j].x; y2=listxy[id][j].y;
                if(found(x2,y2) && found(x2,y) && found(x,y2)) ++res;
            }   
        }else if(sz(listx[x])<=sz(listy[y])){
            REP(j,sz(listx[x])){
                y2=listx[x][j].y;
                x2=x-(y-y2);
                if(found(x2,y2) && found(x2,y) && found(x,y2)) ++res;
            }   
        }else{
            REP(j,sz(listy[y])){
                x2=listy[y][j].x;
                y2=y-(x-x2);
                if(found(x2,y2) && found(x2,y) && found(x,y2)) ++res;
            }   
        }                
        listxy[id].pb(a[i]);
        listx[x].pb(a[i]);
        listy[y].pb(a[i]);
        
    }
    cout<<res<<endl;    
}
