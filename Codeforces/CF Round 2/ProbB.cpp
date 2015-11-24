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

int n,res,arr[1001][1001];
string path;
bool found0;
pii a[1001][1001],f[1001][1001];
char trace[1001][1001];

pii phantich(int v){
    if(v==0) return pii(oo,oo);
    int c2=0, c5=0;
    while(v>0 && v%2==0) c2++, v/=2;
    while(v>0 && v%5==0) c5++, v/=5;
    return pii(c2,c5);
}

void update(int v){
    if(res>v){
        res=v;
        path="";
        int i=n, j=n;
        while(i!=1 || j!=1){
            path=trace[i][j]+path;
            if(trace[i][j]=='D') i--; else j--;
        }
    }
}

void optimize0(){
    FOR(i,1,n) FOR(j,1,n)
        if(i==1 && j==1) f[i][j].fi=(arr[i][j]==0?1:0);
        else{
            f[i][j].fi=(arr[i][j]==0?1:0);
            if(i>1) trace[i][j]='D'; else trace[i][j]='R';
            if(i>1 && f[i-1][j].fi>0) f[i][j].fi=1, trace[i][j]='D';
            if(j>1 && f[i][j-1].fi>0) f[i][j].fi=1, trace[i][j]='R';
        }
    update(1);
}

void optimize(){
    FOR(i,1,n) FOR(j,1,n) 
        if(i==1 && j==1) f[i][j]=a[i][j];
        else{
            f[i][j]=pii(oo,oo);
            if(i>1 && (f[i-1][j].fi<f[i][j].fi || (f[i-1][j].fi==f[i][j].fi && f[i-1][j].se<f[i][j].se))) f[i][j]=f[i-1][j],trace[i][j]='D';
            if(j>1 && (f[i][j-1].fi<f[i][j].fi || (f[i][j-1].fi==f[i][j].fi && f[i][j-1].se<f[i][j].se))) f[i][j]=f[i][j-1],trace[i][j]='R';
            f[i][j].fi+=a[i][j].fi;
            f[i][j].se+=a[i][j].se;
        }
    update(min(f[n][n].fi,f[n][n].se));
    FOR(i,1,n) FOR(j,1,n) 
        if(i==1 && j==1) f[i][j]=a[i][j];
        else{
            f[i][j]=pii(oo,oo);
            if(i>1 && (f[i-1][j].se<f[i][j].se || (f[i-1][j].se==f[i][j].se && f[i-1][j].fi<f[i][j].fi))) f[i][j]=f[i-1][j],trace[i][j]='D';
            if(j>1 && (f[i][j-1].se<f[i][j].se || (f[i][j-1].se==f[i][j].se && f[i][j-1].fi<f[i][j].fi))) f[i][j]=f[i][j-1],trace[i][j]='R';
            f[i][j].fi+=a[i][j].fi;
            f[i][j].se+=a[i][j].se;
        }
    update(min(f[n][n].fi,f[n][n].se));
}

void output(){
    printf("%d\n",res);
    cout<<path;
}

//#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int v;
    found0=0;
    FOR(i,1,n) FOR(j,1,n){
        scanf("%d",&v);
        if(v==0) found0=1;
        arr[i][j]=v;
        a[i][j]=phantich(v);
    }
    res=oo;
    if (found0) optimize0();
    optimize();
    output();
    //getch();
    return 0;
}
