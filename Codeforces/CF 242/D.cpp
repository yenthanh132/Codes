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

const int maxn=307;

int a[maxn][maxn],m,n,t,tp,tu,td;
int s1[maxn][maxn],s2[maxn][maxn],s3[maxn][maxn],s4[maxn][maxn];

int val(int a, int b){
    if(a==b) return tp;
    if(a<b) return tu;
    return td;   
}

int myabs(int v){
    return (v>0?v:-v);
}

int res,xr1,yr1,xr2,yr2;

void update(int v, int x1, int y1, int x2, int y2){
    if(myabs(v-t)<myabs(res-t)){
        res=v;
        xr1=x1; yr1=y1;   
        xr2=x2; yr2=y2;
    }   
}

int cal(int i1, int j1, int i2, int j2){
    return (s1[i2][j1]-s1[i1][j1]) + (s3[i1][j2]-s3[i1][j1]) 
         + (s2[i2][j2]-s2[i1][j2]) + (s4[i2][j2]-s4[i2][j1]);
}

int main(){
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    
    scanf("%d%d%d%d%d%d",&m,&n,&t,&tp,&tu,&td);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    
    FOR(j,1,n) s1[1][j]=s2[1][j]=0;
    FOR(i,2,m) FOR(j,1,n) s1[i][j]=s1[i-1][j]+val(a[i][j],a[i-1][j]), s2[i][j]=s2[i-1][j]+val(a[i-1][j],a[i][j]);
    FOR(i,1,m) s3[i][1]=s4[i][1]=0;
    FOR(j,2,n) FOR(i,1,m) s3[i][j]=s3[i][j-1]+val(a[i][j-1],a[i][j]), s4[i][j]=s4[i][j-1]+val(a[i][j],a[i][j-1]);
    
    res=-oo;
    FOR(i1,1,m-2) FOR(i2,i1+2,m){
        int j1=1;
        FOR(j2,3,n){
            int v=cal(i1,j1,i2,j2);
            while(j1+2<j2 && v>t) ++j1;                           
            FOR(j3,max(1,j1-100),min(j1+100,j2-2)) update(cal(i1,j3,i2,j2),i1,j3,i2,j2);

        }
    }    
    printf("%d %d %d %d\n",xr1,yr1,xr2,yr2);
    
   
    return 0;   
}
