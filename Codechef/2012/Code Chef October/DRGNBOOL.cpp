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

const int maxn = 107;
int test, n, m, v[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    int c,l,res;
    REP(index,test){
        scanf("%d%d",&n,&m);
        reset(v,0);
        REP(i,n){ scanf("%d%d",&c,&l); v[l]+=c;}
        REP(i,m){ scanf("%d%d",&c,&l); v[l]-=c;}
        res=0;
        FOR(i,1,100) if(v[i]<0) res-=v[i];
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
     
