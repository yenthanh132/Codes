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


class ICPCBalloons {
public:
	int minRepaintings(vector <int> c, string s, vector <int> a) {
	    int m=sz(c);
        int n=sz(a);
        int sm=0, sl=0;
        vector<int> lm,ll,a0,a1;
        REP(i,m) if(s[i]=='M') lm.pb(c[i]), sm+=c[i]; 
        else ll.pb(c[i]), sl+=c[i];
        sort(ll.rbegin(),ll.rend());
        sort(lm.rbegin(),lm.rend());
        int tm,tl,res=oo,ans;
        REP(i,1<<n){
            tm=tl=0;
            a0.clear(); a1.clear();
            REP(j,n) if((i>>j)&1) a1.pb(a[j]), tl+=a[j];
            else a0.pb(a[j]), tm+=a[j];
            sort(a0.rbegin(),a0.rend());
            sort(a1.rbegin(),a1.rend());
            if(tm>sm || tl>sl) continue;
            ans=0;
            int v;
                REP(j,sz(a0)){
                    if(j<sz(lm)) v=lm[j]; else v=0;
                    ans+=max(a0[j]-v,0);
                }
                REP(j,sz(a1)){
                    if(j<sz(ll)) v=ll[j]; else v=0;
                    ans+=max(a1[j]-v,0);
                }
            cout<<i<<endl;
            REP(j,sz(a0)) cout<<a0[j]<<' '; cout<<endl;
            REP(j,sz(a1)) cout<<a1[j]<<' '; cout<<endl;
            res=min(res,ans);
        }
        if(res==oo) return -1; else return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
