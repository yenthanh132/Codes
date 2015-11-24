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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll res,t,T,x,cost,minv;
int n,m;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    res=0;
    REP(index,n){
        scanf("%I64d%I64d%I64d%I64d",&t,&T,&x,&cost);
        if(t>=T) res+=x*m+cost;
        else{
            ll a=T-t;
            ll k;
            k=(m-1)/a+1;
            minv=k*cost;
            minv=min(minv,cost+m*x);
            res+=minv;
        }
    }
    printf("%I64d\n",res);
    //getch();
    return 0;
}
    
