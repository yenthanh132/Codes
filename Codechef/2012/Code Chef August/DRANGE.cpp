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

const int maxn = 1000007;

int d[maxn],minv,maxv,v;
int n,m,s,t;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&t);
    int w,x,y,z;
    REP(index,t){
        scanf("%d%d",&n,&m);
        REP(i,n) d[i]=1; 
        REP(i,m){
            scanf("%d%d%d%d",&w,&x,&y,&z);
            if(w==1) d[x-1]+=z, d[y]-=z; else d[x-1]-=z, d[y]+=z;
        }
        minv=maxv=v=d[0]; 
        FOR(i,2,n){
            v=v+d[i-1];
            minv=min(minv,v); maxv=max(maxv,v);
        }
        printf("%d\n",maxv-minv);
    }
    //getch();
    return 0;
}
