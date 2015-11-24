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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll, string> pis;

class Lottery {
public:
	vector <string> sortByOdds(vector <string>);
};

vector <string> Lottery::sortByOdds(vector <string> rules) {
	vector<pis> ds;
	vector<string> ans;
	ll f[9][101];
	REP(i,sz(rules)){
        int choices, blank;
        char sorted, unique;
        string s=rules[i];
        int p=s.find(":");
        string name=s.substr(0,p);
        s.erase(0,p+2); p=s.find(" ");
        choices=atoi(s.substr(0,p).c_str());
        s.erase(0,p+1); p=s.find(" ");
        blank=atoi(s.substr(0,p).c_str());
        s.erase(0,p+1);
        sorted=s[0]; unique=s[2];
        ll t=1;
        reset(f,0);
        if(sorted=='F'){
            if(unique=='F') FOR(j,1,blank) t*=choices;
            else{
                for(int j=1;j<=blank;j++,choices--) t*=choices;
            }
        }else{
            if(unique=='F'){
                FOR(j,1,choices) f[1][j]=1;
                FOR(i,2,blank) FOR(j,1,choices) FOR(k,1,j) f[i][j]+=f[i-1][k];
                t=0; FOR(j,1,choices) t+=f[blank][j];
            }else{
                for(int j=1;j<=blank;j++,choices--) t*=choices;
                FOR(j,2,blank) t/=j;
            }
        }
        ds.pb(pis(t,name));
    }
    sort(all(ds));
    REP(i,sz(ds)) ans[i]=ds[i].se;
    return ans;
}

int main(){
    Lottery a;
    vector<string> s(1,"PICK ANY TWO: 10 2 F F");
    a.sortByOdds(s);
    return 0;
}
