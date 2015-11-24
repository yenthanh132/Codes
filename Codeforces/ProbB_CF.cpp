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
const int maxn=1001;

int m,n,a[maxn][maxn],s[maxn][maxn];

ll getS(int x1, int y1, int x2, int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

ll sqr(int x){
    return ll(x)*x;
}

void solve(){
    ll res,sum,minX,minY;
    int X,Y;
    minX=1000000000000000007ll; X=-1;
    FOR(x,0,m){
        sum=0;
        FOR(i,1,m) sum=sum+sqr(i*4-2-x*4)*getS(1,i,n,i);
        if(sum<minX){
            minX=sum;
            X=x;
        }
    }
    minY=1000000000000000007ll; Y=-1;
    FOR(y,0,n){
        sum=0;
        FOR(i,1,n) sum=sum+sqr(i*4-2-y*4)*getS(i,1,i,m);
        if(sum<minY){
            minY=sum;
            Y=y;
        }
    }
    cout<<minX+minY<<endl;
    cout<<Y<<" "<<X<<endl;
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    reset(s,0);
    FOR(i,1,n) FOR(j,1,m) s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    solve();
    //getch();
    return 0;
}
