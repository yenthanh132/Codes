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
#define oo 1000000009

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=307;

string s;
    int n,a,b,sum[maxn],len;
    ll dp[maxn][maxn][maxn];

class TheExperiment {
public:
    
    
    int getsum(int l, int r, int f){
        int s=f-len+1;
        if(s<l) s=l; if(f>r) f=r;
        return sum[f]-sum[s-1];
    }
    
    ll count(int i, int l, int r){
        if(i==0) return 1;
        if(dp[i][l][r]!=-1) return dp[i][l][r];
        if(l>r) return 0;
        ll d=0;
        
        if(i==1){
            FOR(t,len,n) if(getsum(l,r,t)>=a && getsum(l,r,t)<=b) d++;
            dp[i][l][r]=d;
            return d;
        }
        
        
        FOR(t,max(len,l),min(r+len-1,n)){
            int val=getsum(l,r,t);
            if(val<a || val>b) continue;
            FOR(j,0,i-1) d=(d + count(j,l,t-len)*count(i-j-1,t+1,r))%oo;
        }
        dp[i][l][r]=d;
        return d;
    }
    
	int countPlacements(vector <string> intensity, int M, int L, int A, int B) {
        s="";
        
	    REP(i,sz(intensity)) s+=intensity[i];
	    n=sz(s);
	    s=' '+s;
	    a=A; b=B;
	    len=L;
	    sum[0]=0;
	    FOR(i,1,n) sum[i]=sum[i-1]+s[i]-'0';
	    
	    FOR(k,0,M) FOR(i,1,n) FOR(j,1,n) dp[k][i][j]=-1;
	    return count(M,1,n);
	    
	}
};


<%:testing-code%>
int main(){
    TheExperiment t;
    vector<string> s;
    s.pb("341156");
    cout<<t.countPlacements(s,3,3,6,10)<<endl;
system("pause");
}
//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
