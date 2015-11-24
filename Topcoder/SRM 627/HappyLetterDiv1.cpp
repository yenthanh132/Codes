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

struct HappyLetterDiv1 {

    int c[26],a[26];
	string getHappyLetters(string letters) {
        reset(c,0);
        REP(i,sz(letters)) c[letters[i]-'a']++;
        string res="";
        REP(v,26) if(c[v]){
            REP(i,26) a[i]=c[i];
            a[v]--;
            bool ok=1;
            int maxv=a[0],sum=0, u=0;
            REP(i,26){
                if(a[i]>maxv){
                    maxv=a[i];
                    u=i;
                }
                sum+=a[i];
            }
            if((sum-maxv)*2<sum && u!=v) ok=0;
            if(sum&1 && a[v]==0) ok=0;
            if(ok) res+=char('a'+v);
        }
        return res;
	}
};
