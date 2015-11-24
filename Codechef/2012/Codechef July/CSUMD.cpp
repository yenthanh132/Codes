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

struct matrix{int arr[2][2];};

int T,n;
ll f[3]={0,1,3};

matrix operator *(matrix a, matrix &b){
    matrix c;
    REP(i,2) REP(j,2){
        c.arr[i][j]=0;
        REP(k,2) c.arr[i][j]=(c.arr[i][j]+ll(a.arr[i][k])*b.arr[k][j])%oo;
    }
    return c;
}

matrix pow(matrix &base, int n){
    if(n==1) return base;
    matrix t=pow(base,n/2);
    if(n&1) return ((t*t)*base); else return (t*t);
}    
       
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(i,T){
        scanf("%d",&n);
        if(n<=2){
            printf("%d\n",f[n]);
            continue;
        }
        matrix base,mul;
        base.arr[0][0]=0; base.arr[0][1]=1;
        base.arr[1][0]=base.arr[1][1]=2;
        mul=pow(base,n-2);
        printf("%d\n",(mul.arr[1][0]*f[1]+mul.arr[1][1]*f[2])%oo);
    }
    //getch();
    return 0;
}
