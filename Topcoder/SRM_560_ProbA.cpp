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


bool cmp(int a, int b){
    return a>b;
}

class TomekPhone {
public:
	int minKeystrokes(vector <int> a, vector <int> s) {
		int n=sz(a), m=sz(s);
		int sum=0,res=0;
		REP(i,m) sum+=s[i];
		if(n>sum) return -1;
		sort(a.begin(),a.end(),cmp);
		sort(s.begin(),s.end(),cmp);
		int pos, layer;
		layer=1; pos=0;
		REP(i,n){
            while(pos<m && s[pos]==0) pos++;
            if(pos==m){
                pos=0;
                layer++;
            }
            res+=a[i]*layer;
            s[pos]--; pos++;
        }
        return res;
    }
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
