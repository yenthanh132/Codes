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

int maxnum(int i){
    int maxv=0;
    while(i){
        maxv=max(maxv,i%10);
        i/=10;
    }
    return maxv;
}

int convert(int v, int base){
    int d=1,res=0;
    while(v){
        res+=d*(v%10);
        d*=base;
        v/=10;   
    }   
    return res;
}

int count(int v, int base){
    if(v==0) return 1;
    int c=0;
    while(v){
        c++;
        v/=base;
    }
    return c;
}

int main(){
    int a,b;
    cin>>a>>b;
    int base=max(maxnum(a),maxnum(b));
    base++;
    if(base<2) base=2;
    a=convert(a,base); b=convert(b,base);
    cout<<count(a+b,base)<<endl;
    return 0;
}
    
