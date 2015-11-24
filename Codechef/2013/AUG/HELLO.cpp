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

double D,R,cost,C;
int pos,N,M,U;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    double v;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%lf%d%d",&D,&U,&N);
        cost=D*U; pos=0;
        FOR(i,1,N){
            scanf("%d%lf%lf",&M,&R,&C);
            v=R*U + C/M;
            if(v<cost){
                cost=v;
                pos=i;
            }   
        }
        printf("%d\n",pos);
    }
    //getch();
    return 0;
}
