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

const int maxn=100;
int a[maxn][maxn];

#include <conio.h>
int main(){
    int n=60;
    a[1][n]=1;
    FOR(i,2,n) FOR(j,1,n) if(j==1) a[i][j]=a[i-1][j+1];
    else if(j==n) a[i][j]=a[i-1][j-1];
    else a[i][j]=a[i-1][j-1]^a[i-1][j+1];
    FOR(i,1,n){
        int c=0;
        FOR(j,1,n){if(a[i][j]) cout<<'1'; else cout<<' '; c+=a[i][j];};
        cout<<" - "<<c<<endl;
    }
    getch();
    return 0;
}
