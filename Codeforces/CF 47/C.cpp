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

struct point{
    ll x,y;
    point(){}
    point(ll a, ll b){
        x=a; y=b;
    }
}a[400007];

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n;
int mys[400007],last;
set<pii> myset;

ll dt2(int i, int j, int k){
    ll vx1=a[j].x-a[i].x, vy1=a[j].y-a[i].y;
    ll vx2=a[k].x-a[i].x, vy2=a[k].y-a[i].y;
    return vx1*vy2-vx2*vy1;
}

ll dt2(const point &a,const point &b,const point &c){
    ll vx1=b.x-a.x, vy1=b.y-a.y;
    ll vx2=c.x-a.x, vy2=c.y-a.y;
    return vx1*vy2-vx2*vy1;
}

bool cmp(const point &i, const point &j){
    return dt2(a[1],i,j)>0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int x,y;
    int c=0;
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        REP(k,4)
            if(myset.find(pii(x+dx[k],y+dy[k]))==myset.end()){            
                a[++c]=point(x+dx[k],y+dy[k]);
                myset.insert(pii(x+dx[k],y+dy[k]));
            }
    }
    n=c;
    FOR(i,2,n) if(a[i].y < a[1].y || (a[i].y==a[1].y && a[i].x<a[1].x)) swap(a[1],a[i]);
    
    mys[last=1]=1;
    sort(a+2,a+n+1,cmp);
    FOR(i,2,n){
        while(last>=2 && dt2(mys[last-1],mys[last],i)<=0) last--;
        mys[++last]=i;
    }
    ll res=0;
    mys[last+1]=mys[1];
    
    FOR(i,1,last){
        point &p1=a[mys[i]];
        point &p2=a[mys[i+1]];
        res+=max(abs(p1.x-p2.x),abs(p1.y-p2.y));
    }
    
     
    cout<<res<<endl;
    //getch();
    return 0;
}   

