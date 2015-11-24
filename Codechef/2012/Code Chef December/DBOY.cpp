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

const int maxn=507;

int f[maxn*2],h[maxn],k[maxn],n,test,maxh,res;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        maxh=res=0;
        FOR(i,1,n) scanf("%d",&h[i]), maxh=max(maxh,h[i]);
        FOR(i,1,n) scanf("%d",&k[i]);
        maxh*=2;
        
        FOR(i,1,maxh) f[i]=oo;
        f[0]=0;
        
        FOR(i,1,n) FOR(j,k[i],maxh) f[j]=min(f[j],f[j-k[i]]+1);
        
        FOR(i,1,n) res+=f[h[i]*2];
        
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
