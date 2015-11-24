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
const int maxn=57;

class TreesCount {
public:
    
    bool free1[maxn];
    int n,d[maxn],c[maxn];
    set<pii> mys;
    
	int count(vector <string> a) {
		n=sz(a);
	    REP(i,n) d[i]=oo;
	    d[0]=0;  c[0]=1;
        mys.insert(pii(0,0));
        int u,v,w;
        reset(free1,1);
        while(!mys.empty()){    
	       u=mys.begin()->se; mys.erase(mys.begin());
	       free1[u]=0;
	       REP(v,n) if(free1[v] && a[u][v]!='0'){
                w=a[u][v]-'0';
                if(d[v]>d[u]+w){
                    if(d[v]!=oo) mys.erase(mys.find(pii(d[v],v)));
                    d[v]=d[u]+w;
                    c[v]=c[u];
                    mys.insert(pii(d[v],v));
                }else if(d[v]==d[u]+w){
                    c[v]=(c[v]+c[u])%oo;
                }
            }
        }
        ll res=1;
        REP(i,n) res=(res*c[i])%oo;
        return int(res);
    }
                    
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
