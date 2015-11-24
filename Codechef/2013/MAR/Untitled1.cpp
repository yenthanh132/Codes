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

double dp[100007][1007];

#include <conio.h>
int main(){
    dp[0][0]=0;
    FOR(i,1,100000) dp[i][0]=i;
    double sum;
    FOR(j,1,100){
        sum=0;
        FOR(i,1,100000){
            dp[i][j]=sum/i;
            sum+=dp[i][j-1];
        }
    }
    FOR(i,1,100) printf("%d %0.12lf\n",i,dp[100000][i]);
    getch();
    return 0;
}
