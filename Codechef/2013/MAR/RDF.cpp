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

//fast input
template<typename T>
void readNumber(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


double dp[100007][32];

int main(){
    dp[0][0]=0;
    FOR(i,1,100000) dp[i][0]=i;
    double sum;
    FOR(j,1,31){
        sum=0;
        FOR(i,1,100000){
            dp[i][j]=sum/i;
            sum+=dp[i][j-1];
        }
    }
    int test,n,k;
    readNumber(test);
    REP(index,test){
        readNumber(n); readNumber(k);
        if(k<=31) printf("%0.6lf\n",dp[n][k]);
        else puts("0.000000");
    }
    return 0;
}
