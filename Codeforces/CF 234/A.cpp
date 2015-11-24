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

int main(){
    int t;
    cin>>t;
    REP(tt,t){
        string s;
        cin>>s; 
        s="@"+s;
        vector<pii> res;
        FOR(a,1,12) if(12%a==0){
            int b=12/a;
            bool is=0;
            FOR(i,1,b){
                bool ok=1;
                for(int j=i; j<=12; j+=b) if(s[j]!='X') ok=0;
                if(ok) is=1;
            }  
            if(is) res.pb(pii(a,b));
        }
        
        cout<<sz(res);
        REP(i,sz(res)) cout<<' '<<res[i].fi<<'x'<<res[i].se; cout<<endl;
    }   
    
    return 0;
}
