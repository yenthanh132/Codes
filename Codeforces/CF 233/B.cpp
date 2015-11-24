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

int a[2222][2222],n,m;
double f[2222][2222];

double get(int r, int c){
    if(r+c==0) return 0;
    if(a[r][c]) return f[r][c];
    a[r][c]=1;
    double &res=f[r][c];
    res=1;
    if(r>0) res+=1.0*r*(n-c)/n/n * get(r-1,c);
    if(c>0) res+=1.0*(n-r)*c/n/n * get(r,c-1);
    if(r>0 && c>0) res+=1.0*r*c/n/n * get(r-1,c-1);
    res/=(1 - 1.0*(n-r)*(n-c)/n/n);
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y;
    reset(a,0);
    REP(i,m){
        scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
    int r=0;
    FOR(i,1,n){
        bool ok=1;
        FOR(j,1,n) if(a[i][j]) ok=0;
        r+=ok;   
    }
    int c=0;
    FOR(j,1,n){
        bool ok=1;
        FOR(i,1,n) if(a[i][j]) ok=0;
        c+=ok;   
    }
    
    reset(a,0);
    printf("%0.9lf\n",get(r,c));
    
    return 0;
}
