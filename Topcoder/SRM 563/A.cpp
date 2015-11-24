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
    int n;
	int c[26];
	string s;
	
	int count(int pos){
        int cnt=0;
        int b[26];
        REP(i,26) b[i]=c[i];
        FOR(j,pos,n-1) if(b[s[j]-'a']>0){
            b[s[j]-'a']--;
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
		int p=0,len=n/2;
		string res="";
		while(len>0){
            char ch='z'+1;
            int t=0;
            FOR(i,p,n-1){
                if(count(i)<len) break;
                if(c[s[i]-'a']>0 && ch>s[i]){
                    ch=s[i];
                    t=i;
                }
            }
            c[ch-'a']--;
            res+=ch;
            p=t+1;
            len--;
        }
        return res;
    }
            
};

int main(){
    FoxAndHandle t;
    cout<<t.lexSmallestName("fedcbafedcba");
    system("pause");
}
//<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
