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


int gcd(int a, int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


const int maxn=100;
const int maxv=10007;
int n,a[maxn];
ll dp[maxv];


//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test;
    read(test);
    REP(tt,test){
        read(n);
        FOR(j,1,n) read(a[j]);
        reset(dp,0);
        FOR(i,1,n){
            FOR(v,1,10000) if(dp[v]) dp[gcd(v,a[i])]+=dp[v];
            dp[a[i]]++;
        }
        printf("%lld\n",dp[1]);
    }
    
    //getch();
    return 0;
}
            
            
