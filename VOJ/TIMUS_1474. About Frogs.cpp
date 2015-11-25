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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

//#include <conio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n*n+2*n);
    bool left=true;
    int x=n;
    FOR(i,1,n){
        FOR(j,1,i-1) printf("%d ",x + 2*j*(left?-1:1));
        printf("%d ",x + 2*(i-1)*(left?-1:1) + (left?-1:1));
        x=x+2*(i-1)*(left?-1:1) + (left?-1:1);
        left=!left;
    }
    
    FOR(j,1,n) printf("%d ",x+2*j*(left?-1:1));
    x=x+2*n*(left?-1:1);
    left=!left;
    
    FORD(i,n,1){
        printf("%d ",x + (left?-1:1));
        FOR(j,1,i-1) printf("%d ",x + (left?-1:1) + 2*j*(left?-1:1));
        x=x+2*(i-1)*(left?-1:1) + (left?-1:1);
        left=!left;
    }
    //getch();
    return 0;
}
