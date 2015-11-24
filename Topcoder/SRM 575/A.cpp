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
const int maxn=107;

class ArcadeManao {
public:
    int m,n,x,y;
    vector<string> s;
    
    bool free1[maxn][maxn];
    queue<pii> myq;
    
    bool check(int l){
        while(!myq.empty()) myq.pop();
        myq.push(pii(0,0));
        reset(free1,1);
        free1[0][0]=0;
        int i,j;
        while(!myq.empty()){
            i=myq.front().fi; j=myq.front().se; myq.pop();
            if(j>0 && s[i][j-1]=='X' && free1[i][j-1]){
                free1[i][j-1]=0;
                myq.push(pii(i,j-1));
            }
            if(j<n-1 && s[i][j+1]=='X' && free1[i][j+1]){
                free1[i][j+1]=0;
                myq.push(pii(i,j+1));
            }
            REP(it,m) if(abs(it-i)<=l && free1[it][j] && s[it][j]=='X'){
                free1[it][j]=0;
                myq.push(pii(it,j));
            }
        }
        return !free1[x][y];
    }
    
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		m=sz(level);
		n=sz(level[0]);
		s.resize(m);
		REP(i,m) s[m-i-1]=level[i];
		
		x=coinRow-1; y=coinColumn-1;
		x=m-x-1;
		int l=0, r=oo, mid,res=oo;
		while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        
        return res;
	}
};


<%:testing-code%>


int main(){
    string t0[] = {"XXXX....","...X.XXX","XXX..X..","......X.","XXXXXXXX"};
    vector<string> s(t0,t0+5);
    ArcadeManao t;
    cout<<t.shortestLadder(s,2,4);
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
