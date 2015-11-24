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

const double PI=atan(1)*4;
const double lim=1e-9;

bool equal(double a, double b){
    return (fabs(a-b)<=lim);
}

struct seg{
    double x1,y1,x2,y2,vx,vy;
    void init(){vx=x2-x1; vy=y2-y1;}
    void doswap(){swap(x1,x2); swap(y1,y2);}
    double len(){return sqrt(vx*vx+vy*vy);}
    bool belong(double x, double y){
        return(equal(0,vy*(x-x1)-vx*(y-y1)) && (equal(x,x1) || equal(x,x2) || (min(x1,x2)<=x && x<=max(x1,x2))));
    }
}a[3];

bool compoint(seg a, seg b){
    return((a.x1==b.x1 && a.y1==b.y1) || (a.x1==b.x2 && a.y1==b.y2) || (a.x2==b.x1 && a.y2==b.y1) || (a.x2==b.x2 && a.y2==b.y2));
}

double angle(seg &a, seg &b){
    int i=1;
    while(!(a.x1==b.x1 && a.y1==b.y1)){
        if(i&1) a.doswap(); else b.doswap();
        i++;
    }
    a.init(); b.init();
    return((a.vx*b.vx+a.vy*b.vy)/(a.len()*b.len()));
}

bool catnhau(seg a, seg b){
    double x,y;
    if(b.belong(a.x1,a.y1)) x=a.x1, y=a.y1;
    else if(b.belong(a.x2,a.y2)) x=a.x2, y=a.y2;
    else return 0;
    double r=sqrt((x-b.x1)*(x-b.x1)+(y-b.y1)*(y-b.y1))/b.len();
    if(!equal(r,0.2) && !equal(r,0.8) &&(r<0.2 || r>0.8)) return 0;
    return 1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int t;
    cin>>t;
    REP(i,t){
        REP(j,3) cin>>a[j].x1>>a[j].y1>>a[j].x2>>a[j].y2, a[j].init();
        int u=-1,v,z;
        REP(j,3){
            REP(k,3) if(j!=k && compoint(a[j],a[k])){
                u=j; v=k;
            }
            if(u!=-1) break;
        }
        if(u==-1){cout<<"NO\n"; continue;}
        if(equal(a[0].len(),0) || equal(a[1].len(),0) || equal(a[2].len(),0)){ cout<<"NO\n"; continue; }
        double r=angle(a[u],a[v]);
        if((a[u].x2==a[v].x2 && a[u].y2==a[v].y2) || (!equal(r,0) && r<0)){cout<<"NO\n"; continue;}
        
        z=(3-u-v);
        if(catnhau(a[z],a[u]) && catnhau(a[z],a[v]))
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    //getch();
    return 0;
}
        
        
