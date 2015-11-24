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

const int maxv=1000000;
const int maxn=1000007;

int d[maxn],arr[maxn];

class RightTriangle {
public:
    ll places,n,a,b,c;
	long long triangleCount(int _places, int _points, int _a, int _b, int _c) {
		if(_places&1) return 0;
	    places=_places; n=_points; a=_a; b=_b; c=_c;
	    
	    REP(i,n){
            ll p=(a*i*i+b*i+c)%places;
            d[p]++;
        }
        int sum=0;
        REP(i,places){
            sum+=d[i];
            d[i]=0;
            if(sum){
                arr[i]=1;
                sum--;
            }
        }
        REP(i,places){
            if(!sum) break;
            if(arr[i]==0){
                arr[i]=1;
                sum--;
            }
        }
        
        int i=0, j=places/2;
        ll res=0;
        while(i<places/2){
            if(arr[i] && arr[j]) res+=n-2;
            i++; j=(j+1)%places;
        }
        
        return res;
        
	}
};


<%:testing-code%>

#include <conio.h>
int main(){
    RightTriangle t;
    cout<<t.triangleCount(68579, 6175, 981761, 976111, 140183);
    getch();
    return 0;
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
