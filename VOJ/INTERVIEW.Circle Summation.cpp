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

const int maxn = 51;
const int base = 1000000007;

struct matrix{ll arr[maxn][maxn];};
int n,T,a[maxn],b[maxn],m;
ll res[maxn];

matrix operator +(const matrix &a, const matrix &b){
    matrix c;
    FOR(i,1,n) FOR(j,1,n) c.arr[i][j]=(a.arr[i][j]+b.arr[i][j])%base;
    return c;
}

matrix operator *(const matrix &a, const matrix &b){
    matrix c;
    FOR(i,1,n) FOR(j,1,n){
        c.arr[i][j]=0;
        FOR(k,1,n) c.arr[i][j]=(c.arr[i][j]+ll(a.arr[i][k])*b.arr[k][j])%base;
    }
    return c;
}

matrix mat_pow(const matrix &a, int n){
    if(n==1) return a;
    matrix mul=mat_pow(a,n/2);
    if(n&1) return (mul*mul)*a; else return mul*mul;
}
    

int round1(int v){
    if(v<1) return v+n;
    else if(v>n) return v-n;
    return v;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    int pos;
    REP(index,T){
        scanf("%d%d",&n,&m);
        FOR(i,1,n) scanf("%d",a+i);
        
        matrix matbase; reset(matbase.arr,0);
        FOR(i,1,n-1) matbase.arr[i][i+1]=1;
        matbase.arr[n][1]=matbase.arr[n][2]=matbase.arr[n][n]=1;
        matrix mul=mat_pow(matbase,m);
        
        pos=n-((m-1)%n+1)+1;
        FOR(i,1,n){
            FOR(j,1,n) if(i+j-1>n) b[j]=a[i+j-1-n]; else b[j]=a[i+j-1];
            FOR(j,1,n){
                res[j]=0;
                FOR(k,1,n) res[j]=(res[j]+ll(mul.arr[j][k])*b[k])%base;
            }
            FOR(j,1,n) printf("%d ",res[round1(j+pos-i)]);
            printf("\n");
        }
        if(index<T-1) printf("\n");
    }
    //getch();
    return 0;
}
