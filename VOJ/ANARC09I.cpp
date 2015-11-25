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

const int maxn=103;

double a[maxn][maxn],r[maxn], arr[11][11];
int w,h,d,n;

int toid(int x, int y){
    return (x-1)*w+y;
}

void gauss(){
    double t;
    FOR(i,1,n-1){
        if(fabs(a[i][i])<1e-7){
            FOR(j,i+1,n) if(fabs(a[j][i])>1e-7){
                FOR(k,1,n+1) swap(a[i][k],a[j][k]);
                break;
            }
        }
        FOR(j,i+1,n) if(fabs(a[j][i])>1e-7){
            t=a[j][i]/a[i][i];
            FOR(k,1,n+1) a[j][k]-=a[i][k]*t;
        }
    }
    
    FORD(i,n,1){
        t=0;
        FOR(j,i+1,n) t+=r[j]*a[i][j];
        r[i]=(a[i][n+1]-t)/a[i][i];
    }
}

//#include <conio.h>
int main(){
    bool first=1;
    while(scanf("%d%d%d",&w,&h,&d),w){
        if(!first) puts(""); first=0;
        FOR(i,1,h) FOR(j,1,w) scanf("%lf",&arr[i][j]);
        n=h*w;
        FOR(i,1,n) FOR(j,1,n+1) a[i][j]=0;
        int num=0,c;
        
        FOR(i,1,h) FOR(j,1,w){
            num++;
            c=0;
            FOR(x,1,h) FOR(y,1,w) if(abs(x-i)+abs(y-j)<=d){
                c++;
                a[num][toid(x,y)]=1;
            }
            a[num][n+1]=c*arr[i][j];
        }
        
        gauss();
        num=0;
        FOR(i,1,h){
            FOR(j,1,w) printf("%8.2lf",r[++num]);
            puts("");
        }
    }
    //getch();
    return 0;
}
        
