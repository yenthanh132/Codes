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

const int maxn=111111;

int x[maxn],y[maxn],a,b,c;
int m,n,p;

void RotateClockwise(){
    REP(i,p){
        int xt=y[i];
        int yt=m-x[i]+1;
        x[i]=xt; y[i]=yt;   
    }   
    swap(m,n);
}

void RotateCounterClockwise(){
    REP(i,p){
        int xt=n-y[i]+1;
        int yt=x[i];
        x[i]=xt; y[i]=yt;   
    }   
    swap(m,n);
}

void RotateHorizontal(){
    int v=(b%n);
    REP(i,p){
        int yt=n-y[i]+1;
        y[i]=yt;
    }   
}

int main(){

    scanf("%d%d%d%d%d%d",&m,&n,&a,&b,&c,&p);
    REP(i,p) scanf("%d%d",&x[i],&y[i]);
    REP(i,a%4) RotateClockwise();
    if(b&1) RotateHorizontal();
    REP(i,c%4) RotateCounterClockwise();
    REP(i,p){
        printf("%d %d\n",x[i],y[i]);   
    }
    return 0;
}
