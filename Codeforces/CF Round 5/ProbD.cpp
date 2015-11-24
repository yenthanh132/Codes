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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

double ptb2(double a, double b, double c){
    double delta=sqrt(b*b-4*a*c);
    return max((-b+delta)/(2*a),(-b-delta)/(2*a));
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int a,v,l,d,w;
    cin>>a>>v>>l>>d>>w;
    double t1,t2,tt,res=0;
    t1=1.0*v/a; t2=1.0*w/a; tt=sqrt((l*2.0)/a);
    if(tt<=min(t1,t2)) res=tt;
    else if(v<=w) res=t1+1.0*(l-0.5*a*t1*t1)/v;
    else{
        double dis=0.5*a*t2*t2; res=t2;
        if(dis<d){
            double t3=1.0*(v-w)/a;
            double dis3=w*t3+0.5*a*t3*t3;
            if(dis3>1.0*(d-dis)/2) t3=ptb2(0.5*a,w,1.0*(dis-d)/2);
                else t3=t3+1.0*((d-dis)/2-dis3)/v;
            res=res+t3*2; 
            dis=d;
        }
        t1=1.0*(v-w)/a;
        double dis2=dis+w*t1+0.5*a*t1*t1;
        if(dis2>=l) res=res+ptb2(0.5*a,w,dis-l);
        else res=res+t1+(l-dis2)/v;
    }
    printf("%0.12f",res);
    //getch();
    return 0;
}
        
