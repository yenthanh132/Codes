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
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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
typedef pair<int, int> pii;

ll gcd(ll a, ll b, ll&x, ll&y){
    if(a<b) return gcd(b,a,y,x);
    else if(b==0){
        x=1; y=0; 
        return a;
    }else{
        ll x2,y2;
        ll d=gcd(b,a%b,x2,y2);
        x=y2;
        y=x2-(a/b)*y2;
        return d;
    }
}

#include <conio.h>
int main(){
    ll a,b,c,t1,t2,d,x,y;
    cin>>a>>b>>c;
    d=gcd(abs(a),abs(b),x,y);
    if(c%d!=0) cout<<-1;
    else{
        ll k=c/d,X,Y;
        t1=(a>0?-1:1); t2=(b>0?-1:1);
        X=x*t1*k; Y=y*t2*k;
        cout<<X<<' '<<Y;
    }
    //getch();
    return 0;
}
    
