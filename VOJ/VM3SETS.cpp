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

const int maxn = 100005;
const double x[9][3]={{0,0.0001,0}, {0,-0.0001,0}, {0,-0.0001,0}, {0,0.0001,0}, {0,0.5,1}, {-1,0,1},{-1,0,1},{0,-1,0}, {0,1,0}};
const double y[9][3]={{0,0,0.0001}, {0,0,-0.0001}, {0,0,0.0001}, {0,0,-0.0001}, {0,0.85,0},{0,1,0}, {0,-1,0},{1,0,-1},{1,0,-1}};

int n;
pii a[3][maxn];
double res;

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    return abs((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2));
}

void move(int i, double &X, double &Y, double x1, double y1, double x2, double y2){
    double S=0;
    FOR(j,1,n) if(area(a[i][j].fi,a[i][j].se,x1,y1,x2,y2)>S){
        X=a[i][j].fi; Y=a[i][j].se;
        S=area(X,Y,x1,y1,x2,y2);
    }
}

//#include <conio.h>
int main(){
    double x1,y1,x2,y2,x3,y3;
    res=0;
    int permute[3];
    
    //freopen("vm3sets.in","r",stdin);
    scanf("%d",&n);
    REP(h,3) FOR(i,1,n) scanf("%d%d",&a[h][i].fi,&a[h][i].se);
    
    if(n<=200){
        FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) res=max(res,area(a[0][i].fi,a[0][i].se,a[1][j].fi,a[1][j].se,a[2][k].fi,a[2][k].se));
        printf("%0.1f\n",res/2);
        //getch();
        return 0;
    }
    
REP(t,9){
    REP(a,3) REP(b,3) if(a!=b) REP(c,3) if(a!=c && b!=c){
        REP(i,3) permute[i]=i+1;
        do{
            x1=x[t][0]; y1=y[t][0]; x2=x[t][1]; y2=y[t][1]; x3=x[t][2]; y3=y[t][2];
            REP(t,3)
                if(permute[t]==1) move(a,x1,y1,x2,y2,x3,y3);
                else if(permute[t]==2) move(b,x2,y2,x1,y1,x3,y3);
                else move(c,x3,y3,x1,y1,x2,y2);
            res=max(res,area(x1,y1,x2,y2,x3,y3));
        }while(next_permutation(permute,permute+3));
    }
}   
    printf("%0.1f\n",res/2);
    //getch();
    return 0;
}
