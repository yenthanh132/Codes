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

const int maxn=57;

int s[maxn][maxn],a[maxn][maxn];
int m,n,h,w;

int count(int x1, int y1, int x2, int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

int get(int h, int w){
    int res=oo;
    FOR(i,1,m-h+1) FOR(j,1,n-w+1) res=min(res,count(i,j,i+h-1,j+w-1));
    return res;   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>m>>n;
    FOR(i,1,m) FOR(j,1,n){
        cin>>a[i][j];
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
    cin>>h>>w;
    cout<<min(get(h,w),get(w,h));
    //getch();
    return 0;
}
