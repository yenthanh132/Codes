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

const int maxv=33000;
const int maxm=5000;
const int maxn=1000007;
int m,p[maxm],val[maxn],a[maxn],n;
map<int,int> c;
bool isprime[maxv+7];

class TheDivisionGame {
public:
	long countWinningIntervals(int L, int R) {
        isprime[2]=1;
		for(int i=3; i<=maxv; i+=2) isprime[i]=1;
		for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
		    for(int j=i*i; j<=maxv; j+=i*2) isprime[j]=0;
		p[m=1]=2;
		for(int i=3; i<=maxv; i+=2) if(isprime[i]) p[++m]=i;
		
		n=R-L+1;
		FOR(i,1,n) a[i]=L+i-1;
		
		FOR(i,1,m){
            int pos=(L/p[i])*p[i];
            while(pos<L) pos+=p[i];
            while(pos<=R){
                while(a[pos-L+1]%p[i]==0){
                    val[pos-L+1]++;
                    a[pos-L+1]/=p[i];
                }
                pos+=p[i];
            }
        }    
        FOR(i,1,n) if(a[i]>1) val[i]++;
        c.clear(); c[0]=1;
        int v=0;
        ll res=0;
        FOR(i,1,n){
            v^=val[i];
            res+=c[v];
            c[v]++;
        }
        return (1ll*n*(n+1)/2) - res;
	}
};


<%:testing-code%>
