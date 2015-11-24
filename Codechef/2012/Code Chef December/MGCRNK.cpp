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

const int maxn=107;

int n,s[maxn][maxn],test;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        s[0][1]=s[1][0]=0;
        FOR(i,1,n) FOR(j,1,n){
            scanf("%d",&s[i][j]);
            if(i==1) s[i][j]+=s[i][j-1];
            else if(j==1) s[i][j]+=s[i-1][j];
            else s[i][j]+=max(s[i-1][j],s[i][j-1]);
        }
        if(s[n][n]>=0) printf("%0.9lf\n",1.0*s[n][n]/(2*n-3)); else puts("Bad Judges");
    }
    //getch();
    return 0;
}
