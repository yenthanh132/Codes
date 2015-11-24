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

double area3(double x1, double y1, double x2, double y2, double x3, double y3){
    double sa=x1*y2+x2*y3+x3*y1;
    double sb=x2*y1+x3*y2+x1*y3;
    return fabs(sa-sb)/2;
}

double area4(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double sa=x1*y2+x2*y3+x3*y4+x4*y1;
    double sb=x2*y1+x3*y2+x4*y3+x1*y4;
    return fabs(sa-sb)/2;
}

double x[4],y[4],a[4],b[4],dis,v1,v2,val;

void rotate(){
    double xt=x[0],yt=y[0];
    REP(i,3){
        x[i]=x[i+1];
        y[i]=y[i+1];
    }
    x[3]=xt; y[3]=yt;   
}

void check(double a1, double a2){
    if(fabs(a1-a2)<dis){
        dis=fabs(a1-a2);
        v1=min(a1,a2);
        v2=max(a1,a2);
    }   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    REP(i,4){
        cin>>x[i]>>y[i];   
    }
    int tt=0;
    while(1){
        if(x[0]==y[0] && x[0]==y[1] && x[0]==x[1] && x[0]==0) break;
        
        dis=oo;
        double a1,a2;
        REP(step,4){
            REP(k,4){
                a[k]=(x[k]+x[(k+1)%4])/2;
                b[k]=(y[k]+y[(k+1)%4])/2;
            }
            
            a1 = area3(x[0],y[0],x[1],y[1],a[1],b[1]);
            a2 = area4(x[0],y[0],a[1],b[1],x[2],y[2],x[3],y[3]);
            check( a1, a2 );
            
            a1 = area3(x[0],y[0],x[1],y[1],x[2],y[2]);
            a2 = area3(x[0],y[0],x[2],y[2],x[3],y[3]);
            check( a1, a2 );
            
            a1 = area3(x[0],y[0],x[3],y[3],a[2],b[2]);
            a2 = area4(x[0],y[0],a[2],b[2],x[2],y[2],x[1],y[1]);
            check( a1, a2 );
            
            a1 = area3(a[0],b[0],x[1],y[1],a[1],b[1]);
            a2 = area4(x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]) - a1;
            check( a1, a2 );
            
            a1 = area4(a[0],b[0],x[1],y[1],x[2],y[2],a[2],b[2]);
            a2 = area4(a[0],b[0],x[0],y[0],x[3],y[3],a[2],b[2]);
            check( a1, a2 );
            
            a1 = area3(a[0],b[0],x[0],y[0],a[3],b[3]);
            a2 = area4(x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]) - a1;
            check( a1, a2 );
            
            rotate();   
        }
        
        printf("Cake %d: %0.3lf %0.3lf\n",++tt,v1,v2);
        
        REP(i,4){
            cin>>x[i]>>y[i];   
        }    
    }
    
    //getch();
    return 0;
}
