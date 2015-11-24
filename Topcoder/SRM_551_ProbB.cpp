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

const int maxn = 107;

vector<pii> a[maxn];
int d[maxn];
bool free1[maxn];
set<pii> myset;

class ColorfulWolves {
public:
	int getmin(vector <string> arr) {
		int n=sz(arr),t;
		REP(i,n){
            t=0;
            REP(j,n) if(arr[i][j]=='Y') a[i].pb(pii(j,t++));
        }
        REP(i,n) d[i]=oo;
        d[0]=0; reset(free1,1);
        myset.insert(pii(0,0));
        while(!myset.empty()){
            int u=myset.begin()->se; myset.erase(myset.begin());
            free1[u]=0;
            if(u==n-1) break;
            REP(i,sz(a[u])){
                int v=a[u][i].fi, w=a[u][i].se;
                if(free1[v] && d[v]>d[u]+w){
                    if(d[v]!=oo) myset.erase(myset.find(pii(d[v],v)));
                    d[v]=d[u]+w;
                    myset.insert(pii(d[v],v));
                }
            }
        }
        if(d[n-1]==oo) return -1; else return d[n-1];
	}
};


<%:testing-code%>

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
