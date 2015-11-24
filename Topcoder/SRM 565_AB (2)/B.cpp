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


string res;
int n,len,found;
vector<int> k;
vector<string> s;
map<vector<int>,int> mymap;

string int2str(int v){
    stringstream ss;
    ss<<v;
    return ss.str();
}

class EllysBulls {
public:
    
    
	string getNumber(vector <string> _s, vector <int> _k) {
        s=_s; k=_k;
        n=sz(s); len=sz(s[0]);
        found=0;
        
        int n1=len/2, n2=len-n1, v;
        bool ok;
        
        v=1; REP(i,n1) v*=10;
        vector<int> id;
        string st;
        mymap.clear();
        REP(num,v){
            id.clear();
            st=int2str(num);
            while(sz(st)<n1) st='0'+st;
            ok=1;
            REP(i,n){
                int tmp=0;
                REP(j,n1) if(s[i][j]==st[j]) tmp++;
                if(tmp>k[i]){
                    ok=0;
                    break;
                }
                id.pb(tmp);
            }
            if(!ok) continue;
            if(mymap.find(id)!=mymap.end()) mymap[id]=-1; else mymap[id]=num;
        }
        
        if(n2>n1) v*=10;
        REP(num,v){
            id.clear();
            st=int2str(num);
            while(sz(st)<n2) st='0'+st;
            REP(i,n){
                int tmp=0;
                REP(j,n2) if(s[i][j+n1]==st[j]) tmp++;
                id.pb(k[i]-tmp);
            }
            if(mymap.find(id)!=mymap.end()){
                if(mymap[id]==-1 || found!=0) found=2;
                else{
                    st=int2str(num);
                    res=int2str(mymap[id]);
                    while(sz(res)<n1) res='0'+res;
                    while(sz(st)<n2) st='0'+st;
                    res=res+st;
                    found=1;
                }
            }
        }
                
        if(found==0) return "Liar";
        else if(found==2) return "Ambiguity";
        else return res;
	}
};

<%:testing-code%>

#include <conio.h>
int main(){
    EllysBulls t;
    vector <string> p0;
	vector <int> p1;
	string p2;
	
	
	// ----- test 0 -----
	string t0[] = {"1234","4321","1111","2222","3333","4444","5555","6666","7777","8888","9999"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,1,0,2,0,0,0,1,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    cout<<t.getNumber(p0,p1)<<endl;
    getch();
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
