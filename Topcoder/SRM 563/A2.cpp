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


class FoxAndHandle {
public:
    string s;
    int n,c[26];
    
    int count(int pos){
        int b[26],cnt=0;
        REP(i,26) b[i]=c[i];
        FOR(i,pos,n-1) if(b[s[i]-'a']>0){
            b[s[i]-'a']--;
            cnt++;
        }
        return cnt;
    }
    
	string lexSmallestName(string S) {
		s=S;
		n=sz(s);
		reset(c,0);
		REP(i,n) c[s[i]-'a']++;
		REP(i,26) c[i]/=2;
		int p,t,len=n/2;
		string res="";
		char ch;
		p=0;
		while(len){
            ch='z'+1;
            FOR(i,p,n-1){
                if(count(i)<len) break;
	           	if(c[s[i]-'a']>0 && ch>s[i]){
                    ch=s[i];
                    t=i;
                }
            }
            c[ch-'a']--;
            len--;
            res+=ch;
            p=t+1;
        }
        return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
