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

const ll dx[4]={0,1,0,-1};
const ll dy[4]={-1,0,1,0};

class RobotHerb {
public:
    
	long long getdist(int T, vector <int> a) {
        ll x,y,k,len;
        x=y=k=0;
        len=0;
        do{        
            REP(i,sz(a)){
                x+=dx[k]*a[i]; y+=dy[k]*a[i];
                k=(k+a[i]%4)%4;
            }
            len++;
        }while(len<T && k!=0);
        
        
        if(len==T) return abs(x)+abs(y);
        else{
            ll v=T/len;
            x*=v; y*=v;
            REP(tt,T-len*v){
                REP(i,sz(a)){
                    x+=dx[k]*a[i]; y+=dy[k]*a[i];
                    k=(k+a[i]%4)%4;
                }
            }
            return abs(x)+abs(y);
        }
    }
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
