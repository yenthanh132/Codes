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

const int maxn=47;

int a[maxn][maxn][maxn];
char sa[maxn*maxn*maxn],sb[maxn*maxn*maxn];
int T,n,p,r1,r2;

int sum(int x, int y, int z, int n){
    int x0=x-n, y0=y-n, z0=z-n;
    return a[x][y][z] - a[x0][y][z] - a[x][y0][z] - a[x][y][z0] + a[x0][y0][z] + a[x0][y][z0] + a[x][y0][z0] - a[x0][y0][z0];   
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int val;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&p);        
        scanf("%s%s",sa,sb);
        int pos=0;
        bool found=0;
        FOR(i,1,n) FOR(j,1,n) FOR(k,1,n){
            a[i][j][k]=a[i-1][j][k]+a[i][j-1][k]+a[i][j][k-1] - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1] + a[i-1][j-1][k-1];   
            if(sa[pos]==sb[pos]) ++a[i][j][k], found=1;
            ++pos;
        }
        r1=0;
        if(!found && p>0) goto out;
        FORD(s,n,1)
            FOR(i,s,n) FOR(j,s,n) FOR(k,s,n){
                val=sum(i,j,k,s);
                if(val * 100 >= s*s*s*p){
                    r1=s;
                    goto out;   
                }
            }   
        
    out:
        if(r1==0) puts("-1");
        else{
            r2=0;
            FOR(i,r1,n) FOR(j,r1,n) FOR(k,r1,n){
                val=sum(i,j,k,r1);
                if(val * 100 >= r1*r1*r1*p) ++r2;
            }   
            printf("%d %d\n",r1,r2);
        }
    }
}   
