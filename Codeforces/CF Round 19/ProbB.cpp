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

const double lim=1e-9;
ll a,b,c,delta;

double round(double v){
    if(fabs(v)<=lim) return 0; else return v;
}

#include <conio.h>
int main(){
    cin>>a>>b>>c;
    
    if(a==0){
        if(b==0){
            if(c==0) printf("-1\n");
            else printf("0\n");
        }else{
            printf("1\n%0.12lf\n",round(-1.0*c/b));
        }
        //getch();
        return 0;
    }        
    
    delta=b*b-4*a*c;
    if(delta==0){
        printf("1\n");
        printf("%0.12lf\n",round(-1.0*b/(2*a)));
    }else if(delta<0) printf("0\n");
    else{
        printf("2\n");
        printf("%0.12lf\n",round(min((-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a))));
        printf("%0.12lf\n",round(max((-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a))));
    }
    //getch();
    return 0;
}
        
