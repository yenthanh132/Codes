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

const int maxn=44;
const int maxv=250000;

int dp[maxn],res[maxn];
bool isprime[maxv+1];

int main(){
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;

    dp[0]=1;
    FOR(i,1,40){
        dp[i]=dp[i-1];
        if(i>=4) dp[i]+=dp[i-4];
    }
    int p=0;
    res[0]=0;
    FOR(i,1,40){
        res[i]=res[i-1];
        while(p<=dp[i]){
            if(isprime[p]) ++res[i];
            ++p;
        }
    }

    int T,n;
    cin>>T;
    REP(tt,T){
        cin>>n;
        cout<<res[n]<<endl;
    }

    return 0;
}
