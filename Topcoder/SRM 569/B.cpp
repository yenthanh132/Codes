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

const int maxn=27;


class TheJediTest {
public:
    int a[maxn],n;
    
    int solve(vector<int> s, int k){
        int v,ans=0;
        REP(i,n) if(a[i]&1){
            if(i-1>=0) s[i]+=s[i-1], s[i-1]=0;
            if(i+1<n){
                v=(s[i+1]+s[i])%k;
                if(v<s[i+1]){
                    s[i]=(s[i]+s[i+1])-v;
                    s[i+1]=v;
                }
            }
            
        }
        if(n>1 && s[n-1]>0){
            s[n-2]+=s[n-1];
            s[n-1]=0;
        }
        int sum=0;
        REP(i,n) cout<<s[i]<<' ', sum+=s[i]; cout<<endl;
        
        REP(i,n) if(s[i]>0) ans+=(s[i]-1)/k+1;
        cout<<sum<<' '<<ans<<endl;
        return ans;
    }
    
	int minimumSupervisors(vector <int> s, int K) {
		n=sz(s);
		REP(i,n) a[i]=i&1;
		int res;
		res=solve(s,K);
		REP(i,n) a[i]=1-(i&1);
		res=min(res,solve(s,K));
		return res;
	}
};

#include <conio.h>
int main(){
    int a[]={84809247, 22486586, 99664323, 85682516, 926336, 8620094, 11657708, 70562974, 99654217, 23012065, 12903209, 2074458, 44927126, 94514648, 47812845};
    vector<int> ss(a,a+15);
    TheJediTest t;
    cout<<t.minimumSupervisors(ss,45942325);
    getch();
    return 0;
}

//<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
