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


class ColorfulChocolates {
public:
	int maximumSpread(string s, int maxS) {
		vector<int> a[26];
		int n=sz(s),res=0,t;
		REP(i,n) a[s[i]-'A'].pb(i);
		REP(i,26){
            REP(j,sz(a[i])){
                t=maxS;
                int left=a[i][j], right;
                FORD(x,j,0){
                    t-=left-a[i][x];
                    left--;
                    if(t<0) break;
                    int y=j;
                    right=a[i][j]+1;
                    int tt=t;
                    while(y<sz(a[i])-1 && a[i][y+1]-right<=tt){
                        y++;
                        tt-=a[i][y]-right;
                        right++;
                    }
                    //cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<y-x+1<<endl;
                    res=max(res,y-x+1);
                }
            }
        }
        return res;
	}
};

int main(){
    ColorfulChocolates a;
    cout<<a.maximumSpread("ABCDEF",4);
    system("pause");
}

//<%:testing-code%>

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
